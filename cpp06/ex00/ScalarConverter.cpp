//
// Created by edvieira on 6/19/25.
//

#include "ScalarConverter.hpp"

#include <float.h>
#include <math.h>

// =========== Utility functions =========== //

Pattern findPattern(std::string input) {
    bool hasDot = false;
    int manyChar = 0;

    for (size_t i  = 0; i < input.length(); i++) {
        char c = input.at(i);
        if (!((c >= '0' && c <= '9') || c == '-' || c == '+' || c == '.'))
            manyChar++;
        if (c == '.')
            hasDot = true;
    }


    if (manyChar > 0) { // inf inff - nan nanf - float -
        if (input.compare("nan") == 0 || input.compare("nanf") == 0)
            return NANS;
        if (manyChar == 1 && input.at(input.length()) == 'f')
            return FLOAT;
        return CHAR;
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

/**
 * Function will print and check for overflow in each of the types of variables
 * instead of double, this specific will be checked before print. It will only get here if it
 * hasn't already overflowed in the asked type
 * @param d var value it double
 * @param f var value it float
 * @param i var value it integer
 * @param c var value it char
 */
void print (double d, float f, int i, char c) {
    if (isNonDisplayable(static_cast<char>(c))) // printable char!
        std::cout << "char: Non displayable" << std::endl;
    else
        std::cout << "char: " <<  "\'" << c << "\'" << std::endl;

    if (d < INT_MIN || d > INT_MAX) // int overflow!
        std::cout << "int: impossible" << std::endl;
    else
        std::cout << "int: " << i << std::endl;

    if (d < FLT_MIN || d > FLT_MAX) // float overflow!
        std::cout << "float: impossible" << std::endl;
    else
        std::cout << "float: " << f << std::endl;

    std::cout << "double: " << d << std::endl;
}

void printOverflow() {
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
    std::cout << "float: impossible" << std::endl;
    std::cout << "double: impossible" << std::endl;
}

// =========== Converters =========== //

void charConverter(std::string input) {
    char c = input.at(0);

    int i = c; // cannot overflow
    double d = i; // cannot overflow
    float f = i; // cannot overflow
    print(d, f, i, c);
}

void intConverter(std::string input) {
    long long ll = strtoll(input.c_str(), NULL, 10);
    if (ll > INT_MAX || ll < INT_MIN)
        printOverflow();
    else {
        int i = static_cast<int>(ll);
        char c = static_cast<char>(i); // using static cast, because int has greater memory than the char

        double d = i; // cannot overflow
        float f = i; // cannot overflow
        print(d, f, i, c);
    }
}

void floatConverter(std::string input) {
    long long ll = strtoll(input.c_str(), NULL, 10);

    if (ll > FLT_MAX || ll < FLT_MIN)
        printOverflow();
    else {
        float f = static_cast<float>(ll);
        int i = static_cast<int>(f);
        char c = static_cast<char>(i);

        double d = f;
        print(d, f, i,c );
    }
}

void doubleConverter(std::string input) {
    long long ll = strtoll(input.c_str(), NULL, 10);
    if (ll > DBL_MAX || ll < DBL_MIN)
        printOverflow();
    else {
        double d = static_cast<double>(ll);
        float f = static_cast<float>(d);
        int i = static_cast<int>(d);
        char c = static_cast<char>(i);
        print(d, f, i,c );
    }
}

// to be done
void nanConverter(std::string input) {
    (void) input;
    std::cout << "char: impossible \nint: impossible \nfloat: nanf \ndouble: nan" << std::endl;
}

void infConverter(std::string input) {
    (void) input;
}

void ScalarConverter::convert(std::string input) {
    switch (findPattern(input)) {
        case INT:
            intConverter(input);
            break;
        case FLOAT:
            floatConverter(input);
            break;
        case DOUBLE:
            doubleConverter(input);
            break;
        case CHAR:
            charConverter(input);
            break;
        case NANS:
            nanConverter(input);
            break;
        case INF:
            infConverter(input);
            break;
        default:
            std::cout << "Invalid input" << std::endl;
    }
}