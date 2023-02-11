#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(): type_("Unknown_type")
{
    std::cout << "[ WrongAnimal: Default Constructor Called ]";
}

WrongAnimal::~WrongAnimal()
{
    std::cout << "[ WrongAnimal: Deconstructor Called!! ]";
}