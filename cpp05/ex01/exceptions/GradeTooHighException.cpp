//
// Created by edvieira on 6/16/25.
//

#include "GradeTooHighException.hpp"

GradeTooHighException::GradeTooHighException(const std::string& msg){
  this->message = msg;
}

const char *GradeTooHighException::what() const throw(){
  return message.c_str();
}

GradeTooHighException::~GradeTooHighException() throw() {}


