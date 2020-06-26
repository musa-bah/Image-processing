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
    cmdLineInfo cmdData;
    
    //Check for command line errors and read in data.
    cmdLineCheck0(argc, argv, cmdData);
    
    return 0;
}

