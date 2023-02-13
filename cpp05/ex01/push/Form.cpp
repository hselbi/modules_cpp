#include "Form.hpp"

Form::Form(void)
{
    _name = "Default";
    isSigned = 0;
    signGrade = 0;
    requiredGrade = 0;

    std::cout << "[ Form: Constructor Default ]" << std::endl;
}

Form::~Form()
{
    std::cout << "[ Form: Destructor ]" << std::endl;
}

Form::Form(std::string name, int siGrade, int exGrade)
{
    std::cout << "[ Form: Constructor Paramaterized ]" << std::endl;
    _name = name;
    isSigned = 0;
    if (siGrade < 1 || exGrade < 1)
        throw GradeTooHighException();
    else if (siGrade > 150 | exGrade)
        throw GradeTooLowException();

    signGrade = siGrade;
    requiredGrade = exGrade;
}

std::string Form::getName() const
{
    return (_name);
}

bool Form::getSigned() const
{
    return (isSigned);
}

int Form::getSignGrade() const
{
    return (signGrade);
}

int Form::getRequiredGrade() const
{
    return requiredGrade;
}


const char* Form::GradeTooHighException::what() const throw() {
    return "Grad is Too High!!!!!!!!!!";
}

const char* Form::GradeTooLowException::what() const throw()
{
    return "Grade is too low!!!!!!!!";
}

std::ostream &operator<<(std::ostream &o, const Form &src)
{
    o << "[ " << src.getName() << " ]\nGrade Required to Sign it: " << src.getRequiredGrade() << "\nGrade Required to Execute it: " << src.getSignGrade() << std::endl;
    return o; 
}

void Form::beSigned(const Bureaucrat &src)
{
    if (src.getGrade() < 150)
        throw GradeTooLowException();
    else if (src.getGrade() > 1)
        throw GradeTooHighException();
    else if (src.getGrade() <= signGrade && src.getGrade() <= requiredGrade)
        isSigned = 1;
}