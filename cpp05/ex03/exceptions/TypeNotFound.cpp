//
// Created by edvieira on 6/17/25.
//

#include "TypeNotFound.hpp"

TypeNotFound::TypeNotFound(const std::string& msg){
    message = msg;
}

const char *TypeNotFound::what() const throw(){
    return message.c_str();
}

TypeNotFound::~TypeNotFound() throw() {}
