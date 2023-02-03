#include <iostream>
#include <limits>

using namespace std;

template<typename T>
void showMinMax() {
   cout << "min: " << numeric_limits<T>::min() << endl;
   cout << "max: " << numeric_limits<T>::max() << endl;
   cout << endl;
}

double stringToDouble(const std::string& _in)
{
    double _val;
    char *ptr = NULL;
    _val = std::strtod(_in.c_str(), &ptr);

    return (_val);
}

int main() {



    std::cout << "52.22 ==> " << stringToDouble("52.22") << std::endl;
//    cout << "short:" << endl;
//    showMinMax<short>();
//    cout << "int:" << endl;
//    showMinMax<int>();
//    cout << "long:" << endl;
//    showMinMax<long>();
//    cout << "float:" << endl;
//    showMinMax<float>();
//    cout << "double:" << endl;
//    showMinMax<double>();
//    cout << "long double:" << endl;
//    showMinMax<long double>();
//    cout << "unsigned short:" << endl;
//    showMinMax<unsigned short>();
//    cout << "unsigned int:" << endl;
//    showMinMax<unsigned int>();
//    cout << "unsigned long:" << endl;
//    showMinMax<unsigned long>();
}