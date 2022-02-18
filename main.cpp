#include <iostream>
#include <string>
#include <stdlib.h>
#include "io.h"

int main()
{
    system("clear");
    std::cout << "Welcome." << std::endl;
    std::string input;

    std::string file = ReadFile("scripts/1.txt");
    std::cout << file << std::endl;

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
