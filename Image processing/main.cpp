//  main.cpp
//  Image processing
//
//  Created by Musa Bah on 6/7/20.
//  Copyright © 2020 Musa Bah. All rights reserved.
//

// Include the image header file
#include "imageHeader.h"


int main(int argc, const char *argv[])
{
    //This is for testing
    pixel **color = nullptr;
    int rows = 10;
    int cols = 10;
    
    
    //Declare variables here.
    cmdLineInfo cmdLineData;
    imageInfo imageData;
    
    //Check for command line errors and read in data.
    cmdLineCheck0(argc, argv, cmdLineData);
    
    //Open the image and read in data.
    openInImage(cmdLineData, imageData);
    
    
    //openOutImage(cmdLineData, imageData);
    
    //This is for testing

    allocate2D(color, rows, cols);
    
    
    return 0;
}

