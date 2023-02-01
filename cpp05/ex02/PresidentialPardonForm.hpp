#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP


#include <iostream>
#include <exception>
#include <string>
#include "Form.hpp"
#include "Bureaucrat.hpp"

class PresidentialPardonForm: virtual public Form
{
private:
    /* data */
public:
    PresidentialPardonForm(void);
    PresidentialPardonForm(std::string target);
    ~PresidentialPardonForm();
    PresidentialPardonForm(const PresidentialPardonForm &target);
    PresidentialPardonForm &operator=(const PresidentialPardonForm &target);

    void execute(Bureaucrat const &exGrade);

};

std::ostream& operator<<(std::ostream &o, const PresidentialPardonForm &src);

#endif