// This file checks the command line for errors in the arguments.
#include "imageHeader.h"

//Check for errors based on the number of arguments
bool data_check(std::string data_type)
{
    if (data_type.compare("-oa") == 0)
        return true;
    
    else if (data_type.compare("-ob") == 0)
        return true;
    
    return false;
}

//Checks if the user provided the right option for the image.
bool option_checker(std::string option_code)
{
    std::vector<std::string> option_codes = {"-n", "-b", "-p", "-s", "-g", "-c"};

    for (unsigned int i = 0; i < option_codes.size(); i++)
    {
        if (option_code.compare(option_codes[i]) == 0)
        {
            return true;
        }
    }

    return false;
}

//Determines which command line error checker to invoke.
void cmd_line_check0(int argc, const char *argv[], cmd_line_info &cmd_data)
{
    if (argc == 4)
        cmd_line_check1(argv, cmd_data);
    
    else if (argc == 5)
        cmd_line_check2(argv, cmd_data);
    
    else if (argc == 6)
        cmd_line_check3(argv, cmd_data);
    
    else
    {
        std::cout << "Invalid arguments.\n" << std::endl;
        usage_message();
    }
}

//Check one is used when there are 4 cmd arguments.
void cmd_line_check1(const char *argv[], cmd_line_info &cmd_data)
{
    if (data_check(argv[1]) == false)
    {
        std::cout << "Invalid data type.\n" << std::endl;
        usage_message();
        exit(0);
    }
    
    else
    {
        cmd_data.data_type = argv[1];
        cmd_data.out_image_name = argv[2];
        cmd_data.in_image_name = argv[3];
    }
}

//Check two is used when there are 5 cmd arguments.
void cmd_line_check2(const char *argv[], cmd_line_info &cmd_data)
{
    std::string bright = "-b";
    
    if (bright.compare(argv[1]) == 0)
    {
        std::cout << "Brightness value needed. Re-enter options.\n" << std::endl;
        usage_message();
        exit(0);
    }
    
    else if (option_checker(argv[1]) == false)
    {
        std::cout << "Invalid option code\n" << std::endl;;
        usage_message();
        exit(0);
    }
    
    else if (data_check(argv[2]) == false)
    {
        std::cout << "Invalid data type.\n" << std::endl;
        usage_message();
        exit(0);
    }
    
    else
    {
        cmd_data.option_code = argv[1];
        cmd_data.data_type = argv[2];
        cmd_data.out_image_name = argv[3];
        cmd_data.in_image_name = argv[4];
    }
}

//Check three is used when there are 6 arguments.
void cmd_line_check3(const char *argv[], cmd_line_info &cmd_data)
{
    std::string bright = "-b";
    if (bright.compare(argv[1]) != 0)
    {
        std::cout << "Invalid option code.\n" << std::endl;
        usage_message();
        exit(0);
    }
    
    else
    {
        if (data_check(argv[3]) == false)
        {
            std::cout << "Invalid data type.\n" << std::endl;
            usage_message();
            exit(0);
        }
        
        else
        {
            cmd_data.option_code = argv[1];
            cmd_data.bright_set_value = atoi(argv[2]);
            cmd_data.data_type = argv[3];
            cmd_data.out_image_name = argv[4];
            cmd_data.in_image_name = argv[5];
        }
    }
}

void usage_message()
{
    std::cout <<"@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n";
    std::cout << "How to run the program.\n";
    std::cout << "In this progrma there can be a min of 3 arguments and a max of 5.\n";
    std::cout << "Default arguments example: image.exe -o(ab) out-name in-name.ppm\n";
    std::cout << "-oa       ----- write the final image to ASCII\n";
    std::cout << "-ob       ----- write the final image to Binary\n";
    std::cout << "out-name  ----- is the name of the processed image\n";
    std::cout << "in-name   ----- is the name of the image to be processed\n" << std::endl;
        
    
    std::cout << "To apply a filter to the image, enter the option code after the .exe file name\n";
    std::cout << "Option Code     Filter applied\n";
    std::cout << "        -n      Negate\n";
    std::cout << "        -b #    Brighten (# is the brightness value)\n";
    std:: cout << "        -p      Sharpen\n";
    std::cout << "        -s      Smooth\n";
    std::cout << "        -g      Grayscale\n";
    std::cout << "        -c      Contrast\n";
    std::cout << "Example to apply filter: image.exe option code (#) -o(ab) out-name in-name.ppm\n";
    std::cout << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n";
    std::cout << std::endl;
    
}

