//
// Created by edvieira on 6/19/25.
//

#ifndef BASE_HPP
# define BASE_HPP

# include <cstdlib>
# include <ctime>
# include <typeinfo>

class Base {
private:
    bool fstGenerated;
public:
    Base();
    Base *generate(void);
    void identify(Base* p);
    void identify(Base& p);

    virtual ~Base();
};

#endif