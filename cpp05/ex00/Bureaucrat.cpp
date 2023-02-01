#include <iostream>
#include <string>
#include <exception>

class Bureaucrat
{
private:
    std::string _name;
    int _grade;
public:
    Bureaucrat(void); //default constructor
    Bureaucrat(int grade); //user-define
    Bureaucrat(std::string name);
    Bureaucrat(std::string name, int grade);
    Bureaucrat(const Bureaucrat &src); // copy constructor

    // setters
    // void setName(std::string name);
    // void setGrade(int grade);
    
    // getters
    const std::string getName(void) const;
    int getGrade(void) const;

    //
    void increaseGrade();
    void decreaseGrade();

    class GradeTooLowException : public std::exception{
        const char *what() const throw() {
            return "Grade Too Low";
        }
    };

    class GradeTooHighException : public std::exception{
        const char *what() const throw() {
            return "Grade Too High";
        }
    };
    ~Bureaucrat(); // default destructor
};

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

int main() {

    try
    {
        Bureaucrat human("Judy", 50);
		std::cout << human << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    

    try
    {
        Bureaucrat human("Judy", 1150);
		std::cout << human << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    try
    {
        Bureaucrat human("Judy", -1);
		std::cout << human << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    try
    {
        Bureaucrat human("Judy", -1);
		std::cout << human << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    try
    {
        Bureaucrat human("Judy", 5);
		std::cout << human << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    try
    {
        Bureaucrat human("Judy", 5);
		std::cout << human << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    try
    {
        Bureaucrat human("Judy", 1);
		std::cout << human << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try {
        Bureaucrat human("Judy", 150);
        std::cout << "this is before " << human << std::endl;
        human.decreaseGrade();
        std::cout << "this is after " << human << std::endl;
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
    try {
        Bureaucrat b("Jane", 100);
        std::cout << "this is before " << b << std::endl;
        b.increaseGrade();
        std::cout << "this is after " << b << std::endl;
        std::cout << b << std::endl;
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
    try {
        Bureaucrat b("Jack", 50);
        std::cout << b << std::endl;
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}


