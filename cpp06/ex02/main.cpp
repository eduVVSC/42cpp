

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>

Base *generate() {
    static bool frst = true;
    Base *p;
    int min = 1;
    int max = 3;

    if (frst)
    {
        srand(time(0));
        frst = false;
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

void identify(Base *p) {
    if (dynamic_cast<A *>(p)) 
        std::cout << " -> Class is of type 🇦" << std::endl;
    else if (dynamic_cast<B *>(p)) 
        std::cout << " -> Class is of type 🇧" << std::endl;
    else if (dynamic_cast<C*>(p)) 
        std::cout << " -> Class is of type 🇨" << std::endl;
    else 
        std::cout << "Cannot identify a NULL pointer" << std::endl;
}

void identify(Base &p) {
    void *fu = NULL;
    Base &ck = (Base &)fu;
    try { ck = dynamic_cast<A &>(p); std::cout << " -> Class is of type 🇦" << std::endl; }     catch(const std::exception& e) {  }
    try { ck = dynamic_cast<B &>(p); std::cout << " -> Class is of type 🇧" << std::endl; }     catch(const std::exception& e) {  }
    try { ck = dynamic_cast<C &>(p); std::cout << " -> Class is of type 🇨" << std::endl; }     catch(const std::exception& e) {  }            
        
}


int main(void) {
    Base *baseBoss = new Base();

    Base *t1 = generate();
    Base *t2 = generate();
    Base *t3 = generate();

    std::cout << "««««««««««««««««««««««««««" << std::endl;

    identify(t1);
    identify(&(*t2));
    identify(&(*t3));
    identify(NULL);

    delete t1;
    delete t2;
    delete t3;
    delete baseBoss;
}
