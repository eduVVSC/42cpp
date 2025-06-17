
#include <iostream>
#include "Bureaucrat.hpp"


void creatingTest() {
  std::cout << "======================\n" << "Creating test." << std::endl;
  try {
    Bureaucrat *b4 = new Bureaucrat(5, "normal test2");
    std::cout << "b4 created: " << b4->getName() << " " << b4->getGrade() << std::endl;
    delete b4;
  } catch (const std::exception& e) {
    std::cout << e.what() << std::endl;
  }
  try {
    Bureaucrat *b3 = new Bureaucrat(150, "normal test1");
    std::cout << "b3 created: " << b3->getName() << " " << b3->getGrade() << std::endl;
    delete b3;
  } catch (const std::exception& e) {
    std::cout << e.what() << std::endl;
  }
  try {
    Bureaucrat *b1 = new Bureaucrat(151, "testGradeTooLowException");

    std::cout << "b1 created: " << b1->getName() << " " << b1->getGrade() << std::endl;
    delete b1;
  } catch (const GradeTooLowException & e) {
    std::cout << e.what() << std::endl;
  }

  try {
    Bureaucrat *b2 = new Bureaucrat(-2, "testGradeTooLowException");
    std::cout << "b2 created: " << b2->getName() << " " << b2->getGrade() << std::endl;
    delete b2;
  } catch (const GradeTooHighException & e) {
    std::cout << e.what() << std::endl;
  }
}

void operationsTest() {
    Bureaucrat *b1;
    Bureaucrat *b2;

    std::cout << "======================\n" << "Operations test." << std::endl;
  try {
    b1 = new Bureaucrat(150, "testGradeTooHighException");

    std::cout << "testing subtraction in " << b1->getName() << " " << b1->getGrade() << std::endl;

    b1->sumGrade();
    std::cout << "after add 1 in " << b1->getGrade() << std::endl;
    b1->subtractGrade();
    std::cout << "after sub 1 in " << b1->getGrade() << std::endl;
    b1->subtractGrade();
    std::cout << "after sub 2 in " << b1->getGrade() << std::endl;
    delete b1;
  } catch (std::exception & e) {
      std::cout << e.what() << std::endl;
      delete b1;
  }

  try {
    Bureaucrat *b2 = new Bureaucrat(1, "testGradeTooLowException");

    b2->subtractGrade();
    std::cout << "after 1 sub in " << b2->getGrade() << std::endl;
    b2->subtractGrade();
    std::cout << "after 2 sub in " << b2->getGrade() << std::endl;
    b2->sumGrade();
    std::cout << "after 1 add in " << b2->getGrade() << std::endl;
    delete b2;
  } catch (std::exception & e) {
    std::cout << e.what() << std::endl;
    delete b2;
  }
}


int main(void){
  creatingTest();
  operationsTest();
  return 0;
}
