#include <iostream>
#include <string>

int main()
{
  std::string name;
  while (std::getline(std::cin, name))
  {
    if (!name.compare("ADD"))
    {
      std::cout << "here i am adding" << std::endl;
    }
    else if (!name.compare("SEARCH"))
    {
      std::cout << "here i am in searching" << std::endl;
    }
    else if (!name.compare("EXIT"))
    {
      std::cout << "here i am in exit" << std::endl;
      exit(0);
    }
  }
  
  
  return 0;
}

