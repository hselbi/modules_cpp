#include <iostream>

// #include <iostream>

// int main() {
//     int a = 10;
//     double* p = reinterpret_cast<double*>(&a); // reinterpret a as a double pointer

//     std::cout << "a = " << a << std::endl;
//     std::cout << "*p = " << *p << std::endl;

//     return 0;
// }


// int main()
// {
//     double b = 432.554;
//     int a = static_cast<int>(b);
//     std::cout << "this is original: " << b << std::endl;
//     std::cout << "this is after: " << a << std::endl;
// }


// int main()
// {
//     int a = 169;
//     double* b = reinterpret_cast<double*>(&a);
//     std::cout << "a: " << a << std::endl;
//     std::cout << "*b: " << *b << std::endl;

// }

// #include <iostream>
// using namespace std;

// class Base {
// public:
//     virtual void print() {
//         cout << "This is a base class." << endl;
//     }
// };

// class Derived : public Base {
// public:
//     void print() {
//         cout << "This is a derived class." << endl;
//     }
// };

// int main() {
//     Base* b = new Base();
//     Derived* d = dynamic_cast<Derived*>(b);

//     if (d == nullptr) {
//         cout << "Dynamic cast failed." << endl;
//     } else {
//         d->print();
//     }

//     delete b;
//     return 0;
// }


#include <iostream>

#include <cstdlib>

#include <string> 
#include <cctype> // for isdigit()
#include <iostream>
// #include <string>
#include <sstream>

bool isNumeric(std::string str) {
    std::istringstream iss(str);
    double d;
    double f;
    char c;
    iss >> f;
    iss >> c;
    std::cout << "==> float: " << f << std::endl;
    std::cout << "==> double: " << d << std::endl;
    std::cout << "==> char: " << c << std::endl;
    if (!(iss >> f) || (iss >> c)) {
        return false;
    }
    return true;
}

int main() {
    std::string str1 = "123.0f";
    std::string str2 = "3.14";
    std::string str3 = "1.23e-4";
    std::string str4 = "abc123";
    
    std::cout << std::boolalpha;
    std::cout << isNumeric(str1) << std::endl; // true
    // std::cout << isNumeric(str2) << std::endl; // true
    // std::cout << isNumeric(str3) << std::endl; // true
    // std::cout << isNumeric(str4) << std::endl; // false
    return 0;
}