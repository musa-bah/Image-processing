//  imageHeader.h
//  Image processing
//
//  Created by Musa Bah on 6/16/20.
//  Copyright © 2020 Musa Bah. All rights reserved.
//
#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>
#include <typeinfo>

#ifndef imageHeader_h
#define imageHeader_h


#endif /* imageHeader_h */

typedef unsigned char pixel;

//Structure to store commandline info.
struct cmdLineInfo
{
    std::string optionCode, dataType;
    std::string outImageName, inImageName;
    int brightSetValue;
    
};

struct imageInfo
{
    std::string magicNumber;
    std::vector<std::string> comments;
    int rows, cols;
    int maxPixel;
    pixel **redgray = nullptr;
    pixel **green = nullptr;
    pixel **blue = nullptr;
    
};

//@@@@@@@@@@@@@@ Function prototypes @@@@@@@@@@@@@@@@@
void usageMessage();

// Check if data type is ASCII or Binary
bool dataCheck(std::string data_type);

//Check if the option code is valid.
bool optionChecker(std::string option_code);

//Checks which command line check to use.
void cmdLineCheck0(int argc, const char *argv[], cmdLineInfo &cmdData);

//Check for command line errors with 4 arguments.
void cmdLineCheck1(const char *argv[], cmdLineInfo &cmdData);

//Check formmand line errors with 5 arguments.
void cmdLineCheck2(const char *argv[], cmdLineInfo &cmdData);

//Check form command line errors with 6 arguments.
void cmdLineCheck3(const char *argv[], cmdLineInfo &cmdData);

// Open the in and out file in binary mode and read in file data.
void openInImage(cmdLineInfo &cmdLineData, imageInfo &imageData);

void openOutImage(cmdLineInfo &cmdLineData, imageInfo imageData);

//Allocate and free memory
void allocate2D(pixel **&color, int rows, int cols);

void free2D(pixel **&color, int rows, int cols);

//Read and write data.
void readASCII(imageInfo &imageData, std::ifstream &inImage);

void writeASCII(imageInfo imageData, std::ofstream &outImage);

void readBinary();

void writeBinary();




