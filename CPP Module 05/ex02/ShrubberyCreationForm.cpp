#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137) {

}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& copy) : AForm(copy) {
    *this = copy;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& copy) {
    if (this != &copy) {
        AForm::operator = (copy);
    }
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {

}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("Shrubbery", 145, 137) {
    setTarget(target);
}

void ShrubberyCreationForm::execute(const Bureaucrat& bureaucrat) const {
    if (bureaucrat.getGrade() > getExecuteGrade())
        throw GradeTooLowException();
    else if (getSign() == false)
		std::cout << "Form not signed" << std::endl;
	std::ofstream outputFile(getTarget() + "_shrubbery");
	if (outputFile.is_open()) {
		outputFile << "       ccee88oo\n";
		outputFile << "  C8O8O8Q8PoOb o8oo\n";
		outputFile << " dOB69QO8PdUOpugoO9bD\n";
		outputFile << "CgggbU8OU qOp qOdoUOdcb\n";
		outputFile << "O o88oUodcb  dUdUO8PdU\n";
		outputFile << "   6OuU  /p u gcoUodpP\n";
		outputFile << "     \\//  /douUP\n";
		outputFile << "       \\\\////\n";
		outputFile << "        |||/\\\n";
		outputFile << "        |||\\/\\\n";
		outputFile << "        |||||\n";
		outputFile << "  .....//|||||\\....\n";
    }
}
