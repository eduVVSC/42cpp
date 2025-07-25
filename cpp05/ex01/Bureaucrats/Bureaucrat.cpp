//
// Created by edvieira on 6/16/25.
//

#include "Bureaucrat.hpp"

// ====== functions

void Bureaucrat::signForm(Form &form){
  try {
      form.beSign(this->getGrade());
      std::cout << "Bureaucrat " <<  this->getName() << " signed form "
                << form.getName() << std::endl;
  } catch (std::exception& e) {;
      std::cout << "Bureaucrat " <<  this->getName() << " couldn't sign form "
              << form.getName() << " because " << e.what() << std::endl;
  }
}

void Bureaucrat::sumGrade(){
  if ((grade - 1) > MAX_GRADE){
    grade--;
  }
  else {
    std::cout << "Grade exceeded the max grade." << std::endl;
    throw GradeTooHighException("Grade too High!");
  }
}

void Bureaucrat::subtractGrade(){
  if ((grade + 1) < MIN_GRADE){
    grade++;
  }
  else {
     std::cout << "Grade less than minimum grade" << std::endl;
     throw GradeTooLowException("Grade too Low!");
  }
}

int Bureaucrat::getGrade() const{ return grade; }

std::string Bureaucrat::getName() const{ return name; }

// ====== constructor and destructors

Bureaucrat::Bureaucrat(int grade, std::string name) : name(name) {
  if (grade < MAX_GRADE)
    throw GradeTooHighException("Grade too High!");
  if (grade > MIN_GRADE)
    throw GradeTooLowException("Grade too Low!");

  this->grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : name(other.getName()) {
  // no need to protect becuase it will be protected in the other bureaucrat
  this->grade = other.getGrade();
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat) {
    os << bureaucrat.getName() << " has " << bureaucrat.getGrade() << " grade" << std::endl;
    return os;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
  other.getName() = this->getName();
    return *this;
}

Bureaucrat::~Bureaucrat(){}