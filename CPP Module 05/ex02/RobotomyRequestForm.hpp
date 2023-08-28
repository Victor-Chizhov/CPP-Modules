#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
#include "Bureaucrat.hpp" 

class RobotomyRequestForm : public AForm {

    public:
        RobotomyRequestForm();
        RobotomyRequestForm(std::string _target);
        RobotomyRequestForm(const RobotomyRequestForm& copy);
        RobotomyRequestForm& operator=(const RobotomyRequestForm& copy);
        virtual ~RobotomyRequestForm();


        void execute(const Bureaucrat& bureaucrat) const;

};

#endif