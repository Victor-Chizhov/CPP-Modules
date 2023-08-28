#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {

    private:
        std::string const _name;
        bool _sign;
        int const _signGrade;
        int const _executeGrade;
        std::string _target;

    public:
        AForm();
        AForm( std::string _name, int _signGrade, int _executeGrade );
        AForm( const AForm& copy );
        AForm& operator=(const AForm& copy);
        virtual ~AForm();


        virtual std::string getName() const;
        virtual int getSignGrade() const;
        virtual int getExecuteGrade() const;
        virtual bool getSign() const;
        virtual std::string getTarget() const;
        virtual void setTarget(std::string target);
        virtual void execute(const Bureaucrat& executor) const = 0;
        virtual void beSigned(const Bureaucrat& bureaucrat);
        
        class GradeTooLowException : public std::exception {
            public:
                virtual const char* what() const throw();
        };
        class GradeTooHighException : public std::exception {
            public:
                virtual const char* what() const throw();
        };

};

std::ostream& operator << (std::ostream& os, const AForm& p);

#endif