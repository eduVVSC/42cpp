//
// Created by edvieira on 6/17/25.
//

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm(target, "RobotomyRequestForm") {
    this->requiredGradeSign = 25;
    this->requiredGradeExecute = 5;
    this->sign = false;
}

void RobotomyRequestForm::execute(const Bureaucrat &executor) {
    if (sign){
        if (executor.getGrade() <= requiredGradeExecute){
        }
        else
            throw GradeTooLowException("Grade was too low");
    }
    else
        throw NotSignedException("Form was not signed");
}