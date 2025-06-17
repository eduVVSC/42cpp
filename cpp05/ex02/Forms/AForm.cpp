//
// Created by edvieira on 6/16/25.
//

#include "AForm.hpp"

std::string AForm::getName() const{ return name; }

bool AForm::getSign() const{ return sign; }

int AForm::getRequiredGradeSign() const{ return requiredGradeSign; }

int AForm::getRequiredGradeExecute() const{ return requiredGradeExecute; }

void AForm::beSign(int grade){
    // greater grade
    if (!sign){
        if (grade <= requiredGradeSign){
            sign = true;
        }
        else
            throw GradeTooLowException("Grade too low to sign ");
    }
}

// ====== constructor

AForm::~AForm(){
}

void AForm::execute(const Bureaucrat &executor) {
    int grade = executor.getGrade();
    // executre
    if (grade <= requiredGradeExecute){

    }
    else
        throw GradeTooLowException("Grade to low to execute the form!");
}

AForm::AForm(std::string target, std::string name) : name(name), target(target){
}

std::ostream& operator<<(std::ostream& os, const AForm& form) {
    os << form.getName() << ", isSigned=" << form.getSign() << " and have requiredGradeToSign="
        << form.getRequiredGradeSign() << " and requiredGradeToExecute=" << form.getRequiredGradeExecute() <<std::endl;
    return os;
}
