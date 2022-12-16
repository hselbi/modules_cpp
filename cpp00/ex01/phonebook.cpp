/*

!You have to implement phonebook classes:
	* ◦ It has an array of contacts.
	* ◦ It can store a maximum of 8 contacts. If the user tries to add a 9th contact, replace the oldest one by the new one.
	* ◦ Please note that dynamic allocation is forbidden.

*/
#include <iostream>
#include <stdlib.h>
// #include <string>
#include <stdio.h>
#include <string.h>

int	ft_isdigit(char *str)
{
	int i = 0;
	while (str[i])
	{
		if (str[i] <= '0' || str[i] >= '9')
			return (0);
		i++;
	}
	return (1);
}

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
	std::string str;	//initial a string
	
	while (1)
	{
		std::cout << "ENTER A CHOICE:\t";
		std::getline(std::cin, str);
		if (str.empty())
			break;
		else if (str == "EXIT")
			exit(0);
		else if (str == "ADD")
		{
			for (int i = 0; i < 5; i++)
			{
				if (i == 0)
					std::cout << "\nput your first name\t";
				else if (i == 1)
					std::cout << "\nput your last name\t";
				else if (i == 2)
					std::cout << "\nput your nickname\t";
				if (i == 3)
					std::cout << "\nput your number\t";
				if (i == 4)
					std::cout << "\nput your darkest secret\t";
				Obj[j].SetDate(i);
				j++;
			}
			/*
				! when user use this command shoukd gives like thus :
					* put first name:
					* put last name:
					* put nickname:
					* put phone number:
					* put dark secret: 
				! the contact fields 
					* first name
					* last name
					* nickname
					* phone number
					* dark secret
			*/
		}
		else if (str == "SEARCH")
		{

			std::cout << "1: :\t";
			/* 
			! searching
				* in saved contacts 
					^ index
					^ first name
					^ last name
					^ nickname
				* each column must be 10 characters wide
					^ a pipe "|" separate them
					^ text must be right-aliged
					^ if text longer than the column make a truncated and the last char must be dot "."
				* 
			*/
		}
	}
	// Obj.SetDate(av[1]);
	// std::cout << Obj.GetData();
	return (0);
}
