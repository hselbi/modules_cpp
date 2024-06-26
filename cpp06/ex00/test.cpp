#include <cmath>
#include <cstdlib>
#include <limits>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>
#include <cstring>

#define C_ND              "Non displayable"
#define C_NP              "impossible"

class Convert {
 private:
  bool _e;
  const std::string _input;
  const double _value;

  Convert(void);

 public:
  char toChar(void) const;
  int toInt(void) const;
  float toFloat(void) const;
  double toDouble(void) const;

  bool getError(void) const;
  const double& getValue(void) const;
  const std::string& getInput(void) const;

  Convert& operator=(const Convert& c);
  explicit Convert(const std::string input);
  Convert(const Convert& c);
  ~Convert(void);
};

#include <cctype>

char Convert::toChar(void) const {
  return static_cast<char>(_value);
}

int Convert::toInt(void) const {
  return static_cast<int>(_value);
}

float Convert::toFloat(void) const {
  return static_cast<float>(_value);
}

double Convert::toDouble(void) const {
  return static_cast<double>(_value);
}

bool Convert::getError(void) const {
  return _e;
}

const double& Convert::getValue(void) const {
  return _value;
}

const std::string& Convert::getInput(void) const {
  return _input;
}

Convert& Convert::operator=(const Convert& c) {
  if (this != &c) {
    _e = c.getError();
    *(const_cast<std::string*>(&_input)) = c.getInput();
    *(const_cast<double*>(&_value)) = c.getValue();
  }
return *this;
}

Convert::Convert(void)
  : _e(false), _input(""), _value(0.0) {}

Convert::Convert(const std::string input)
  : _e(false), _input(input), _value(0.0) {
    std::cout << "this is a in " << _input << std::endl;
    std::cout << "this is a val " << _value << std::endl;
    std::cout << "this is a err " << _e << std::endl;
  try {
    char *ptr = NULL;
    *(const_cast<double*>(&_value)) = std::strtod(_input.c_str(), &ptr);
    std::cout << "this is a in " << _input << std::endl;
    std::cout << "this is a val " << _value << std::endl;
    if (_value == 0.0 &&
        (_input[0] != '-' &&
         _input[0] != '+' &&
         !std::isdigit(_input[0])))
      throw std::bad_alloc();
    if (*ptr && std::strcmp(ptr, "f"))
      throw std::bad_alloc();
  } catch (std::exception&) {
    _e = true;
  }
}

Convert::Convert(const Convert& c)
  : _e(false), _input(c.getInput()), _value(c.getValue()) {}

Convert::~Convert(void) {}

static void printToChar(std::ostream& o, const Convert& c) {
  o << "char: ";
  if (std::isnan(c.getValue()) || std::isinf(c.getValue())) {
    o << C_NP << std::endl;
  } else if (std::isprint(c.toChar())) {
    o << "'" << c.toChar() << "'" << std::endl;
  } else {
    o << C_ND << std::endl;
  }
}

static void printToInt(std::ostream& o, const Convert& c) {
  o << "int: ";
  if (std::isnan(c.getValue()) || std::isinf(c.getValue())) {
    o << C_NP << std::endl;
  } else {
    o << c.toInt() << std::endl;
  }
}

static void printToReal(std::ostream& o, const Convert& c) 
{
    std::cout << c.getValue() << std::endl;
    std::cout << std::isinf(c.getValue()) << std::endl;
    std::cout << c.toFloat() << std::endl;
    std::cout << static_cast<int64_t>(c.toFloat()) << std::endl;
    std::cout << std::setprecision(std::numeric_limits<float>::digits10)
      << c.toFloat() << std::endl;
  if (std::isnan(c.getValue()) || std::isinf(c.getValue())) {
    o << "float: " << std::showpos << c.toFloat() << "f" << std::endl;
    o << "double: " << std::showpos << c.toDouble() << std::endl;
    return;
  }
  if (c.toFloat() == static_cast<int64_t>(c.toFloat())) {
    o << "float: " << c.toFloat() << ".0f" << std::endl;
  } else {
    o << "float: " << std::setprecision(std::numeric_limits<float>::digits10)
      << c.toFloat() << "f" << std::endl;
  }
  if (c.toDouble() == static_cast<int64_t>(c.toDouble())) {
    o << "double: " << c.toDouble() << ".0" << std::endl;
  } else {
    o << "double: " << std::setprecision(std::numeric_limits<double>::digits10)
      << c.toDouble() << std::endl;
  }
}

std::ostream& operator<<(std::ostream& o, const Convert& c) {
  if (c.getError()) {
    o << "Converting Failed (Bad Alloc)" << std::endl;
    return o;
  }
  printToChar(o, c);
  printToInt(o, c);
  printToReal(o, c);
  return o;
}


int main(int argc, char **argv) {
  if (argc != 2) {
    std::cout << "Command Not Formatted Well" << std::endl
      << "./convert [ Convert Input ]" << std::endl;
  } else {
    std::cout << Convert(argv[1]);
  }
  return 0;
}
