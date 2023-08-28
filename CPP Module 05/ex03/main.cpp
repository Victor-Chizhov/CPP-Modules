#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main() {

    Intern someRandomIntern;
    AForm* rrf;
    rrf = someRandomIntern.makeForm("robotomy request", "Bender");

    Bureaucrat John("John Wick", 2);
    std::cout << John;

    std::cout << std::endl;

    Bureaucrat Winston("Winston Scott", 140);
    std::cout << Winston;

    std::cout << std::endl;

    Bureaucrat Charon("Charon", 120);
    std::cout << Charon;

    std::cout << std::endl;

    AForm* Shrubbery = new ShrubberyCreationForm("Form1");
    AForm* Presidential = new PresidentialPardonForm("Form3");

    John.signForm(*Shrubbery);
    Winston.signForm(*rrf);
    Charon.signForm(*Presidential);

    std::cout << std::endl;

    John.executeForm(*Shrubbery);
    Winston.executeForm(*rrf);
    Charon.executeForm(*Presidential);


}