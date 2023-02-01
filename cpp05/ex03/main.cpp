#include "Form.hpp"
#include "intern.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

int main(void)
{
    intern i;
    try 
    {
        // {
        //     // Bureaucrat human("dabdoba",135);
        //     Bureaucrat human("dabdoba",-140);
        //     // Bureaucrat human("dabdoba",146);

        //     ShrubberyCreationForm myTree("hselbi");
            
        //     std::cout << human << std::endl;
        //     std::cout << myTree << std::endl;
            
        //     myTree.beSigned(human);
        //     human.signForm(myTree);
        //     myTree.execute(human);
        // }

        // {
        //     Bureaucrat human("dabdoba",-135);
        //     // Bureaucrat human("dabdoba",140);
        //     // Bureaucrat human("dabdoba",40);

        //     RobotomyRequestForm myRobot("hselbi");
            
        //     std::cout << human << std::endl;
        //     std::cout << myRobot << std::endl;
            
        //     myRobot.beSigned(human);
        //     human.signForm(myRobot);
        //     myRobot.execute(human);
        // }

         {
            // Bureaucrat human("dabdoba",-135);
            // Bureaucrat human("dabdoba",40);

            Form *fo; 
            Bureaucrat human("dabdoba",4);

            // PresidentialPardonForm myRobot("hselbi");
            fo = i.makeForm("ShrubberyCreation", "hselbi");
            std::cout << fo->getName() << std::endl;
            std::cout << fo->getTargetForm() << std::endl;
            std::cout << *fo << std::endl;
            // myRobot.beSigned(human);
            // human.signForm(myRobot);
            // myRobot.execute(human);

            // human.executeForm(myRobot);
        }



    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
}