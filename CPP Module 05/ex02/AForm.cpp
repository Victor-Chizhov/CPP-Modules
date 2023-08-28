#include "AForm.hpp"

AForm::AForm() : _name("default"), _signGrade(0), _executeGrade(0) {
    _sign = false;
}

AForm::AForm( std::string name, int signGrade, int executeGrade ) : _name(name), _signGrade(signGrade), _executeGrade(executeGrade) {
    
    if (signGrade > 150 || executeGrade > 150)
        throw GradeTooLowException();
    else if (signGrade < 1 || executeGrade < 1) 
        throw GradeTooHighException();
    
    this->_sign = false;
}

AForm::AForm( const AForm& copy ) : _name(copy._name), _signGrade(copy._signGrade), _executeGrade(copy._executeGrade) {
    *this = copy;
}

AForm& AForm::operator=(const AForm& copy) {
    if (this != &copy) {
        _sign = false;
    }
    return *this;
}

AForm::~AForm() {

}

std::string AForm::getName() const {
    return _name;
}

int AForm::getSignGrade() const {
    return _signGrade;
}

int AForm::getExecuteGrade() const {
    return _executeGrade;
}

bool AForm::getSign() const {
    return _sign ? true : false;
}

const char* AForm::GradeTooHighException::what() const throw() {
    return "Grade is too high";
}

const char* AForm::GradeTooLowException::what() const throw() {
    return "Grade is too low";
}

void AForm::beSigned(const Bureaucrat& bureaucrat) {
    if (bureaucrat.getGrade() > _signGrade)
        throw GradeTooLowException();
    _sign = true;
}

std::string AForm::getTarget() const {
    return _target;
}

std::ostream& operator << (std::ostream& os, const AForm& p) {
    os << "Form: " << p.getName() << std::endl;
    os << "Sign: " << p.getSign() << std::endl;
    os << "signGrade: " << p.getSignGrade() << std::endl;
    os << "executeGrade: " << p.getExecuteGrade() << std::endl;
    return os;
}

void AForm::setTarget(std::string target) {
    _target = target;
}