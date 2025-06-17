//
// Created by edvieira on 6/17/25.
//

#include "NotSignedException.hpp"

NotSignedException::NotSignedException(const std::string& msg){
    message = msg;
}

const char *NotSignedException::what() const throw(){
    return message.c_str();
}

NotSignedException::~NotSignedException() throw() {}
