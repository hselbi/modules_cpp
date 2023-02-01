#include <iostream>
#include <string>
#include <exception>

class Bureaucrat;

class Form
{
private:
    std::string name_;
    bool issigned;
    int signGrade;
    int excuteGrade;
public:
    Form(void) ;
    Form(std::string name, int siGrade, int exGrade);
    virtual ~Form();
    Form(const Form& src);
    Form &operator=(const Form &src);

    void beSigned(Bureaucrat &src);

    std::string getName() const;
    bool getSigned() const;
    int getSignedGrade() const;
    int getExcuteGrade() const;

    class GradeTooLowException: std::exception {
        const char* what() const throw()
        {
            return "Grade Too Low";
        }
    };
    class GradeTooHighException: std::exception {
        const char* what() const throw()
        {
            return "Grade Too High";
        }
    };
};

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

    void increaseGrade();
    void decreaseGrade();
    
    // getters
    const std::string getName(void) const;
    int getGrade(void) const;

    void signForm(Form &target);

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

void Form::beSigned(Bureaucrat &src)
{
    if (src.getGrade() < 1)
        throw GradeTooHighException();
    else if (src.getGrade() > 150)
        throw GradeTooLowException();
    if (src.getGrade() <= signGrade && src.getGrade() <= excuteGrade)
        issigned = 1;
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


std::ostream& operator<<(std::ostream &o, const Form &src)
{
    o << "[ " << src.getName() << " ]\n" << "Required Grade: " << src.getSignedGrade() << "\nExcustion Grade: " << src.getExcuteGrade() << std::endl;
    return (o);
}

int main()
{
    try
	{
		// test 1
		{
//			Form project1("project 1", 1000, -3);
//			Form project1("project 1", 10000, 5);
		}
        // test 2
		{
			// Bureaucrat human("Olivia", 3);
			// std::cout << human << std::endl;
			// Form project1("project 1", 3, 3);
			// project1.beSigned(human);
			// human.signForm(project1);
			// std::cout << project1 << std::endl;
		}
		// test 3
		{
			
			Bureaucrat human("Olivia", 3);
			std::cout << human << std::endl;

			// Form project1("project 1", 3, 2);
			Form project1("project 1", 1, 3);
		
			project1.beSigned(human);
			
			human.signForm(project1);

			std::cout << project1 << std::endl;
		}
	}
	catch (std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}
}