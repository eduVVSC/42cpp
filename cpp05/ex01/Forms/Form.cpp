//
// Created by edvieira on 6/16/25.
//


std::string Form::getName() const{ return this->getName(); }

bool Form::getSign() const{ return this->getSign(); }

int Form::getRequiredGradeSign() const{ return requiredGradeSign; }

int Form::getRequiredGradeExecute() const{ return requiredGradeExecute; }

void Form::beSign(int grade){
    // greater grade
    if (!sign){
        if (grade <= requiredGradeSign){
            sign = true;
        }
        else
            throw GradeTooLowException();
    }
}

// ====== constructor
Form::Form(std::string name, int requiredGradeSign, int requiredGradeExecute){
    this->name = name;
    this->requiredGradeSign = requiredGradeSign;
    this->requiredGradeExecute = requiredGradeExecute;
    sign = false;
}

Form::Form(Form &form){
    this->name = form.getName();
    this->requiredGradeSign = form.getRequiredGradeSign();
    this->requiredGradeExecute = form.getRequiredGradeExecute();
    this->sign = form.getSign();
}


Form::~Form(){

}
