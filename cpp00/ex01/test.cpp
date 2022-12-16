#include <iostream>
#include <stdlib.h>
// #include <string>
#include <stdio.h>
#include <string.h>

int main() {
  int i = 0, j = 0;

  while (1) {
    i++;
    std::cin >> j;
    if (std::cin.fail())
    {
        std::cin.clear();
        std::cin.ignore(256, '\n');
        std::cout << "please put only digits " << std::endl;
    }
    else
    {
        std::cout << "Integer " << ": " << j << std::endl;
        break;
    }
  }
  return (0);
}