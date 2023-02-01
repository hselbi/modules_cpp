#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void):Form("PresidentialPardonForm", "None", 25, 5)
{
}

PresidentialPardonForm::PresidentialPardonForm(std::string target):Form("PresidentialPardonForm", target, 25, 5)
{
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &target)
{
    return (*this);
} 

std::ostream& operator<<(std::ostream &o, const PresidentialPardonForm &src)
{
    o << src.getName() << " with target form " << src.getTargetForm() << std::endl;
    return (o);
}


void PresidentialPardonForm::execute(Bureaucrat const &exGrade)
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
    std::cout << exGrade.getName() << " has been pardoned by Zaphod Beeblebrox" << std::endl;
    
}