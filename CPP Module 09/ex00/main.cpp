#include <iostream>
#include <map>

int main() {
    std::map<std::string, unsigned int> products;

    products["Apple"] = 5;
    products["Banana"] = 10;
    products["Orange"] = 15;

    for (std::map<std::string, unsigned int>::iterator it = products.begin(); it != products.end(); it++) {
        std::cout << it->first << ": " << it->second << std::endl;
    }
    std::cout << std::endl;
    products.erase("Banana");

    for (std::map<std::string, unsigned int>::iterator it = products.begin(); it != products.end(); it++) {
        std::cout << it->first << ": " << it->second << std::endl;
    }

    std::cout << products.size() << std::endl;


    return 0;
}