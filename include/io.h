#ifndef TA_IO_H
#define TA_IO_H

#include "Common.h"
#include <fstream>

std::string ReadFile(const std::string& filename)
{
    std::string fileContents;
    std::fstream stream(filename, std::ios::in);

    while(stream.good())
    {
        std::string line;
        std::getline(stream, line);
        //if(line == "~")
        //{
            //line.clear();
            //std::cout << "Breaking" << std::endl;
            //break;
        //}
        fileContents += line + "\n";
    }

    stream.close();
    return fileContents;
}


#endif
