#include <iostream>
#include <string>
// using namespace std;

// class person {
// private:
//     string name;
//     int age;

// public:
//     // default constructor
//     person()
//     {
//         name = "N/A";
//         age = 0;
//     }

//     // parameterized constructor with 
//     // default argument
//     person(string name, int age = 18)
//     {
//         this->name = name;
//         this->age = age;
//     }

//     // function to display values
//     void display()
//     {
//         cout << name << "\t" << age << endl;
//     }
// };

// int main()
// {
//     //array of class objects declaration
//     person per[4] = { person("ABC"), person("PQR"), person("XYZ", 30), person() };

//     per[0].display();
//     per[1].display();
//     per[2].display();
//     per[3].display();

//     return 0;
// }


class book
{
public:
  std::string name;
  std::string lname; 
  void print()
  {
    std::cout << "name ==>" << name << std::endl;
    std::cout << "last name ==>" << lname << std::endl;
  }
  book()
  {
    name = "nothing";
    lname = "last nothing";
  }
   book()
  {
    name = "nothing";
    lname = "last nothing";
  }
};

int main()
{
  book sq[3];
  for (int i = 0; i < 3; i++)
  {
    sq[i].print();
  }
  
  return 0;
}

