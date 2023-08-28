#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45) {

}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& copy) : AForm(copy) {
    *this = copy;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& copy) {
    if (this != &copy) {
        AForm::operator = (copy);
    }
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {

}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("Robotomy", 72, 45) {
    setTarget(target);
}

void RobotomyRequestForm::execute(const Bureaucrat& bureaucrat) const {
    if (bureaucrat.getGrade() > getExecuteGrade())
        throw GradeTooLowException();
    else if (getSign() == false)
        std::cout << "Form not signed" << std::endl;
    else {
        std::cout << "* drilling noises *" << std::endl;
        if (rand() % 2 == 0)
            std::cout << getTarget() << " has been robotomized successfully" << std::endl;
        else
            std::cout << getTarget() << " has not been robotomized successfully" << std::endl;
    }
}
