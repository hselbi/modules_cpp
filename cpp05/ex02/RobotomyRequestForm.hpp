#ifndef ROBOTMYREQUESTFORM_HPP
#define ROBOTMYREQUESTFORM_HPP

#include <iostream>
#include <exception>
#include <string>
#include "Form.hpp"
#include "Bureaucrat.hpp"

class RobotomyRequestForm : virtual public Form
{
private:
    /* data */
public:
    RobotomyRequestForm(void);
    RobotomyRequestForm(std::string target);
    ~RobotomyRequestForm();
    RobotomyRequestForm(const RobotomyRequestForm &target);
    RobotomyRequestForm &operator=(const RobotomyRequestForm &target);

    void execute(Bureaucrat const &exGrade);
};

std::ostream& operator<<(std::ostream &o, const RobotomyRequestForm &src);

#endif