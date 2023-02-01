#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(void):Form("RobotomyRequestForm", "None", 72, 45)
{
}

RobotomyRequestForm::RobotomyRequestForm(std::string target):Form("RobotomyRequestForm", target, 72, 45)
{
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &target)
{
    return (*this);
} 

std::ostream& operator<<(std::ostream &o, const RobotomyRequestForm &src)
{
    o << src.getName() << " with target form " << src.getTargetForm() << std::endl;
    return (o);
}


void RobotomyRequestForm::execute(Bureaucrat const &exGrade)
{
    if (!getSigned())
    {
        // std::cerr << "this is the error 1" << std::endl;
        throw isNotSigned();
    }
    if (getExcuteGrade() < exGrade.getGrade())
    {
        // std::cerr << "this is the error 2" << std::endl;
        throw lowGrade();
    }
    std::cout << "Dg Dg ..... Dg Dg Dg Dg Dg ...... Dg Dg Dg Dg Dg Dg Dg Dg! ";
    srand(time(0));
    if (rand()%100 <= 50)
        std::cout << exGrade.getName() << " has been successfully" << std::endl;
    else 
        std::cout << exGrade.getName() << " has been failed ...... :'(" << std::endl;


}