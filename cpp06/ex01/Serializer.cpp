//
// Created by edvieira on 6/19/25.
//

#include "Serializer.hpp"

#include <cstdint>


void serialize(const string& filename)
{
    ofstream file(filename, ios::binary);
    if (!file.is_open()) {
        cerr
            << "Error: Failed to open file for writing."
            << endl;
        return;
    }
    file.write(reinterpret_cast<const char*>(this),
               sizeof(*this));
    file.close();
    cout << "Object serialized successfully." << endl;
}

static Serializable deserialize(const string& filename)
{
    Serializable obj("", 0);
    ifstream file(filename, ios::binary);
    if (!file.is_open()) {
        cerr
            << "Error: Failed to open file for reading."
            << endl;
        return obj;
    }
    file.read(reinterpret_cast<char*>(&obj),
              sizeof(obj));
    file.close();
    cout << "Object deserialized successfully." << endl;
    return obj;
}

static Data*  Data::deserialize(uintptr_t raw) {

    return reinterpret_cast<uintptr_t>(ptr);
}

static uintptr_t  Data::serialize(Data* ptr){

    return reinterpret_cast<Data*>(raw);
}

int Data::getInt() {
    return n1;
}

char Data::getChar() {
    return c1;
}

float Data::getFloat() {
    return f1;
}

double Data::getDouble() {
    return d1;
}

Data::Data(int n, char c, float f, double d) {
    n1 = n;
    c1 = c;
    f1 = f;
    d1 = d;
}

Data::~Data() {
}
