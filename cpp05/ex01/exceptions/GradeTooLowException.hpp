//
// Created by edvieira on 6/16/25.
//

#ifndef GRADETOOLOWEXCEPTION_H
# define GRADETOOLOWEXCEPTION_H


# include <string>
# include <exception>


class GradeTooLowException : public std::exception {
private:
    std::string message;
public:
    // Constructor accepting const char*
    GradeTooLowException(const std::string& msg);

    // Override what() method, marked
    virtual const char* what() const throw();

    ~GradeTooLowException() throw();
};



#endif //GRADETOOLOWEXCEPTION_H
