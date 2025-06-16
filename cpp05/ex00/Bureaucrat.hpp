//
// Created by edvieira on 6/16/25.
//

#ifndef BUREAUCRAT_H
# define BUREAUCRAT_H

# include <string>
# include <iostream>
# include "exceptions/GradeTooHighException.hpp"
# include "exceptions/GradeTooLowException.hpp"

class Bureaucrat {
    private:
       static const int minGrade = 150;
       static const int maxGrade = 1;

       int grade;
       std::string name;
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

      // === Operator =
      Bureaucrat& operator=(const Bureaucrat& other);
};



#endif //BUREAUCRAT_H
