#include "Animal.hpp"

Animal::Animal():_type("Unknown")
{
    std::cout << "[ Animal: Constructor is called ]" << std::endl;
    memo_ = new std::string("Unknown");
}

Animal::Animal(const Animal &target)
{
    this->_type = target._type;
}

Animal &Animal::operator=(const Animal &target)
{
    if (this != &target)
    {
        this->_type = target._type;
    }
    return (*this);
}

std::string Animal::getType()
{
    return (this->_type);
}

Animal::~Animal()
{
    std::cout << "[ Destructor from Animal ]" << std::endl;
}

