

#include "Base.hpp"
#include <iostream>

int main(void) {
    Base *baseBoss = new Base();

    Base *t1 = baseBoss->generate();
    Base *t2 = baseBoss->generate();
    Base *t3 = baseBoss->generate();
    Base *t4 = baseBoss->generate();

    std::cout << "««««««««««««««««««««««««««" << std::endl;

    t1->identify(t1);
    t2->identify(t2);
    t3->identify(t3);
    t4->identify(t4);

    delete t1;
    delete t2;
    delete t3;
    delete t4;
    delete baseBoss;
}
