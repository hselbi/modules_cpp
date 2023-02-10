
// Header-protection
#pragma once

// Includes
#include "ClapTrap.hpp"

// classes

class FragTrap: virtual public ClapTrap
{
	private:

	public:
	// Constructors
		FragTrap();
		FragTrap(const FragTrap &copy);
		FragTrap(std::string name);

	// Deconstructors
		~FragTrap();

	// Overloaded Operators
		FragTrap &operator=(const FragTrap &src);

	// Public Methods
		void highFiveGuys(void);
	// Getter

	// Setter

};
