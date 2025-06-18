//
// Created by edvieira on 6/16/25.
//

#include "AForm.hpp"

void AForm::beSign(int grade){
    // greater grade
    if (!sign){
        if (grade <= requiredGradeSign){
            sign = true;
        }
        else
            throw GradeTooLowException("Grade too low to sign ");
    }
    else
        throw AlreadySignedException("This form has already been signed");
}

// ====== Getters

std::string AForm::getTarget() const {
    return target;
}

std::string AForm::getName() const{ return name; }

bool AForm::getSign() const{ return sign; }

int AForm::getRequiredGradeSign() const{ return requiredGradeSign; }

int AForm::getRequiredGradeExecute() const{ return requiredGradeExecute; }


// ====== Setters

void AForm::setSign(bool sign) {
    this->sign = sign;
}

void AForm::setRequiredGradeSign(int grade) {
    requiredGradeSign = grade;
}

void AForm::setRequiredGradeExecute(int grade) {
    requiredGradeExecute = grade;
}

// ====== constructor

AForm::~AForm(){
}

AForm::AForm(std::string target, std::string name) : name(name), target(target){
}

std::ostream& operator<<(std::ostream& os, const AForm& form) {
    os << "[" << form.getName() << ", isSigned=" << form.getSign() << " requiredGradeToSign="
        << form.getRequiredGradeSign() << " requiredGradeToExecute=" << form.getRequiredGradeExecute() << "]";
    return os;
}
