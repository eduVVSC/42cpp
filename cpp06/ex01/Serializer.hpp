//
// Created by edvieira on 6/19/25.
//

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <string>
# include <fstream>
# include <iostream>
# include <exception>
# include <stdint.h>

# include "Data.hpp"

class Serializer {
public:
    static Data* deserialize(uintptr_t raw);
    static uintptr_t serialize(Data* ptr);
};



#endif
