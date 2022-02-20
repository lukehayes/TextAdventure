#ifndef TA_PAGEPARSER_H
#define TA_PAGEPARSER_H

#include "Common.h"
#include "io.h"
#include "StoryBlock.h"
#include <regex>

using VecStoryBlock = std::vector<StoryBlock>;

/**
 * Get all of the possible choices for the current story page
 */
VecStr GetStoryChoices(const std::string& filename)
{
    VecStr choices;

    std::string str = ReadFile(filename);
    std::smatch match;
    std::regex r("\\[([A-Z])\\]"); // Grab the capital letter in "[W]alk"

    auto const_iter = str.cbegin();

    // Loop through and get all of the choices in the file: "[W]" for example.
    while(std::regex_search(const_iter, str.cend(), match, r))
    {
        const_iter = match.suffix().first;
        std::cout << "------" << std::endl;
        std::cout << match.str() << std::endl;
        std::cout << match.str(1) << std::endl;
        std::cout << "------" << std::endl;
        choices.push_back(match.str(1));
    }

    return choices;
}

/**
 * Get all of the possible choices for the current story page
 */
VecStr GetChoiceStrings(const std::string& filename)
{
    VecStr choices;

    std::string str = ReadFile(filename);
    std::smatch match;
    std::regex r("\\[[A-Z]\\]\\w+.+"); // Grab all the text of the option.

    auto const_iter = str.cbegin();
    // Loop through and get all of the choices in the file: "[W]" for example.
    while(std::regex_search(const_iter, str.cend(), match, r))
    {
        const_iter = match.suffix().first;
        choices.push_back(match.str());
    }

    return choices;
}

/**
 * Get the next possible page from the choices.
 */
VecStr GetNextPage(const std::string& filename)
{
    VecStr choices;

    std::string str = ReadFile(filename);
    std::smatch match;
    std::regex r("\\[#([A-Za-z]+)\\]"); // Grab next page '[#NextPage]'
                                     //
    auto const_iter = str.cbegin();
    // Loop through and get all of the choices in the file: "[W]" for example.
    while(std::regex_search(const_iter, str.cend(), match, r))
    {
        const_iter = match.suffix().first;

        if(match.str() != "[#END]")
        {
            // 1 gets just the string in the () group,
            // 0 gets the entire matched string.
            choices.push_back(match.str(1));
        }
    }

    return choices;
}


#endif
