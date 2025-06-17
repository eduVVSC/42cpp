//
// Created by edvieira on 6/17/25.
//

#include "PresidentialPardonForm.hpp"


PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm(target, "PresidentialPardonForm") {
    this->requiredGradeSign = 25;
    this->requiredGradeExecute = 5;
    this->sign = false;
}

void PresidentialPardonForm::execute(const Bureaucrat &executor) {
    if (sign){
        if (executor.getGrade() <= requiredGradeExecute){
            std::cout << target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
        }
        else
            throw GradeTooLowException("Grade was too low");
    }
    else
        throw NotSignedException("Form was not signed");
}