#ifndef TA_STORYBLOCK_H
#define TA_STORYBLOCK_H

#include "Common.h"

class StoryBlock
{
public:
        StoryBlock();
        ~StoryBlock();

        void addLine(const std::string& line);
        void option(const std::string& option);

private:
        VecStr lines;
        VecStr options;
};

#endif
