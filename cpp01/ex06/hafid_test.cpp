#include <iostream>

class Harl
{
    private:
        void debug(void);
        void info(void);
        void warning(void);
        void error(void);
        void others(void);
    public:
        Harl();
        ~Harl();
        void complain( std::string level);
};

Harl::Harl() {}

Harl::~Harl() {}


void Harl::debug()
{
    std::cout << "[ DEBUG ]" << std::endl;
    std::cout << "love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger." << std::endl;
    std::cout << "I really do!" << std::endl << std::endl;
}

void Harl::info()
{
    std::cout << "[ INFO ]" << std::endl;
    std::cout << "I cannot believe adding extra bacon costs more money." << std::endl;
    std::cout << "You didn’t put enough bacon in my burger!" << std::endl;
    std::cout << "If you did, I wouldn’t be asking for more!" << std::endl << std::endl;
}

void Harl::warning()
{
    std::cout << "[ WARNING ]" << std::endl;
    std::cout << "I think I deserve to have some extra bacon for free." << std::endl;
    std::cout << "I’ve been coming for years whereas you started working here since last month." << std::endl << std::endl;
}

void Harl::error()
{
    std::cout << "[ ERROR ]" << std::endl;
    std::cout << "This is unacceptable!" << std::endl;
    std::cout << "I want to speak to the manager now." << std::endl << std::endl;
}

void Harl::others()
{
    std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
}

// void Harl::complain(std::string level)
// {
//     Harl obj;
//     void (Harl::*ptr[5])() = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error, &Harl::others};
//     std::string msgs[5] = {"DEBUG", "INFO", "WARNING", "ERROR", "idc"};
//     for (size_t i = 0; i < 5; i++)
//     {
//         // std::cout << i << " this is index of this msg => " << msgs[i] << std::endl;
//         if (i == 4)
//         {
//             (obj.*ptr[4])();
//             return ;
//         }
//         if (level == msgs[i])
//         {
//             while (i < 4)
//             {
//                 (obj.*ptr[i])();
//                 i++;
//             }
//             return ;       
//         }   
//     }
// }

void Harl::complain(std::string level)
{
    Harl obj;
    void (Harl::*ptr[5])() = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error, &Harl::others};
    std::string msgs[5] = {"DEBUG", "INFO", "WARNING", "ERROR", "idc"};
    int index = -1;
    for (size_t i = 0; i < 5; i++)
    {
        if (level == msgs[i])
        {
            index = i + 1;
            break;
        }
        if (i + 1 == 5)
            index = 5;
    }

    std::cout << "this is the index that will enter to switch: " << index << std::endl; 
    switch(index)
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

int main(int ac, char **av)
{
    Harl h;

    (void)ac;
    h.complain(av[1]);
    return 0;
}