//
// Created by edvieira on 6/17/25.
//

#ifndef TYPENOTFOUND_HPP
# define TYPENOTFOUND_HPP

# include <string>
# include <exception>

class TypeNotFound  : public std::exception {
private:
    std::string message;
public:
    // Constructor accepting const char*
    TypeNotFound(const std::string& msg);

    // Override what() method, marked
    virtual const char* what() const throw();

    ~TypeNotFound() throw();
};


#endif
