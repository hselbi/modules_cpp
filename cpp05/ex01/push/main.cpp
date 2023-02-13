#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    try
	{
		// test 1
		{
			Form project1("project 1", 1000, -3);
			Form project1("project 1", 10000, 5);
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
			
			// Bureaucrat human("Olivia", 3);
			// std::cout << human << std::endl;

			// // Form project1("project 1", 3, 2);
			// Form project1("project 1", 1, 3);
		
			// project1.beSigned(human);
			
			// human.signForm(project1);

			// std::cout << project1 << std::endl;
		}
	}
	catch (std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}
    
}