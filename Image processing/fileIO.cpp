//This file contains function that open, read and and write image data. 
#include "imageHeader.h"

// Open the file in binary mode and read in file data.
void openInImage(cmdLineInfo &cmdLineData, imageInfo &imageData)
{
    std::ifstream inImage;
    std::string imagePixel;
    std::string comment;
    char peekValue;
    
    inImage.open(cmdLineData.inImageName, std::ios::in | std::ios::binary);
    
    if (!inImage.is_open())
    {
        std::cout << "Image file could not be opened.\n";
        exit(0);
    }
    
    //Read image header.
    else
    {
        inImage >> imageData.magicNumber;
        inImage.ignore();
        peekValue = inImage.peek();
        
        //Read in comments
        while (peekValue == 35)
        {
            getline(inImage, comment);
            imageData.comments.push_back(comment);
            peekValue = inImage.peek();
        }
        
        //Read in column, row, and max pixel value.
        inImage >> imageData.cols >> imageData.rows >> imageData.maxPixel;
        inImage.ignore();
        
        //Read in image data.
        if (imageData.magicNumber == "P3")
            //read ASCII
            readASCII(imageData, inImage);
        
        else if (imageData.magicNumber == "P6")
            //read Binary
            readBinary(imageData, inImage);
    
    }
    
    inImage.close();
    
    return;
}

//Open the output image and write the data to the file.
void openOutImage(cmdLineInfo &cmdLineData, imageInfo imageData)
{
    //Declare variables here
    std::ofstream outImage;
    
    //Add extension to the output image.
    if (cmdLineData.optionCode == "-g" || cmdLineData.optionCode == "-c")
        cmdLineData.outImageName += ".pgm";
    
    else
        cmdLineData.outImageName += ".ppm";
    
    //Open the output image file.
    outImage.open(cmdLineData.outImageName, std::ios::out | std::ios::binary );
    
    //Check if the file opened.
    if (!outImage.is_open())
    {
        std::cout << "Could not open file\n";
        exit(0);
    }
    
    else
    {
        //Check data type.
        if (cmdLineData.dataType == "-oa")
        {
            //Write ascii
            writeASCII(imageData, outImage);
            std::cout << "ASCII data written.\n";
        }
        
        else if (cmdLineData.dataType == "-ob")
        {
            //Write binary
            writeBinary(imageData, outImage);
            std::cout << "Binary data written.\n";
        }
    }
    
    outImage.close();
    return;
    
}

void readASCII(imageInfo &imageData, std::ifstream &inImage)
{
    //Declare variables here.
    unsigned int data;
    
    //Allocate mormory to read data into
    allocate2D(imageData.redgray, imageData.rows, imageData.cols);
    allocate2D(imageData.green, imageData.rows, imageData.cols);
    allocate2D(imageData.blue, imageData.rows, imageData.cols);
    
    //Read in data to allocated memory.
    for (int i = 0; i < imageData.rows; i++)
    {
        for (int j = 0; j < imageData.cols; j++)
        {
            inImage >> data;
            imageData.redgray[i][j] = unsigned (char (data));

            inImage >> data;
            imageData.green[i][j] = unsigned (char (data));

            inImage >> data;
            imageData.blue[i][j] = unsigned (char (data));
        }
    }

    return;
}

//Write the file in ASCII format
void writeASCII(imageInfo imageData, std::ofstream &outImage)
{
    //Write the image header to the output image.
    outImage << "P3\n";
    
    //Write the comments.
    for (int i = 0; i < imageData.comments.size(); i++)
        outImage << imageData.comments[i] << "\n";
    
    outImage << imageData.cols << " " << imageData.rows << "\n";
    outImage << imageData.maxPixel << "\n";
    
    for (int i = 0; i < imageData.rows; i++)
    {
        for (int j = 0; j < imageData.cols; j++)
        {
            outImage << unsigned (int (imageData.redgray[i][j])) << std::endl;
            outImage << unsigned (int (imageData.green[i][j])) << std::endl;
            outImage << unsigned (int (imageData.blue[i][j])) << std::endl;
        }
            
    }
    
    return;
}

void readBinary(imageInfo &imageData, std::ifstream &inImage)
{
    //Declare variables here.
    
    //Allocate mormory to read data into
    allocate2D(imageData.redgray, imageData.rows, imageData.cols);
    allocate2D(imageData.green, imageData.rows, imageData.cols);
    allocate2D(imageData.blue, imageData.rows, imageData.cols);
    
    //Read in the data.
    for (int i = 0; i < imageData.rows; i++)
    {
        for (int j = 0; j < imageData.cols; j++)
        {
            inImage.read( (char *) &imageData.redgray[i][j], sizeof(pixel));
            inImage.read( (char *) &imageData.green[i][j], sizeof (pixel));
            inImage.read( (char *) &imageData.blue[i][j], sizeof (pixel));
        }
    }
    
    return;
}

void writeBinary(imageInfo imageData, std::ofstream &outImage)
{
    //Write the image header to the output image.
    outImage << "P6\n";
    
    //Write the comments.
    for (int i = 0; i < imageData.comments.size(); i++)
        outImage << imageData.comments[i] << "\n";
    
    outImage << imageData.cols << " " << imageData.rows << "\n";
    outImage << imageData.maxPixel << "\n";
    
    for (int i = 0; i < imageData.rows; i++)
    {
        for (int j = 0; j < imageData.cols; j++)
        {
            outImage.write( (char *) &imageData.redgray[i][j], sizeof(pixel));
            outImage.write( (char *) &imageData.green[i][j], sizeof(pixel));
            outImage.write( (char *) &imageData.blue[i][j], sizeof(pixel));
        }
    }
    
    return;
}




