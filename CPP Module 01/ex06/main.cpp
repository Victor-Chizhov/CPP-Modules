#include "Harl.hpp"

int main(int ac, char **av) {

    Harl a;
    
    switch (ac) {
        case 2:
            a.complain(av[1]);
            break;
        default:
            std::cout << "Error" << std::endl;
            return 1;
    }
    return 0;
}