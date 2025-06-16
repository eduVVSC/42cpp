//
// Created by edvieira on 6/16/25.
//

#include "Bureaucrat.hpp"

// ====== functions
void Bureaucrat::sumGrade(){
  if ((grade - 1) > maxGrade){
    grade--;
  }
  else {
    std::cout << "Grade exceeded the max grade." << std::endl;
    throw GradeTooHighException("Grade too High!");
  }
}

void Bureaucrat::subtractGrade(){
  if ((grade + 1) < minGrade){
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

Bureaucrat::Bureaucrat(int grade, std::string name){
  if (grade < maxGrade)
    throw GradeTooHighException("Grade too High!");
  if (grade > minGrade)
    throw GradeTooLowException("Grade too Low!");

  this->grade = grade;
  this->name = name;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other){
  // no need to protect becuase it will be protected in the other bureaucrat
  this->grade = other.grade;
  this->name = other.name;
}

Bureaucrat::~Bureaucrat(){}