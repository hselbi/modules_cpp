#include "ShrubberyCreationForm.hpp"


ShrubberyCreationForm::ShrubberyCreationForm(void) : Form("ShrubberyCreationForm", "None", 145, 137)
{
    ;
    // targetForm = "None";
    
}
ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : Form("ShrubberyCreationForm", target,145, 137)
{
    ;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& target)
{
    //copy constructor
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &target)
{
    return (*this);
} 

std::ostream& operator<<(std::ostream &o, const ShrubberyCreationForm &src)
{
    o << src.getName() << " with target form " << src.getTargetForm() << std::endl;
    return (o);
}

void  ShrubberyCreationForm::execute(Bureaucrat const &exGrade)
{
    if (!getSigned())
    {
        throw isNotSigned();
    }
    if (getExcuteGrade() < exGrade.getGrade())
    {
        throw lowGrade();
    }
    std::string nameFile = exGrade.getName() + "_shrubbery";
    std::ifstream readFile;
    std::ofstream file(nameFile);

    file << "               ,@@@@@@@,\n"
            "       ,,,.   ,@@@@@@/@@,  .oo8888o.\n"
            "    ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o\n"
            "   ,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'\n"
            "   %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'\n"
            "   %&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'\n"
            "   `&%\\ ` /%&'    |.|        \\ '|8'\n"
            "       |o|        | |         | |\n"
            "       |.|        | |         | |\n"
            "_\\__\\/ ._\\//_/__/  ,\\_//__\\/.  \\_//__/_\n"
;

    file.close();
}

