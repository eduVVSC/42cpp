//
// Created by edvieira on 6/17/25.
//

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm(target, "RobotomyRequestForm") {
    setRequiredGradeSign(25);
    setRequiredGradeExecute(5);
    setSign(false);
}

void RobotomyRequestForm::execute(const Bureaucrat &executor) const {
    if (sign){
        if (executor.getGrade() <= requiredGradeExecute){
            std::cout << "Makes some drilling noises..." << std::endl;

            srand(time(0));
            int randNum = rand();

            if (randNum % 2 == 0)
                std::cout << target << " has been 🤖robotomized successfully!" << std::endl;
            else
                std::cout << "⛔ Robotomy failed!!" << std::endl;
        }
        else
            throw GradeTooLowException("Grade was too low");
    }
    else
        throw NotSignedException("Form was not signed");
}