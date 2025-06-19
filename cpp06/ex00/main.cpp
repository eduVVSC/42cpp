

#include <cmath>
#include <cstdlib>

#include <iostream>
#include <stdlib.h>

bool isNonDisplayable(int asciiValue) {
  if (asciiValue < 32 || asciiValue == 127)
    return true;
  return false;
}

int main(int ac, char **av){
  if (ac > 1) {
    double d = atof(av[1]);
    int i = static_cast<int>(d);
    char c = static_cast<double>(round(d));
    std::cout << d << "| - |" << i << "| - |" << c << std::endl;
    //ScalarConverter::convert(av[1]);
  }
  return 0;
}
