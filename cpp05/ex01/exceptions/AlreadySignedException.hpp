//
// Created by edvieira on 6/17/25.
//

#ifndef CPP05_ALREADYSIGNEDEXCEPTION_H
# define CPP05_ALREADYSIGNEDEXCEPTION_H

# include <exception>
# include <string>

class AlreadySignedException : public std::exception {
private:
    std::string message;
public:
    // Constructor accepting const char*
    AlreadySignedException(const std::string& msg);

    // Override what() method, marked
    virtual const char* what() const throw();

    ~AlreadySignedException() throw();
};

#endif