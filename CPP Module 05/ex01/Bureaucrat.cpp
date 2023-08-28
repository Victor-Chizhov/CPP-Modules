#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("default") {
    grade = 150;
}

Bureaucrat::Bureaucrat( std::string name, int grade ) : _name(name) {
    if (grade > 150)
        throw GradeTooLowException();
    else if (grade < 1)
        throw GradeTooHighException();
    
    this->grade = grade;
}

Bureaucrat::Bureaucrat( const Bureaucrat& copy ) {
    *this = copy;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& copy) {
    if (this != &copy) {
        this->grade = copy.grade;
    }
    return *this;
}

Bureaucrat::~Bureaucrat() {

}

std::string Bureaucrat::getName() const {
    return _name;
}

int Bureaucrat::getGrade() const {
    return grade;
}


const char* Bureaucrat::GradeTooHighException::what() const throw() {
    return "Grade is too high";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
    return "Grade is too low";
}

void Bureaucrat::increment() {
    try {
        if (grade - 1 < 1)
            throw GradeTooHighException();
        grade--;

    } catch( std::exception & e ) {
        std::cout << "Caught exception: " << e.what() << std::endl;
    }
}

void Bureaucrat::decrement() {
    try {
        if (grade + 1 > 150)
            throw GradeTooLowException();
        grade++;

    } catch( std::exception & e ) {
        std::cout << "Caught exception: " << e.what() << std::endl;
    }
}

void Bureaucrat::signForm(Form& form) const {
    try {
        form.beSigned(*this);
        std::cout << _name << " signed " << form.getName() << std::endl;
    } catch (std::exception &e) {
        std::cout << _name << " cannot sign " << form.getName() << " because " << e.what() << std::endl;
    }
}



std::ostream& operator << (std::ostream& os, const Bureaucrat& p) {
    os << p.getName() << ", bureaucrat grade " << p.getGrade() << std::endl;
    return os;
}