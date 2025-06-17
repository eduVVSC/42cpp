//
// Created by edvieira on 6/17/25.
//

#include "AlreadySignedException.hpp"

AlreadySignedException::AlreadySignedException(const std::string& msg){
    message = msg;
}

const char *AlreadySignedException::what() const throw(){
    return message.c_str();
}

AlreadySignedException::~AlreadySignedException() throw() {}
