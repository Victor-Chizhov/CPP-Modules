#include <iostream>
#include <string>
#include <sstream>


int main() {
    std::string input;

    // Read a line of text including leading spaces
    std::cout << "Enter a line of text: ";
    std::getline(std::cin, input);

    std::string word;

    // Use std::ws to skip leading spaces
    std::istringstream iss(input);
    iss >> std::ws;

    // Now, you can extract the first word or token
    if (iss >> word) {
        std::cout << "First word: " << word << std::endl;
    } else {
        std::cout << "No words found." << std::endl;
    }

    return 0;
}





