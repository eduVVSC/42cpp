//
// Created by edvieira on 6/17/25.
//

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "AForm.hpp"

class RobotomyRequestForm : public AForm{
private:

public:
    void execute(Bureaucrat const & executor) const;

    RobotomyRequestForm(std::string target);
};


#endif //ROBOTOMYREQUESTFORM_H
