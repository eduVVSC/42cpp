//
// Created by edvieira on 6/16/25.
//

#ifndef FORM_HPP
# define FORM_HPP

# include "../exceptions/GradeTooHighException.hpp"
# include "../exceptions/GradeTooLowException.hpp"
# include <string>

class Form {
private:
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
    Form(Form &form);

    ~Form();
    Form& operator=(Form &other);
};



#endif
