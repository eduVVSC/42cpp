
#include <iostream>
#include "Bureaucrats/Bureaucrat.hpp"
#include "Forms/PresidentialPardonForm.hpp"
#include "Forms/RobotomyRequestForm.hpp"
#include "Forms/ShrubberyCreationForm.hpp"

void testWork(Bureaucrat * b1, AForm * f1) {
    std::cout << "=============== Test Work ==============="<< std::endl;
    b1->executeForm(*f1);
}

void testNotSigned(Bureaucrat * b1, AForm * f1) {
    std::cout << "=============== Test NotSigned ==============="<< std::endl;
    b1->executeForm(*f1);
}

void testNotEnoughGrade(Bureaucrat * b1, AForm * f1) {
    std::cout << "=============== Test NotEnoughGrade ==============="<< std::endl;
    b1->executeForm(*f1);
}


int main(void){
  try {
    Bureaucrat *b1 = new Bureaucrat(5, "b1");
    Bureaucrat *b2 = new Bureaucrat(140, "b2");

    PresidentialPardonForm *f1 = new PresidentialPardonForm("target 1");

      testNotSigned(b1, f1);
      std::cout << "====> Signing"<< std::endl;
      b1->signForm(*f1);
      testNotEnoughGrade(b2, f1);
      testWork(b1, f1);

      delete b1;
      delete b2;
      delete f1;
  } catch (const std::exception& e) {
    std::cout << e.what() << std::endl;
  }
  return 0;
}
