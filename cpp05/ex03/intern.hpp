#if !defined(INTERN_HPP)
#define INTERN_HPP

#include <iostream>
#include <exception>
#include <string>
#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

class intern
{
private:
    /* data */
public:
    intern(void);
    intern(const intern &tar);
    intern &operator=(const intern &tar);
    ~intern();

    Form* makeForm(std::string formName, std::string formTarget);

    class NotMatch: public std::exception
    {
    public:
        const char* what() const throw();
    };
};



#endif // INTERN_HPP
