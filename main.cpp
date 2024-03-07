#include <iostream>
#include <string>
#include "parse.h"

int main() {
    std::string line;

    //Takes a string input
    while(true) {
        std::cout << "->: ";
        std::getline(std::cin, line);
        //Parser object that takes the string and tokenises it
        Parser parse(line);

        //Return if empty
        if(line.empty()) {
            std::cout << "Invalid expression!\n";
            return -1;
        }
    }

    return 0;
}
