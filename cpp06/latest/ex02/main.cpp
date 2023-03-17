#include "TypeId.hpp"

int	main(void)
{
	Base * p;
	Base * p1;

	p = generate();
	usleep(1000000);
	p1 = generate();

	std::cout << std::endl;
	std::cout << "/********* POINTER *********/" << std::endl;
	identify(p);
	identify(p1);

	std::cout << "/********* REFERENCE *********/" << std::endl;
	identify(*p);
	identify(*p1);
	std::cout << "/***************************/" << std::endl;
	std::cout << std::endl;

	delete p;
	delete p1;
	return (0);
}