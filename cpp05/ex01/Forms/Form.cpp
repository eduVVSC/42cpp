//
// Created by edvieira on 6/16/25.
//

#include "Form.hpp"

std::string Form::getName() const{ return name; }

bool Form::getSign() const{ return sign; }

int Form::getRequiredGradeSign() const{ return requiredGradeSign; }

int Form::getRequiredGradeExecute() const{ return requiredGradeExecute; }

void Form::beSign(int grade){
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
Form::Form(std::string name, int requiredGradeSign, int requiredGradeExecute) : name(name){
    if (requiredGradeSign < MAX_GRADE || requiredGradeExecute < MAX_GRADE)
        throw GradeTooHighException("Grade higher than the highest that a Bureaucrat can have");
    if (requiredGradeSign > MIN_GRADE || requiredGradeExecute > MIN_GRADE)
        throw GradeTooLowException("Grade lower than the lowest that a Bureaucrat can have");

    this->requiredGradeSign = requiredGradeSign;
    this->requiredGradeExecute = requiredGradeExecute;
    sign = false;
}

Form::Form(const Form &form) : name(form.getName()){
    this->requiredGradeSign = form.getRequiredGradeSign();
    this->requiredGradeExecute = form.getRequiredGradeExecute();
    this->sign = form.getSign();
}

Form::~Form(){
}

std::ostream& operator<<(std::ostream& os, const Form& form) {
    os << form.getName() << ", isSigned=" << form.getSign() << " and have requiredGradeToSign="
        << form.getRequiredGradeSign() << " and requiredGradeToExecute=" << form.getRequiredGradeExecute() <<std::endl;
    return os;
}
