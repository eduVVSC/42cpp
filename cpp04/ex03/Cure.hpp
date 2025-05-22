//
// Created by edvieira on 5/22/25.
//

#ifndef CURE_H
# define CURE_H


# include "AMateria.hpp"

class Cure : public AMateria {
public:
    Cure();
    Cure(const Cure& other);
    AMateria* clone();

    void use(ICharacter& target) override;
    ~Cure();
};

#endif //CURE_H
