//
// Created by edvieira on 6/16/25.
//

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <string>
# include <iostream>

# include "../Forms/AForm.hpp"

# include "../exceptions/GradeTooHighException.hpp"
# include "../exceptions/GradeTooLowException.hpp"
# include "../exceptions/NotSignedException.hpp"

class AForm;

class Bureaucrat {
    private:
       static const int MIN_GRADE = 150;
       static const int MAX_GRADE = 1;

       const std::string name;
       int grade;

   public:
      // === Constructor
      Bureaucrat(int grade, std::string name);
      Bureaucrat(const Bureaucrat& other);
      ~Bureaucrat();

    // === Methods
    void sumGrade();
    void subtractGrade();
    int getGrade() const;
    std::string getName() const;

    void signForm(AForm& form);
    void executeForm(AForm const & form) const;
    // === Operator =
    Bureaucrat& operator=(const Bureaucrat& other);
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat);


#endif //BUREAUCRAT_H
