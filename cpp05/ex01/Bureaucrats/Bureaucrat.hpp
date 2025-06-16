//
// Created by edvieira on 6/16/25.
//

#ifndef BUREAUCRAT_H
# define BUREAUCRAT_H

# include <string>
# include <iostream>
# include "../Forms/Form.hpp"

# include "../exceptions/GradeTooHighException.hpp"
# include "../exceptions/GradeTooLowException.hpp"

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

      void signForm(Form form);

      // === Operator =
      Bureaucrat& operator=(const Bureaucrat& other);
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat);


#endif //BUREAUCRAT_H
