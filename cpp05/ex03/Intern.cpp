#include "intern.hpp"

intern::intern(void)
{
}

intern::intern(const intern &tar)
{
}

intern &intern::operator=(const intern &tar)
{
    return (*this);
}

intern::~intern()
{
}

const char *intern::NotMatch::what() const throw()
{
    return ("Not Match type!!!!");
}

int match_string(const std::string &input) {
  if (input == "RobotomyRequest" || input == "Robotomy Request") {
    return 0;
  } else if (input == "ShrubberyCreation" || input == "Shrubbery Creation") {
    return 1;
  } else if (input == "PresidentialPardon" || input == "Presidential Pardon") {
    return 2;
  } else {
    return -1;
  }
}


Form* intern::makeForm(std::string formName, std::string formTarget)
{
    try
    {
        int i = match_string(formName);
        if (i >= 0)
        {
            switch (i)
            {
            case 0:
                return (new RobotomyRequestForm(formTarget));
                break;
            case 1:
                return (new ShrubberyCreationForm(formTarget));
                break;
            case 2:
                return (new PresidentialPardonForm(formTarget));
                break;
            }
        }
        throw NotMatch();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        return NULL;
    }
    
}


