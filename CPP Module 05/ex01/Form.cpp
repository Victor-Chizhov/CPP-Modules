#include "Form.hpp"

Form::Form() : _name("default"), _signGrade(0), _executeGrade(0) {
    _sign = false;
}

Form::Form( std::string name, int signGrade, int executeGrade ) : _name(name), _signGrade(signGrade), _executeGrade(executeGrade) {
    
    if (signGrade > 150 || executeGrade > 150)
        throw GradeTooLowException();
    else if (signGrade < 1 || executeGrade < 1) 
        throw GradeTooHighException();
    
    this->_sign = false;
}

Form::Form( const Form& copy ) : _name(copy._name), _signGrade(copy._signGrade), _executeGrade(copy._executeGrade) {
    *this = copy;
}

Form& Form::operator=(const Form& copy) {
    if (this != &copy) {
        _sign = false;
    }
    return *this;
}

Form::~Form() {

}

std::string Form::getName() const {
    return _name;
}

int Form::getSignGrade() const {
    return _signGrade;
}

int Form::getExecuteGrade() const {
    return _executeGrade;
}

bool Form::getSign() const {
    return _sign ? true : false;
}

const char* Form::GradeTooHighException::what() const throw() {
    return "Grade is too high";
}

const char* Form::GradeTooLowException::what() const throw() {
    return "Grade is too low";
}

void Form::beSigned(const Bureaucrat& bureaucrat) {
    if (bureaucrat.getGrade() > _signGrade)
        throw GradeTooLowException();
    _sign = true;
}

std::ostream& operator << (std::ostream& os, const Form& p) {
    os << "Form: " << p.getName() << std::endl;
    os << "Sign: " << p.getSign() << std::endl;
    os << "signGrade: " << p.getSignGrade() << std::endl;
    os << "executeGrade: " << p.getExecuteGrade() << std::endl;
    return os;
}