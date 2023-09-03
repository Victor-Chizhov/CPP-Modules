#include "RPN.hpp"

int main(int ac, char **av) {
    if (ac != 2) {
        std::cout << "Usage: ./rpn \"<expression>\"" << std::endl;
        return 1;
    }

    RPN rpn;
    try {
        rpn.calculate(av[1]);
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
        return 1;
    }

}