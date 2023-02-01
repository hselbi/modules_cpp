#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include <iostream>
#include <exception>
#include <string>
#include "Form.hpp"
#include "Bureaucrat.hpp"

class ShrubberyCreationForm : public Form
{
private:
    /* data */
public:
    ShrubberyCreationForm(void);
    ShrubberyCreationForm(std::string target);
    ~ShrubberyCreationForm();
    ShrubberyCreationForm(const ShrubberyCreationForm& target);
    ShrubberyCreationForm &operator=(const ShrubberyCreationForm &target);

    void execute(Bureaucrat const &exGrade);
};

std::ostream& operator<<(std::ostream &o, const ShrubberyCreationForm &src);


#endif