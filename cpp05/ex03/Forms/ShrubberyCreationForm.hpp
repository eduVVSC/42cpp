//
// Created by edvieira on 6/17/25.
//

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include "AForm.hpp"

class ShrubberyCreationForm : public AForm {
private:

public:
    void execute(Bureaucrat const & executor) const;

    ShrubberyCreationForm(std::string target);
};


#endif //SHRUBBERYCREATIONFORM_HPP
