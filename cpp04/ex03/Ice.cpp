//
// Created by edvieira on 5/22/25.
//

#include "Ice.hpp"

AMateria *Ice::clone() {
    AMateria *temp = new Ice();
    return temp;
}


void Ice::use(ICharacter &target) {
    std::cout << "* shoots an ice bolt at " << target.getName() << "*" << std::endl;
}


// --------- Constructor and destructor

Ice::Ice() : AMateria(){
    std::cout << "🧊 Ice constructor" << std::endl;
    this->type = "ice";
}

Ice::Ice(const Ice &other) : AMateria() {
    std::cout << "🧊 Ice constructor" << std::endl;
    this->type = other.type;
}

Ice::~Ice() {
    std::cout << "🧊 Ice destructor" << std::endl;
}



