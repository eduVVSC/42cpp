//
// Created by edvieira on 5/22/25.
//

#include "AMateria.hpp"

std::string const &AMateria::getType() const {

}

void AMateria::use(ICharacter &target) {

}

AMateria::AMateria(std::string const &type) {
    this->type = type;
}

AMateria &AMateria::operator=(AMateria const &other) {
    return *this;
}

AMateria::~AMateria() {

}


