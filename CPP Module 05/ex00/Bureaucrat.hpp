#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>

class Bureaucrat {

    private:
        const std::string _name;
        int grade;

    public:
        Bureaucrat();
        Bureaucrat( std::string _name, int grade );
        Bureaucrat( const Bureaucrat& copy );
        Bureaucrat& operator=(const Bureaucrat& copy);
        ~Bureaucrat();


        std::string getName() const;
        int getGrade() const;
        void increment();
        void decrement();
        
        class GradeTooLowException : public std::exception {
            public:
                virtual const char* what() const throw();
        };
        class GradeTooHighException : public std::exception {
            public:
                virtual const char* what() const throw();
        };
};

std::ostream& operator << (std::ostream& os, const Bureaucrat& p);


#endif