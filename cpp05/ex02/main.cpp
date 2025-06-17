
#include <iostream>
#include "Bureaucrats/Bureaucrat.hpp"
#include "Forms/PresidentialPardonForm.hpp"
#include "Forms/RobotomyRequestForm.hpp"
#include "Forms/ShrubberyCreationForm.hpp"

void testWork(Bureaucrat * b1, PresidentialPardonForm * f1) {
    std::cout << "=============== Test Work ==============="<< std::endl;
  try {

      b1->executeForm(*f1);
  } catch (const std::exception &e) {
    std::cout << e.what() << std::endl;
  }
}

void testNotSigned(Bureaucrat * b1, PresidentialPardonForm * f1) {
    std::cout << "=============== Test NotSigned ==============="<< std::endl;
    try {

        b1->executeForm(*f1);
    } catch (const std::exception &e) {
        std::cout << e.what() << std::endl;
    }
}

void testNotEnoughGrade(Bureaucrat * b1, PresidentialPardonForm * f1) {
    std::cout << "=============== Test NotEnoughGrade ==============="<< std::endl;
    try {

        b1->executeForm(*f1);
    } catch (const std::exception &e) {
        std::cout << e.what() << std::endl;
    }
}


int main(void){
  try {
    Bureaucrat *b1 = new Bureaucrat(5, "b1");
    Bureaucrat *b2 = new Bureaucrat(140, "b2");

    PresidentialPardonForm *f1 = new PresidentialPardonForm("target 1");

      testNotSigned(b1, f1);

      b1->signForm(*f1);

      testNotEnoughGrade(b2, f1);
      testWork(b1, f1);
  } catch (const std::exception& e) {
    std::cout << e.what() << std::endl;
  }
  return 0;
}
