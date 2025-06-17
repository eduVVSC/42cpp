//
// Created by edvieira on 6/17/25.
//

#ifndef NOTSIGNEDEXCEPTION_HPP
# define NOTSIGNEDEXCEPTION_HPP

# include <exception>
# include <string>

class NotSignedException : public std::exception {
private:
    std::string message;
public:
    // Constructor accepting const char*
    NotSignedException(const std::string& msg);

    // Override what() method, marked
    virtual const char* what() const throw();

    ~NotSignedException() throw();
};

#endif