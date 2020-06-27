//Creates and frees up memory
#include "imageHeader.h"

void allocate2D(pixel **&color, int rows, int cols)
{
    color = new (std::nothrow) pixel *[rows];
    
    if (color ==  nullptr)
    {
        std::cout << "Could not allocate memory\n";
        exit(0);
    }
    
   
    for (int i = 0; i < rows; i++)
    {
        color[i] = new (std::nothrow) pixel [cols];
        
        if (color[i] == nullptr)
        {
            for (int j = 0; j < i; j++)
                delete [] color[j];
            
            delete color;
            std::cout << "Could not allocate memory.\n";
            exit(0);
        }
    }
    
    return;
}

void free2D(pixel **&color, int rows, int cols)
{
    if (color == nullptr)
        return;
    
    for (int i = 0; i < rows; i++)
        delete [] color[i];
    
    delete color;
    
    return;
}
