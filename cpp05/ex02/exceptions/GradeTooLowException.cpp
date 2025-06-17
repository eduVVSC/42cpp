//
// Created by edvieira on 6/16/25.
//

#include "GradeTooLowException.hpp"

GradeTooLowException::GradeTooLowException(const std::string& msg){
    message = msg;
}

const char *GradeTooLowException::what() const throw(){
  return message.c_str();
}

GradeTooLowException::~GradeTooLowException() throw() {}
