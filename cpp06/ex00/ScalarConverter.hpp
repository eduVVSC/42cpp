//
// Created by edvieira on 6/19/25.
//

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <string>
# include <iostream>
# include <limits.h>

enum Pattern {
    INT,
    CHAR,
    FLOAT,
    DOUBLE,
    NANS,
    INF,
};

class ScalarConverter {
private:

public:
    static void convert(std::string input);
};


#endif
