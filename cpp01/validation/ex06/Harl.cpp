#include "Harl.hpp"

Harl::Harl(void)
{
}

Harl::~Harl()
{
}

void Harl::debug(void)
{
    std::cout << "[ DEBUG ]" << std::endl;
    std::cout << "love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger "<< std::endl;
    std::cout << "I really do!" << std::endl << std::endl;
}

void Harl::info(void)
{
    std::cout << "[ INFO ]" <<std::endl;
    std::cout << "I cannot believe adding extra bacon costs more money." << std::endl;
    std::cout << "You didn’t put enough bacon in my burger!"<< std::endl;
    std::cout << "If you did, I wouldn’t be asking for more!" << std::endl << std::endl;
}

void Harl::warning(void)
{
    std::cout << "[ WARNING ]" << std::endl;
    std::cout << "think I deserve to have some extra bacon for free." << std::endl;
    std::cout << "I’ve been coming for years whereas you started working here since last month." << std::endl << std::endl;
}

void Harl::error( void )
{
    std::cout << "[ ERROR ]" << std::endl;
    std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl << std::endl;
}

void Harl::others()
{
    std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
}

void Harl::complain( std::string level )
{
    Harl obj;
    void (Harl::*ptr[5])() = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error, &Harl::others};
    std::string lvls[5] = {"DEBUG", "INFO", "WARNING", "ERROR", "idc"};
    int ind = 0;
    for (size_t i = 0; i < 5; i++)
    {
        if (lvls[i] == level)
        {
            ind = i + 1;
            break;
        }
        if (i + 1 == 5) 
            ind = 5;
    }
    switch (ind)
    {
    case 1:
        (obj.*ptr[0])();
    case 2:
        (obj.*ptr[1])();
    case 3:
        (obj.*ptr[2])();
    case 4:
        (obj.*ptr[3])();
        break;
    default:
        (obj.*ptr[4])();
        break;
    }
}