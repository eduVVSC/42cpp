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
            std::string filename = target + "_shrubbery";
            std::ofstream MyFile(filename.c_str());
            MyFile << "    oxoxoo    ooxoo\n  ooxoxo oo  oxoxooo\n oooo xxoxoo ooo ooox\n oxo o oxoxo  xoxxoxo\n  oxo xooxoooo o ooo\n    ooo\\oo\\  /o/o\n        \\  \\/ /\n         |   /\n         |  |\n         | D|\n         |  |\n         |  |";
        }
        else
            throw GradeTooLowException("Grade was too low");
    }
    else
        throw NotSignedException("Form was not signed");
}