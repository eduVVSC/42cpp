//
// Created by edvieira on 5/22/25.
//

#ifndef AMATERIA_H
# define AMATERIA_H

# include <string>
# include <iostream>
# include "ICharacter.hpp"


class AMateria
{
    protected:
        std::string type;

    public:
        virtual AMateria* clone() const = 0;

        virtual void use(ICharacter& target);

        std::string const & getType() const;   //Returns the materia type

        AMateria&operator=(const AMateria &other);

        AMateria(std::string const & type);

        virtual ~AMateria();
};



#endif
