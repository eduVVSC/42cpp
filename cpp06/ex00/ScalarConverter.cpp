//
// Created by edvieira on 6/19/25.
//

#include "ScalarConverter.hpp"

#include <float.h>
#include <math.h>

static void ScalarConverter::convert(std::string input) {
    switch (findPattern(input)) {
        case INT:
            intConverter(input);
            std::cout << input;
            break;
        case FLOAT:
            floatConverter(input);
            std::cout << input;
            break;
        case DOUBLE:
            doubleConverter(input);
            std::cout << input;
            break;
        case CHAR:
            charConverter(input);
            std::cout << input;
            break;
        case NAN:
            nanConverter(input);
            std::cout << input;
            break;
        case INF:
            infConverter(input);
            std::cout << input;
            break;
        default:
            std::cout << "Invalid input" << std::endl;
    }
}

// =========== Utility functions =========== //

Pattern findPattern(std::string input) {
    bool hasDot = false;
    int manyChar = 0;

    for (char c : input) {
        if (!((c >= '0' && c <= '9') || c == '-' || c == '+' || c == '.'))
            manyChar++;
        if (c == '.')
            hasDot = true;
    }

    if (manyChar > 0) { // inf inff - nan nanf - float -

    }
    else { // means that is going to be an int or a double
        if (hasDot)
            return DOUBLE;
        return INT;
    }
}

bool isNonDisplayable(int asciiValue) {
    if (asciiValue < 32 || asciiValue == 127)
        return true;
    return false;
}

void print (double d, float f, int i, char c) {
    std::string charString = c;
    std::string floatString = f;
    std::string intString = i;

    if (i == INT_MIN && (d < INT_MIN || d > INT_MAX)) // int overflow!
        std::string intString = "impossible";
    if (f == FLT_MIN && (d < FLT_MIN || d > FLT_MAX)) // float overflow!
        std::string floatString = "impossible";
    if (isNonDisplayable(static_cast<char>(c))) // printable char!
        charString = "impossible";

    std::cout << "char: " << charString << std::endl;
    std::cout << "int: " << intString << std::endl;
    std::cout << "float: " << floatString << std::endl;
    std::cout << "double: " << d << std::endl;
}

// =========== Converters =========== //

std::string charConverter(std::string input) {
    //non-displayable characters shouldn’t be used as inputs.If a conversion to char is not
    //displayable, print an informative message
}

std::string intConverter(std::string input) {
    int i = atoi(input.c_str());
    char c = static_cast<char>(i);
    print(d, f, i, c);
}

std::string floatConverter(std::string input) {
    float f = atof(input.c_str());
    int i = static_cast<int>(f);
    char c = static_cast<char>(i);
    print(d, f, i,c );
}

std::string doubleConverter(std::string input) {
    double d = atof(input.c_str());
    float f = static_cast<double>(d);
    int i = static_cast<int>(d);
    char c = static_cast<char>(i);
    print(d, f, i,c );
}


// to be done
std::string nanConverter(std::string input) {
    std::cout << "char: impossible \nint: impossible \nfloat: nanf \ndouble: nan" << std::endl;
}

std::string infConverter(std::string input) {
}

