#include "Bureaucrat.hpp"

int main() {
    Bureaucrat a("John Wick", 2);
    a.getName();
    a.getGrade();
    std::cout << a;
    a.increment();
    std::cout << a;
    a.increment();
    std::cout << a;
}