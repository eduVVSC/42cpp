//
// Created by edvieira on 6/19/25.
//

#include "Serializer.hpp"

static Data*  Serializer::deserialize(uintptr_t raw) {
    return reinterpret_cast<Data*>(raw);
}

static uintptr_t Serializer::serialize(Data* ptr){
    return reinterpret_cast<uintptr_t>(ptr);
}