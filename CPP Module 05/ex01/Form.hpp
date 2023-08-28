#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form {

    private:
        std::string const _name;
        bool _sign;
        int const _signGrade;
        int const _executeGrade;

    public:
        Form();
        Form( std::string _name, int _signGrade, int _executeGrade );
        Form( const Form& copy );
        Form& operator=(const Form& copy);
        ~Form();


        std::string getName() const;
        int getSignGrade() const;
        int getExecuteGrade() const;
        bool getSign() const;

        void beSigned(const Bureaucrat& bureaucrat);
        
        class GradeTooLowException : public std::exception {
            public:
                virtual const char* what() const throw();
        };
        class GradeTooHighException : public std::exception {
            public:
                virtual const char* what() const throw();
        };

};

std::ostream& operator << (std::ostream& os, const Form& p);

#endif