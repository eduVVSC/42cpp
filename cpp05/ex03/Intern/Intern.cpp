//
// Created by edvieira on 6/17/25.
//

#include "Intern.hpp"


AForm Intern::makeForm(std::string formName, std::string target) {
    AForm *result = nullptr;
    switch (formName) {
        case "PresidentialPardonForm":
            result = new PresidentialPardonForm(target);
        case "RobotomyRequestForm":
            result = new RobotomyRequestForm(target);
        case "ShrubberyCreationForm":
            result = new ShrubberyCreationForm(target);
        default:
            throw TypeNotFound("The given type does not exist!");
    }
    return result;
}

Intern::Intern() {

}

Intern::Intern(const Intern &other) {
}