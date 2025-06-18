//
// Created by edvieira on 6/17/25.
//

#ifndef INTERN_HPP
# define INTERN_HPP

# include "../Forms/AForm.hpp"
# include "../Forms/PresidentialPardonForm.hpp"
# include "../Forms/RobotomyRequestForm.hpp"
# include "../Forms/ShrubberyCreationForm.hpp"
# include "../exceptions/TypeNotFound.hpp"

# include <string>
# include <exception>


class Intern {
private:
    static const int PRESIDENCIAL_PARDON_FORM = 0;
    static const int ROBOTOMY_REQUEST_FORM = 1;
    static const int SHRUBBERY_CREATION_FORM = 2;
public:
    AForm *makeForm(std::string formName, std::string target);

    Intern();
    Intern(const Intern &other);
    ~Intern();

    Intern& operator=(const Intern& other);
};


#endif