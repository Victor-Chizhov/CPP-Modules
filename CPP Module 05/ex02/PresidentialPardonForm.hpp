#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"
#include "Bureaucrat.hpp"

class PresidentialPardonForm : public AForm {

public:
    PresidentialPardonForm();
    PresidentialPardonForm(std::string _target);
    PresidentialPardonForm(const PresidentialPardonForm& copy);
    PresidentialPardonForm& operator=(const PresidentialPardonForm& copy);
    virtual ~PresidentialPardonForm();

    void execute(const Bureaucrat& bureaucrat) const;

};

#endif