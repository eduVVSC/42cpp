//
// Created by edvieira on 6/19/25.
//

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <string>

class Data {
private:
    int n1;
    char c1;
    float f1;
    double d1;
public:
    int getInt();
    char getChar();
    float getFloat();
    double getDouble();

    Data(int n, char c, float f, double d);
    ~Data();
};


class Serializer {
private:
    const std::string filename = "./data";
public:
    static Data* deserialize(uintptr_t raw);
    static uintptr_t serialize(Data* ptr);
};



#endif
