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
    //Declare variables here.
    cmdLineInfo cmdLineData;
    imageInfo imageData;
    
    //Check for command line errors and read in command line data.
    cmdLineCheck0(argc, argv, cmdLineData);
    
    //Open the image and read in data.
    openInImage(cmdLineData, imageData);
    
    //Format the image here. 
    
    //Open the output image and write data to it.
    openOutImage(cmdLineData, imageData);
    
    return 0;
}

