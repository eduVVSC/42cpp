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
public:
    Aform makeForm(std::string formName, std::string target);

    Intern();
    Intern(const Intern &other);
    ~Intern();

    Intern& operator=(const Intern& other);
};


#endif