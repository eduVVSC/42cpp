//
// Created by edvieira on 6/16/25.
//

#ifndef FORM_HPP
# define FORM_HPP

# include "../exceptions/GradeTooHighException.hpp"
# include "../exceptions/GradeTooLowException.hpp"
# include "../exceptions/NotSignedException.hpp"
# include "../exceptions/AlreadySignedException.hpp"

# include "../Bureaucrats/Bureaucrat.hpp"

# include <string>
# include <iostream>

class Bureaucrat;

class AForm {
protected:
    static const int MIN_GRADE = 150;
    static const int MAX_GRADE = 1;

    bool sign;
    int requiredGradeSign;
    int requiredGradeExecute;
    const std::string name;
    const std::string target;
public:
      // ===== getters
    bool getSign() const;
    std::string getName() const;
    int getRequiredGradeSign() const;
    int getRequiredGradeExecute() const;
    void beSign(int grade);

    virtual void execute(Bureaucrat const & executor) const = 0;
    // ====== constructor

    AForm(std::string target, std::string name);

    virtual ~AForm();

    AForm& operator=(AForm &other);
};

std::ostream& operator<<(std::ostream& os, const AForm& form);

#endif
