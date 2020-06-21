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
    cmd_line_info cmd_data;
    
    //Check for command line errors and read in data.
    cmd_line_check0(argc, argv, cmd_data);
    
    return 0;
}

