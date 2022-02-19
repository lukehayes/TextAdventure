#ifndef TA_IO_H
#define TA_IO_H

#include "Common.h"
#include <fstream>
#include <regex>

using VecStr = std::vector<std::string>;

std::string ReadFile(const std::string& filename)
{
    std::string fileContents;
    std::fstream stream(filename, std::ios::in);

    while(stream.good())
    {
        std::string line;
        std::getline(stream, line);
        fileContents += line + "\n";
    }

    stream.close();
    return fileContents;
}

/**
 * Get all of the possible choices for the current story page
 */
VecStr GetStoryChoices()
{
    VecStr choices;

    std::string str = ReadFile("pages/1.txt");
    std::cout << "Contents: " << str << std::endl;
    std::smatch match;
    std::regex r("(\\[[A-Z]\\])"); // Grab the capital letter in "[W]alk"

    std::regex_search(str, match, r);
    choices.push_back(match.str());

    //std::cout << match.suffix().str() << std::endl;
    //std::cout << match.str() << std::endl;


    return choices;
}


#endif
