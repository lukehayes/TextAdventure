#include "Common.h"
#include "io.h"

int main()
{
    system("clear");
    std::cout << "Welcome." << std::endl;
    std::string input;

    std::string file = ReadFile("pages/1.txt");
    std::cout << file << std::endl;
    
    for(auto choice : GetStoryChoices())
    {
        static int i = 1;
        std::cout << i << ": " << choice  << std::endl;
        i++;
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
    }

    std::cout << "Goodbye." << std::endl;

    return 0;
}
