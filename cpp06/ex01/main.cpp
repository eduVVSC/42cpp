

#include "Serializer.hpp"
#include <iostream>

int main(void) {
  Data a;
  a.n1 = 2; a.f1 = 3.1;  a.d1 = 4.2;

  std::cout << "a = "<< a.n1 << a.d1 << a.f1 << std::endl;
  uintptr_t res = Serializer::serialize(&a);
  Data *b = Serializer::deserialize(res);
  std::cout << "b = "<< b->n1 << b->d1 << b->f1 << std::endl;
  return 0;
}
