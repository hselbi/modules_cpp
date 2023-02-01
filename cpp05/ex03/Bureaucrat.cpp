#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void)
{
    _name = "Default";
    _grade = 150;
    std::cout << "[ Default Constructor is called ]" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& src)
{
    _name = src._name;
    _grade = src._grade;
}

Bureaucrat::Bureaucrat(int grade)
{
    if (grade < 1)
        throw GradeTooHighException();
    else if (grade > 150)
        throw GradeTooLowException();
    _grade = grade;
}

Bureaucrat::Bureaucrat(const std::string name)
{
    _name = name;
}

Bureaucrat::Bureaucrat(const std::string name, int grade)
{
    std::cout << "[ Default Constructor is called ]" << std::endl;
    if (grade < 1)
        throw GradeTooHighException();
    else if (grade > 150)
        throw GradeTooLowException();
    _grade = grade;
    _name = name;
}

const std::string Bureaucrat::getName(void) const
{
    return (_name);
}

int Bureaucrat::getGrade(void) const
{
    return (_grade);
}

void Bureaucrat::increaseGrade()
{
    if (_grade > 1)
        _grade--;
    else if (_grade == 1)
        throw GradeTooHighException();
}

void Bureaucrat::decreaseGrade()
{
    if (_grade < 150)
        _grade++;
    else if (_grade == 150)
        throw GradeTooLowException();
}

Bureaucrat::~Bureaucrat()
{
    std::cout << "[ Default Destructor is called ]" << std::endl;
}

std::ostream& operator<<(std::ostream &o, const Bureaucrat &src)
{
    o << src.getName() << " bureaucrat grade " << src.getGrade() << std::endl;
    return (o);
}

void Bureaucrat::signForm(Form &target)
{
    if (target.getSigned() == true)
    {
        std::cout << _name << " signed " << target.getName() << std::endl;
    }
    else{
        std::cout << _name << " couldn't sign " << target.getName() << " because ";
        if (_grade > target.getSignedGrade())
            std::cout << "required grade is low." << std::endl;
        if (_grade > target.getExcuteGrade())
            std::cout << "required grade is high." << std::endl;
    }

}

void Bureaucrat::executeForm(Form const &form)
{
    if (_grade > form.getExcuteGrade())
    {
        std::cout << _name << " cannot sign " << form.getName();
        std::cout << "because excute grade is too low" << std::endl;
    }
    else
    {
        std::cout << _name << " executed " << form.getName() << std::endl;
    }
}