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

//Structure to store commandline info.
struct cmd_line_info
{
    std::string option_code, data_type;
    std::string out_image_name, in_image_name;
    int bright_set_value;
    
};

//@@@@@@@@@@@@@@ Function prototypes @@@@@@@@@@@@@@@@@
void usage_message();

// Check if data type is ASCII or Binary
bool data_check(std::string data_type);

//Check if the option code is valid.
bool option_checker(std::string option_code);

//Checks which command line check to use.
void cmd_line_check0(int argc, const char *argv[], cmd_line_info &cmd_data);

//Check for command line errors with 4 arguments.
void cmd_line_check1(const char *argv[], cmd_line_info &cmd_data);

//Check formmand line errors with 5 arguments.
void cmd_line_check2(const char *argv[], cmd_line_info &cmd_data);

//Check form command line errors with 6 arguments.
void cmd_line_check3(const char *argv[], cmd_line_info &cmd_data);


