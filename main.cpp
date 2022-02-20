#include "Common.h"
#include "io.h"
#include "PageParser.h"
#include "Room.h"

int main()
{
    system("clear");
    std::cout << "Welcome." << std::endl;
    std::string input;

    std::string file = ReadFile("pages/1.txt");

    file.resize(98);

    Room a(
            file, 
            GetStoryChoices(),
            GetChoiceStrings(),
            GetNextPage()
   );

    for(auto choice : a.getNextRooms())
    {
        std::cout << choice << std::endl;
    }


    while(input != "q")
    {
        std::cin >> input;
        std::cout << "Said: " << input << std::endl;

        if(input == "n")
        {
            system("clear");
            continue;
        }
        if(input == "h" || input == "help")
        {
            system("clear");
            std::cout << "Showing Help..." << std::endl;
            continue;
        }
    }

    std::cout << "Goodbye." << std::endl;

    return 0;
}
