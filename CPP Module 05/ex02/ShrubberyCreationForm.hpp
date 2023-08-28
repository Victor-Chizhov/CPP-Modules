#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include "Bureaucrat.hpp" 

class ShrubberyCreationForm : public AForm {

    public:
        ShrubberyCreationForm();
        ShrubberyCreationForm(std::string _target);
        ShrubberyCreationForm(const ShrubberyCreationForm& copy);
        ShrubberyCreationForm& operator=(const ShrubberyCreationForm& copy);
        virtual ~ShrubberyCreationForm();

        void execute(const Bureaucrat& bureaucrat) const;

};

#endif