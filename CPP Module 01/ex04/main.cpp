#include "CopyFile.hpp"

int main(int ac, char **av) {
    
    CopyFile file;
    
    if (ac == 1 || ac > 4) {
        std::cout << "Error" << std::endl;
        return 1;
    }

    file.copyArguments(av[1], av[2], av[3]);
    file.openSourceFile(file.getFileName());
    file.copyFromSourceInString();
    file.replaceStringInString();
    file.createDestFile();
    return 0;
}