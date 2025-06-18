//
// Created by edvieira on 6/17/25.
//

#include "PresidentialPardonForm.hpp"


PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm(target, "PresidentialPardonForm") {
    setRequiredGradeSign(25);
    setRequiredGradeExecute(5);
    setSign(false);
}
void PresidentialPardonForm::execute(const Bureaucrat &executor) const {
    if (getSign()){
        if (executor.getGrade() <= getRequiredGradeExecute()){
            std::cout << getTarget() << " has been pardoned by Zaphod Beeblebrox." << std::endl;
        }
        else
            throw GradeTooLowException("Grade was too low");
    }
    else
        throw NotSignedException("Form was not signed");
}