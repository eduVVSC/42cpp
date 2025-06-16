//
// Created by edvieira on 6/16/25.
//

#ifndef GRADETOOHIGHEXCEPTION_H
# define GRADETOOHIGHEXCEPTION_H

# include <string>
# include <exception>


class GradeTooHighException : public std::exception {
private:
    std::string message;
public:
    // Constructor accepting const char*
    GradeTooHighException(const std::string& msg);

    // Override what() method, marked
    virtual const char* what() const throw();

    virtual ~GradeTooHighException() throw();
};


#endif //GRADETOOHIGHEXCEPTION_H
