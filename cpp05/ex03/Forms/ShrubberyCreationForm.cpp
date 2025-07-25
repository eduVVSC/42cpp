//
// Created by edvieira on 6/17/25.
//

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm(target, "ShrubberyCreationForm") {
    setRequiredGradeSign(25);
    setRequiredGradeExecute(5);
    setSign(false);
}

void ShrubberyCreationForm::execute(const Bureaucrat &executor) const {
    if (getSign()){
        if (executor.getGrade() <= getRequiredGradeExecute()){
            std::string filename = getTarget() + "_shrubbery";
            std::ofstream MyFile(filename.c_str());
            MyFile << "    oxoxoo    ooxoo\n  ooxoxo oo  oxoxooo\n oooo xxoxoo ooo ooox\n oxo o oxoxo  xoxxoxo\n  oxo xooxoooo o ooo\n    ooo\\oo\\  /o/o\n        \\  \\/ /\n         |   /\n         |  |\n         | D|\n         |  |\n         |  |";
        }
        else
            throw GradeTooLowException("Grade was too low");
    }
    else
        throw NotSignedException("Form was not signed");
}