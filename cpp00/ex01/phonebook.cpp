/*

!You have to implement phonebook classes:
	* ◦ It has an array of contacts.
	* ◦ It can store a maximum of 8 contacts. If the user tries to add a 9th contact, replace the oldest one by the new one.
	* ◦ Please note that dynamic allocation is forbidden.

*/
/*
* Cout: used to output onto the standard output device like display screen.
* Cin : used to take user input from standard input device like keyboard.
* endl : used to have a new line or a line break.
*/
#include "contact.hpp"
#include "phonebook.hpp"
// #include <iostream>
// #include <stdlib.h>
// // #include <string>
// #include <stdio.h>
// #include <string.h>

class Phonebook
{
	private:
		std::string FirstName;
		std::string LastName;
		std::string Numbers;
		std::string Nickname;
		std::string DarkSecret;
	public:
		void SetDate(int flag)
		{
			if (flag == 3)
			{
				int x; 
				std::cin >> x;
				if (std::cin.fail())
				{
					std::cout << "cin failed\n";
					return ;
				}
				else
				{
					Numbers = x;
					return ;
				}
			}
			std::string str;
			std::cin >> str;
			if (flag == 0)
				FirstName = str;
			else if (flag == 1)
				LastName = str;
			else if (flag == 2)
				Nickname = str;
			else if (flag == 4)
				DarkSecret = str;
		}
		std::string	GetData()
		{
			return (Numbers);
		}
};


int	main()
{
	Phonebook Obj[8];
	int	j = 0;
	// char *str;
	std::string cmd;	//initial a string
	
	while (true)
	{
		std::cout << "ENTER A CHOICE:\t";
		std::getline(std::cin, cmd);
		if (cmd.empty())
			break;
		else if (cmd == "EXIT")
			exit(0);
		else if (cmd == "ADD")
		{

			std::string fname;
			std::cout << "Enter your first name: ";
			std::cin >> fname;

			std::string lname;
			std::cout << "Enter your last name: ";
			std::cin >> lname;

			std::string nname;
			std::cout << "Enter your nickname: ";
			std::cin >> nname;

			std::string phone;
			std::cout << "Enter your number phone: ";
			std::cin >> phone;
			std::istringstream num(phone);
			int digit;
			

			std::string dsecret;
			std::cout << "Enter your darkest secret: ";
			std::cin >> dsecret;
		}
		else if (cmd == "SEARCH")
		{

			std::cout << "1: :\t";
		}
		else
		{
			std::cout << "Invalid Command, please try again\n" << std::endl;
		}
		
	}
	return (0);
}
