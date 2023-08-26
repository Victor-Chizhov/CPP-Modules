#include <iostream>

int main() {
    std::string a = "HI THIS IS BRAIN";
    std::string *aPtr = &a;
    std::string& aRef = a;

    std::cout << "The memory address of the string variable: " << &a << std::endl;
    std::cout << "The memory address held by stringPTR: " << aPtr << std::endl;
    std::cout << "The memory address held by stringREF: " << &aRef << std::endl << std::endl;

    std::cout << "The value of the string variable: " << a << std::endl;
    std::cout << "The value pointed to by stringPTR: " << *aPtr << std::endl;
    std::cout << "The value pointed to by stringREF: " << aRef << std::endl;
}