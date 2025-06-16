//
// Created by edvieira on 6/16/25.
//

#ifndef FORM_HPP
# define FORM_HPP

# include "../exceptions/GradeTooHighException.hpp"
# include "../exceptions/GradeTooLowException.hpp"
# include <string>
# include <iostream>

class Form {
private:
    static const int MIN_GRADE = 150;
    static const int MAX_GRADE = 1;

    const std::string name;
    bool sign;
    int requiredGradeSign;
    int requiredGradeExecute;
public:
      // ===== getters
    bool getSign() const;
    std::string getName() const;
    int getRequiredGradeSign() const;
    int getRequiredGradeExecute() const;
    void beSign(int grade);

    // ====== constructor
    Form(std::string name, int requiredGradeSign, int requiredGradeExecute);
    Form(const Form &form);

    ~Form();

    Form& operator=(Form &other);

};

std::ostream& operator<<(std::ostream& os, const Form& form);

#endif
