//
// Created by edvieira on 6/17/25.
//

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm(target, "ShrubberyCreationForm") {
    this->requiredGradeSign = 25;
    this->requiredGradeExecute = 5;
    this->sign = false;
}

void ShrubberyCreationForm::execute(const Bureaucrat &executor) const {
    if (sign){
        if (executor.getGrade() <= requiredGradeExecute){
        }
        else
            throw GradeTooLowException("Grade was too low");
    }
    else
        throw NotSignedException("Form was not signed");
}