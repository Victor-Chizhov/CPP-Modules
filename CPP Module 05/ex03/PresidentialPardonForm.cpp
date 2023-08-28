#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5) {

}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& copy) : AForm(copy) {
    *this = copy;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& copy) {
    if (this != &copy) {
        AForm::operator = (copy);
    }
    return *this;
}

PresidentialPardonForm::~PresidentialPardonForm() {

}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("Presidential", 25, 5) {
    setTarget(target);
}

void PresidentialPardonForm::execute(const Bureaucrat& bureaucrat) const {
    if (bureaucrat.getGrade() > getExecuteGrade())
        throw GradeTooLowException();
    else if (getSign() == false)
        std::cout << "Form not signed" << std::endl;
    else
        std::cout << getTarget() << " has been pardoned by Zafod Beeblebrox" << std::endl;
}
