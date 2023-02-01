#include <iostream>
#include <exception>

class Bureaucrat;

class Form
{
public:
	Form();
	Form(std::string _FormName,int _requiredGrade, int _executedGrade);
	virtual ~Form();
	Form(const Form &target);
	Form &operator=(const Form &target);

	// 관료의 등급이 높으면 서명하는
	void beSigned(Bureaucrat &target);

	std::string getFormName() const;
	bool getIsSigned() const;
	int getRequiredGrade() const;
	int getExecuteGrade() const;

	class GradeTooHighException : public std::exception {
	public:
		const char *what(void) const throw();
	};
	class GradeTooLowException : public std::exception {
	public:
		const char *what(void) const throw();
	};

private:
	std::string FormName_;
	bool isSigned_;
	int requiredGrade_;
	int executedGrade_;

};

class Bureaucrat {
public:
	Bureaucrat();
	Bureaucrat(const std::string _name, int _grade);

	virtual ~Bureaucrat();

	Bureaucrat(const Bureaucrat &target);

	Bureaucrat &operator=(const Bureaucrat &target);

	std::string getName() const;
	unsigned getGrade() const;
	void setIncreaseGrade();    // 등급을 높인다
	void setDecreaseGrade();    // 등급을 낮춘다
	void signForm(Form &form);
	
	class GradeTooHighException : public std::exception {
	public:
		const char *what(void) const throw();
	};
	class GradeTooLowException : public std::exception {
	public:
		const char *what(void) const throw();
	};

private:
	const std::string name_ ;
	int grade_;

};

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("[Grade Too High Exception]\nGrade 1 is the highest grade, so you can't raise your grade any more.");
}


const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("[Grade Too Low Exception]\nThe grade 150 is the lowest, so you can't lower the grade any more.");
}

Bureaucrat::Bureaucrat()
{
	grade_ = 0;
}

Bureaucrat::Bureaucrat(const std::string _name, int _grade) : name_(_name), grade_(_grade)
{
	if (_grade < 1)
		throw GradeTooHighException();

	else if (_grade > 150)
		throw GradeTooLowException();
}


Bureaucrat::~Bureaucrat()
{
}

Bureaucrat::Bureaucrat(const Bureaucrat &target) : name_(target.name_)
{
	grade_ = target.grade_;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &target)
{
	grade_ = target.grade_;
	return(*this);
}

std::string Bureaucrat::getName() const
{
	return (name_);
}

unsigned Bureaucrat::getGrade() const
{
	return (grade_);
}

void Bureaucrat::setIncreaseGrade()
{
	if (grade_ > 1)
		grade_--;
	else if (grade_ == 1)
		throw GradeTooHighException();
}

void Bureaucrat::setDecreaseGrade()
{
	if (grade_ < 150)
		grade_++;
	else if (grade_ == 150)
		throw GradeTooLowException();
}

void Bureaucrat::signForm(Form &form) {


	if (form.getIsSigned() == 1)
	{
		std::cout << name_ << " signs " << form.getFormName() << std::endl;
	}
	else
	{
		std::cout << name_ << " cannot sign " << form.getFormName() << " because ";

		if (grade_ > form.getExecuteGrade() && grade_ > form.getRequiredGrade())
			std::cout << "all grade is low.";
		else if (grade_ > form.getExecuteGrade())
			std::cout << "execute grade is low.";
		else if (grade_ > form.getRequiredGrade())
			std::cout << "required grade is low.";
		std::cout << std::endl;
	}
}

std::ostream& operator<<(std::ostream &outputStream, const Bureaucrat &ref)
{
	outputStream << ref.getName() << ", bureaucrat grade " << ref.getGrade();
	return (outputStream);
}

const char* Form::GradeTooHighException::what() const throw()
{
	return ("[Grade Too High Exception]\nGrade 1 is the highest grade, so you can't raise your grade any more.");
}


const char* Form::GradeTooLowException::what() const throw()
{
	return ("[Grade Too Low Exception]\nThe grade 150 is the lowest, so you can't lower the grade any more.");
}

Form::Form()
{
	isSigned_ = 0;
	requiredGrade_ = 0;
	executedGrade_ = 0;
}

Form::Form(std::string _FormName,int _requiredGrade, int _executedGrade)
{
	isSigned_ = 0;
	FormName_ = _FormName;
	if (_requiredGrade < 1 || _executedGrade < 1 )
		throw GradeTooHighException();
	else if (_requiredGrade > 150 || _executedGrade > 150 )
		throw GradeTooLowException();

	requiredGrade_ = _requiredGrade;
	executedGrade_ = _executedGrade;
}

Form::~Form()
{

}

Form::Form(const Form &target) {
	FormName_ = target.FormName_;
	isSigned_ = target.isSigned_;
	executedGrade_ = target.executedGrade_;
	requiredGrade_ = target.requiredGrade_;
}

Form &Form::operator=(const Form &target)
{
	FormName_ = target.FormName_;
	isSigned_ = target.isSigned_;
	executedGrade_ = target.executedGrade_;
	requiredGrade_ = target.requiredGrade_;
	return (*this);
}

std::string Form::getFormName() const
{
	return (FormName_);
}
bool Form::getIsSigned() const
{
	return (isSigned_);
}

int Form::getRequiredGrade() const
{
	return (requiredGrade_);
}

int Form::getExecuteGrade() const
{
	return (executedGrade_);
}

void Form::beSigned(Bureaucrat &target)
{
	if (target.getGrade() <= (unsigned int)requiredGrade_ && target.getGrade() <= (unsigned int)executedGrade_)
		isSigned_ = 1;
}

std::ostream& operator<<(std::ostream &outputStream, const Form &ref)
{
	outputStream <<
	"[ " << ref.getFormName() << " ]" << std::endl
	<< "Required grade : " << ref.getRequiredGrade()  << std::endl
	<< "Executed grade : " << ref.getExecuteGrade()  << std::endl;
	return (outputStream);
}

int main()
{
    try
	{
		{
            /*  test for too high */ 
			// Form project("project 1", 1000, -3);
            
            /*  test for too low */ 
			// Form project0("project 1", 10000, 5);
		}

		{
			// Bureaucrat human("Olivia", 3);
			// std::cout << human << std::endl;
			// Form project1("project 1", 3, 3);
			// project1.beSigned(human);
			// human.signForm(project1);
			// std::cout << project1 << std::endl;
		}

		// 일반 예제 2
		{
			// 관료 생성
			Bureaucrat human("Olivia", 3);
			std::cout << human << std::endl;

			// 결제 폼 작성
			Form project1("project 1", 3, 2);
			// Form project1("project 1", 1, 3);

			// 결제를 받는다.
			project1.beSigned(human);

			// 결제를 출력한다.
			human.signForm(project1);

			// Form에 대한 정보 출력
			std::cout << project1 << std::endl;
		}
	}
	catch (std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}
}