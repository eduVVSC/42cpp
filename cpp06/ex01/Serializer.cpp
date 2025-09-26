//
// Created by edvieira on 6/19/25.
//

#include "Serializer.hpp"

Data*  Serializer::deserialize(uintptr_t raw) {
    return reinterpret_cast<Data*>(raw);
}

uintptr_t Serializer::serialize(Data* ptr){
    return reinterpret_cast<uintptr_t>(ptr);
}