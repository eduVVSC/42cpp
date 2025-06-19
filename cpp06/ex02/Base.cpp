//
// Created by edvieira on 6/19/25.
//

# include "Base.hpp"

# include "A.hpp"
# include "B.hpp"
# include "C.hpp"
# include <utime.h>

#include <iostream>
#include <unistd.h>

Base::Base() {
    fstGenerated = false;
}

Base *Base::generate() {
    Base *p;
    int min = 1;
    int max = 3;

    if (fstGenerated == false) {
        srand(time(0));
        fstGenerated = true;
    }

    int random_number = min + (rand() % (max - min + 1));

    switch (random_number) {
        case 1:
            std::cout << "🇦 class generated" << std::endl;
            p = new A();
            break;
        case 2:
            std::cout << "🇧 class generated" << std::endl;
            p = new B(  );
            break;
        default:
            std::cout << "🇨 class generated" << std::endl;
            p = new C();
            break;
    }
    return p;
}

void Base::identify(Base *p) {
    if (typeid(*p) == typeid(A)) {
        std::cout << " -> Class is of type 🇦" << std::endl;
    }
    else if (typeid(*p) == typeid(B)) {
        std::cout << " -> Class is of type 🇧" << std::endl;
    }
    else if (typeid(*p) == typeid(C)) {
        std::cout << " -> Class is of type 🇨" << std::endl;
    }
}

void Base::identify(Base &p) {
    if (typeid(p) == typeid(A)) {
        std::cout << " -> Class is of type 🇦" << std::endl;
    }
    else if (typeid(p) == typeid(B)) {
        std::cout << " -> Class is of type 🇧" << std::endl;
    }
    else if (typeid(p) == typeid(C)) {
        std::cout << " -> Class is of type 🇨" << std::endl;
    }
}

Base::~Base() {
}