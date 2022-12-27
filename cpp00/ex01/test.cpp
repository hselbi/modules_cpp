#include <iostream>
#include <stdlib.h>
// #include <string>
#include <stdio.h>
#include <string.h>

bool check_int(std::string num)
{
  for(long unsigned int i = 0; i < num.length(); i++)
  {
    if (!isdigit(num[i]))
      return (false);
  }
  return (true);
}

// int main() {
//   std::string k;
//   // int i = 0, j = 0;

//   while (1) {
//     // i++;
//     std::cin >> k;
//     if (!check_int(k))
//     {
//         // std::cin.clear();
//         // std::cin.ignore(256, '\n');
//         std::cout << "please put only digits " << std::endl;
//     }
//     else
//     {
//         std::cout << "Integer " << ": " << k << std::endl;
//         // break;
//     }
//   }
//   return (0);
// }


int main() {
  std::string v;
  while (true)
  {
    std::cout<<"Please enter some value: ";
    std::cin>>v;
    if((v.find_first_not_of("0123456789") == std::string::npos))
    {
      std::cout<<"The value "<<v<<" is Integer"<<std::endl;
      break ;
    }
    else
      std::cout<<"The value "<<v<<" is Not Integer"<<std::endl;

  }
}

// int main() {
//   int i, j = 0;

//   while (1) {
//     i++;
//     std::cin >> j;
//     if (std::cin.fail()) return 0;
//     std::cout << "Integer " << i << ": " << j << std::endl;  
//   }
// }
