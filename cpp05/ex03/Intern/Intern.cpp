//
// Created by edvieira on 6/17/25.
//

#include "Intern.hpp"


AForm* Intern::makeForm(std::string formName, std::string target) {
    AForm *result;
    std::string forms[3];
    int index = -1;

    forms[0] = "PresidentialPardonForm";
    forms[1] = "RobotomyRequestForm";
    forms[2] = "ShrubberyCreationForm";

    for (int i = 0; i < 3; i++) {
        if (formName.compare(forms[i]) == 0) {
            index = i;
        }
    }

    switch (index) {
        case PRESIDENCIAL_PARDON_FORM:
            result = new PresidentialPardonForm(target);
            break;
        case ROBOTOMY_REQUEST_FORM:
            result = new RobotomyRequestForm(target);
            break;
        case SHRUBBERY_CREATION_FORM:
            result = new ShrubberyCreationForm(target);
            break;
        default:
            throw TypeNotFound("Could not create the form, The given type does not exist!");
    }
    return result;
}

Intern::Intern() {
}

Intern::Intern(const Intern &other) {
    (void) other;
}

Intern::~Intern() {

}
