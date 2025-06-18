//
// Created by edvieira on 6/17/25.
//

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm(target, "ShrubberyCreationForm") {
    setRequiredGradeSign(25);
    setRequiredGradeExecute(5);
    setSign(false);
}

void ShrubberyCreationForm::execute(const Bureaucrat &executor) const {
    if (getSign()){
        if (executor.getGrade() <= getRequiredGradeExecute()){
        }
        else
            throw GradeTooLowException("Grade was too low");
    }
    else
        throw NotSignedException("Form was not signed");
}