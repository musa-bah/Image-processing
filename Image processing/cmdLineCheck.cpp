// This file checks the command line for errors in the arguments.
#include "imageHeader.h"

//Check for errors based on the number of arguments
bool dataCheck(std::string dataType)
{
    if (dataType.compare("-oa") == 0)
        return true;
    
    else if (dataType.compare("-ob") == 0)
        return true;
    
    return false;
}

//Checks if the user provided the right option for the image.
bool optionChecker(std::string optionCode)
{
    std::vector<std::string> optionCodes = {"-n", "-b", "-p", "-s", "-g", "-c"};

    for (unsigned int i = 0; i < optionCodes.size(); i++)
    {
        if (optionCode.compare(optionCodes[i]) == 0)
        {
            return true;
        }
    }

    return false;
}

//Determines which command line error checker to invoke.
void cmdLineCheck0(int argc, const char *argv[], cmdLineInfo &cmd_data)
{
    if (argc == 4)
        cmdLineCheck1(argv, cmd_data);
    
    else if (argc == 5)
        cmdLineCheck2(argv, cmd_data);
    
    else if (argc == 6)
        cmdLineCheck3(argv, cmd_data);
    
    else
    {
        std::cout << "Invalid arguments.\n" << std::endl;
        usageMessage();
    }
}

//Check one is used when there are 4 cmd arguments.
void cmdLineCheck1(const char *argv[], cmdLineInfo &cmdData)
{
    if (dataCheck(argv[1]) == false)
    {
        std::cout << "Invalid data type.\n" << std::endl;
        usageMessage();
        exit(0);
    }
    
    else
    {
        cmdData.dataType = argv[1];
        cmdData.outImageName = argv[2];
        cmdData.inImageName = argv[3];
    }
}

//Check two is used when there are 5 cmd arguments.
void cmdLineCheck2(const char *argv[], cmdLineInfo &cmdData)
{
    std::string bright = "-b";
    
    if (bright.compare(argv[1]) == 0)
    {
        std::cout << "Brightness value needed. Re-enter options.\n" << std::endl;
        usageMessage();
        exit(0);
    }
    
    else if (optionChecker(argv[1]) == false)
    {
        std::cout << "Invalid option code\n" << std::endl;;
        usageMessage();
        exit(0);
    }
    
    else if (dataCheck(argv[2]) == false)
    {
        std::cout << "Invalid data type.\n" << std::endl;
        usageMessage();
        exit(0);
    }
    
    else
    {
        cmdData.optionCode = argv[1];
        cmdData.dataType = argv[2];
        cmdData.outImageName = argv[3];
        cmdData.inImageName = argv[4];
    }
}

//Check three is used when there are 6 arguments.
void cmdLineCheck3(const char *argv[], cmdLineInfo &cmdData)
{
    std::string bright = "-b";
    if (bright.compare(argv[1]) != 0)
    {
        std::cout << "Invalid option code.\n" << std::endl;
        usageMessage();
        exit(0);
    }
    
    else
    {
        if (dataCheck(argv[3]) == false)
        {
            std::cout << "Invalid data type.\n" << std::endl;
            usageMessage();
            exit(0);
        }
        
        else
        {
            cmdData.optionCode = argv[1];
            cmdData.brightSetValue = atoi(argv[2]);
            cmdData.dataType = argv[3];
            cmdData.outImageName = argv[4];
            cmdData.inImageName = argv[5];
        }
    }
}

void usageMessage()
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
