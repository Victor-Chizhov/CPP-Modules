#include "Bureaucrat.hpp"

int main() {
    Bureaucrat a("John Wick", 2);
    Form b("Contract", 5, 15);
    std::cout << a;
    std::cout << b;
    a.signForm(b);

    std::cout << std::endl;

    Bureaucrat a1("Winston Scott", 6);
    Form b1("Contract", 5, 15);
    std::cout << a1;
    std::cout << b1;
    a1.signForm(b1);

}