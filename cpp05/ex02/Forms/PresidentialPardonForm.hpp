//
// Created by edvieira on 6/17/25.
//

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "AForm.hpp"

class PresidentialPardonForm : public AForm {
private:

public:
    void execute(Bureaucrat const & executor) const;

    PresidentialPardonForm(std::string target);
};


#endif
