#include <iostream>
#include "matho.hpp"

int main()
{
  matho tet;
  auto ref = tet.sumo(5, 3);
  std::cout << "Hello world\n";
  std::cout << "ref: " << ref << std::endl;
}