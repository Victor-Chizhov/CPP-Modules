#include "Intern.hpp"

Intern::Intern() {
}

Intern::Intern(const Intern& copy) {
    *this = copy;
}

Intern& Intern::operator=(const Intern& copy) {
    (void)copy;
    return *this;
}

Intern::~Intern() {
}

AForm* Intern::makeForm(std::string formName, std::string target) {

    std::string formNames[3] = {
        "shrubbery creation",
        "robotomy request",
        "presidential pardon"
    };

    for (int i = 0; i < 3; i++) {
        if (formName == formNames[i]) {
            std::cout << "Intern creates " << formName << std::endl;
            switch (i) {
                case 0:
                    return new ShrubberyCreationForm(target);
                case 1:
                    return new RobotomyRequestForm(target);
                case 2:
                    return new PresidentialPardonForm(target);

            }
        }
    }
    std::cout << "Intern doesn't know this form" << std::endl;
    return NULL;
}