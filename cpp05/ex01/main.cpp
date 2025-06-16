
#include <iostream>
#include "Bureaucrats/Bureaucrat.hpp"
#include "Forms/Form.hpp"

void correctTest(Bureaucrat *b1) {
    std::cout << "=============== Tests supposed to work ==============="<< std::endl;
    try {
        Form *f1 = new Form("form1", 100, 5);
        Form *f2 = new Form("form2", 5, 5);

        b1->signForm(*f1);
        b1->signForm(*f2);
    } catch (const std::exception &e) {
      std::cout << e.what() << std::endl;
    }
}


void wrongTest(Bureaucrat * b1) {
    std::cout << "=============== Tests not supposed to work ==============="<< std::endl;
  try {
    Form *f1 = new Form("form2", 1, 5);

    b1->signForm(*f1);
  } catch (const std::exception &e) {
    std::cout << e.what() << std::endl;
  }
}

int main(void){
  try {

    Bureaucrat *b1 = new Bureaucrat(5, "b1");

    std::cout << "b1 created: " << *b1 << std::endl;

    correctTest(b1);
    wrongTest(b1);
  } catch (const std::exception& e) {
    std::cout << e.what() << std::endl;
  }
  return 0;
}
