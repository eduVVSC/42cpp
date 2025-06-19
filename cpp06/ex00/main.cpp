

#include <cmath>
#include <cstdlib>

#include "ScalarConverter.hpp"

#include <iostream>

int main(int ac, char **av){
  if (ac > 1) {
    ScalarConverter::convert(av[1]);
  }
  return 0;
}
