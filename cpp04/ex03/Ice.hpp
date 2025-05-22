//
// Created by edvieira on 5/22/25.
//

#ifndef ICE_H
# define ICE_H

# include "AMateria.hpp"
# include "ICharacter.hpp"

class Ice : public AMateria{
public:
    Ice();
    Ice(const Ice& other);
    AMateria* clone();

    void use(ICharacter& target) override;
    ~Ice();
};



#endif //ICE_H
