

#include "Serializer.hpp"
#include <iostream>

int main(void) {
  Data a;
  a.n1 = 2;
  a.f1 = 3.1;
  a.d1 = 4.2;
  std::cout << a.n1 << a.d1 << a.f1 << std::endl;
  Serializer::serialize(&a);
  return 0;
}
