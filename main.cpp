#include <iostream>
#include <string>

int main() {
    std::string line;

    //Takes a string input
    while(true) {
        std::cout << "->: ";
        std::getline(std::cin, line);

        //Return if empty
        if(line.empty()) {
            std::cout << "Invalid expression!\n";
            return -1;
        }
    }

    return 0;
}
