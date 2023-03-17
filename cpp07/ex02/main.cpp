#include <iostream>
#include "Array.hpp"

int main(void)
{
	Array<int> iarr(5);

	for (int i = 0; i < 5; i++)
		iarr.buf_[i] = i;
	for (int i = 0; i < 5; i++)
		std::cout << iarr.buf_[i] << std::endl;
	std::cout << "iarr size : " << iarr.size() << std::endl;


	Array<float> carr(5);

	for (int i = 0; i < 5; i++)
		carr.buf_[i] = i + 0.5;
	for (int i = 0; i < 5; i++)
		std::cout << carr.buf_[i] << std::endl;
	std::cout << "carr size : " << iarr.size() << std::endl;

	// Size over error
	try{
		Array<int> iarr2(1);
		std::cout << "error~ : " << iarr2[6] << std::endl;
	}
	catch (const char *str)
	{
		std::cerr << str << std::endl;
	}


	return (0);
}
