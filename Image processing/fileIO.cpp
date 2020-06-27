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
    std::cout << cmdLineData.inImageName << "\n";
    
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
            imageData.comments += comment;
            peekValue = inImage.peek();
        }
        
        //Read in column, row, and max pixel value.
        inImage >> imageData.cols >> imageData.rows >> imageData.maxPixel;
        inImage.ignore();
        
        //Read in image data.
        if (imageData.magicNumber == "P3")
            //read binary
            readASCII(imageData, inImage);
        
        else if (imageData.magicNumber == "P6")
            std::cout << "here";
    
    }
    
    inImage.close();
    
    return;
}

//Open the output image and write the data to the file.
void openOutImage(cmdLineInfo &cmdLineData, imageInfo imageData)
{
    //Declare variables here
    std::ofstream outImage;
    
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
        if (cmdLineData.dataType == "-oa")
        {
            //Write ascii
            writeASCII(imageData, outImage);
            std::cout << "ASCII data writtedn\n";
        }
        
        else if (cmdLineData.dataType == "-ob")
        {
            //Write binary
        }
    }
    
}

void readASCII(imageInfo &imageData, std::ifstream &inImage)
{
    //Declare variables here.
    unsigned int data;
    
    
    //Allocate mormory to read data into
//    allocate2D(red, row, col);
//    allocate2D(imageData.green, imageData.rows, imageData.cols);
//    allocate2D(imageData.blue, imageData.rows, imageData.cols);
    
//    for (int i = 0; i < imageData.rows; i++)
//    {
//        for (int j = 0; j < imageData.cols; j++)
//        {
//            inImage >> data;
//            imageData.redgray[i][j] = unsigned (char (data));
//
//            inImage >> data;
//            imageData.green[i][j] = unsigned (char (data));
//
//            inImage >> data;
//            imageData.blue[i][j] = unsigned (char (data));
//        }
//    }
//
    return;
}

void readBinary()
{
    
}

//Write the file in ASCII format
void writeASCII(imageInfo imageData, std::ofstream &outImage)
{
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


