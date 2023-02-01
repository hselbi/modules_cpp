#include "Form.hpp"
#include "Bureaucrat.hpp"
class Bureaucrat;
Form::Form(void)
{
    issigned = 0;
    signGrade = 0;
    excuteGrade = 0;
    std::cout << "[ Default Constructor is called ]" << std::endl;
}

Form::Form(std::string name, int siGrade, int exGrade)
{
    name_ = name;
    issigned = 0;
    if (siGrade < 1 || exGrade < 1)
        throw GradeTooHighException();
    else if(siGrade > 150 || exGrade > 150)
        throw GradeTooLowException();

    signGrade = siGrade;
    excuteGrade = exGrade;

}

Form::Form(std::string name, std::string target, int siGrade, int exGrade)
{
    name_ = name;
    issigned = 0;
    if (siGrade < 1 || exGrade < 1)
        throw GradeTooHighException();
    else if(siGrade > 150 || exGrade > 150)
        throw GradeTooLowException();

    signGrade = siGrade;
    excuteGrade = exGrade;
    targetForm = target;

}

Form::Form(const Form& src)
{
    name_ = src.name_;
    issigned = src.issigned;
    signGrade = src.signGrade;
    excuteGrade = src.excuteGrade;
}

Form &Form::operator=(const Form &src)
{
    name_ = src.name_;
    issigned = src.issigned;
    signGrade = src.signGrade;
    excuteGrade = src.excuteGrade;
    return (*this);
}

std::string Form::getName() const
{
    return(name_);
}

std::string Form::getTargetForm() const
{
    return(targetForm);
}

bool Form::getSigned() const
{
    return(issigned);
}

int Form::getExcuteGrade() const
{
    return (excuteGrade);
}

int Form::getSignedGrade() const
{
    return(signGrade);
}

Form::~Form()
{
    std::cout << "[ Default Deconstructor is called ]" << std::endl;
}

std::ostream& operator<<(std::ostream &o, const Form &src)
{
    o << "[ " << src.getName() << " ]\n" << "Required Grade: " << src.getSignedGrade() << "\nExcustion Grade: " << src.getExcuteGrade() << std::endl;
    return (o);
}

void Form::beSigned(Bureaucrat &src)
{
    if (src.getGrade() < 1)
        throw GradeTooHighException();
    else if (src.getGrade() > 150)
        throw GradeTooLowException();
    if (src.getGrade() <= signGrade)
        issigned = 1;
}