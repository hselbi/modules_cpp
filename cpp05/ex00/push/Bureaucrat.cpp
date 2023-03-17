#include "Bureaucrat.hpp"

// Default Constructor
Bureaucrat::Bureaucrat(void): _name("Default"), _grade(150)
{
    std::cout << "[ Bureaucrat: Default Constructor ]" << std::endl << std::endl;
}

// copy Constructor

Bureaucrat::Bureaucrat(const Bureaucrat &target)
{
    std::cout << "[ Bureaucrat: Copy Constructor Called ]" << std::endl << std::endl;
    this->_name = target._name;
    this->_grade = target._grade;
}

// assignement operator

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &target)
{
    std::cout << "[ Bureaucrat: Assignement operator Called ]" << std::endl << std::endl;
    if (this != &target)
    {
        this->_name = target._name;
        this->_grade = target._grade;
    }
    return (*this);
}

// return the error
const char *Bureaucrat::GradeTooHighException::what() const throw() {
    return "Garde Too High!!!!";
}

const char *Bureaucrat::GradeTooLowException::what() const throw() {
    return "Garde Too Low!!!!";
}



// constructor parameterized 

Bureaucrat::Bureaucrat(int grade)
{
    std::cout << "[ Bureaucrat: Parameterized (grade) Constructor is called ]" << std::endl << std::endl;
    if (grade < 1)
        throw GradeTooHighException();
    else if (grade > 150)
        throw GradeTooLowException();
    else
        _grade = grade;
}

Bureaucrat::Bureaucrat(std::string name)
{
    std::cout << "[ Bureaucrat: Parameterized (name) Constructor is called ]" << std::endl << std::endl;
    _name = name;
}

Bureaucrat::Bureaucrat(std::string name, int grade)
{
    std::cout << "[ Bureaucrat: Parameterized (both) Constructor is called ]" << std::endl << std::endl;
    if (grade < 1)
        throw GradeTooHighException();
    else if (grade > 150)
        throw GradeTooLowException();
    else
        _grade = grade;

    _name = name;
}

std::string Bureaucrat::getName() const
{
    return (this->_name);
}

int Bureaucrat::getGrade() const
{
    return (this->_grade);
}


void Bureaucrat::incrementGrade()
{
    if (_grade > 1)
        _grade--;
    else
        throw GradeTooHighException();
}

void Bureaucrat::decrementGrade()
{
    if (_grade < 150)
        _grade++;
    else
        throw GradeTooLowException();
}


Bureaucrat::~Bureaucrat()
{
    std::cout << "[ Bureaucrat: Deconstructor ]" << std::endl;
}


std::ostream &operator<<(std::ostream &o, const Bureaucrat &src)
{
    o << src.getName() << " Bureaucrat Grade " << src.getGrade() << std::endl;
    return o;
}

