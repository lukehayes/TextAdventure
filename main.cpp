#include "Common.h"
#include "io.h"
#include "PageParser.h"
#include "Room.h"
#include <algorithm>

int main()
{
    system("clear");
    std::cout << "Welcome." << std::endl;
    std::string input;

    std::string file = "pages/1.txt";
    std::string contents = ReadFile("pages/1.txt");

    contents.resize(98);

    Room a(
            contents, 
            GetStoryChoices(file),
            GetChoiceStrings(file),
            GetNextPage(file)
   );

    while(input != "q")
    {
        std::cout << a.getDescription() << std::endl;


        for(auto choice : a.getChoiceStrings())
        {
            std::cout << choice << std::endl;
        }

        std::cin >> input;


        auto it = std::find(a.getChoiceStrings().begin(), a.getChoiceStrings().end(), input);

        std::cout << *it << std::endl;
        std::cout << *it << std::endl;
        std::cout << *it << std::endl;
        std::cout << *it << std::endl;
        std::cout << *it << std::endl;
        std::cout << *it << std::endl;
        std::cout << *it << std::endl;
        std::cout << *it << std::endl;
        std::cout << *it << std::endl;
        std::cout << *it << std::endl;
        std::cout << *it << std::endl;
        std::cout << *it << std::endl;
        std::cout << *it << std::endl;





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
