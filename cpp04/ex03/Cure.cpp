//
// Created by edvieira on 5/22/25.
//

#include "AMateria.hpp"
#include "Cure.hpp"

AMateria *Cure::clone() {
    AMateria temp = new Cure();
    return temp;
}

void Cure::use(ICharacter &target) {
    std::cout << "* heals " << target.getName() << "’s wounds *" << std::endl;
}

Cure::Cure() : AMateria() {
    this->type = "cure";
}

Cure::Cure(const Cure &other) : AMateria(){
    this->type = other.type;
}

Cure::~Cure() {

}



