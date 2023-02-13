#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "DiamondTrap.hpp"

int main(void)
{
    {
        std::cout << "/************************ ClapTrap *********************/" << std::endl;
        ClapTrap ct("Slime");

        ct.attack("Giant");
        ct.takeDamage(8);
        ct.takeDamage(5);
        ct.beRepaired(2);
        ct.attack("Giant");
    }

    {
        std::cout << "/************************ ScavTrap *********************/" << std::endl;
        ScavTrap st("Bender");

        st.attack("Bowser");
        st.takeDamage(8);
        st.takeDamage(5);
        st.beRepaired(20);
        st.attack("Bowser");
        st.guardGate();
    }
	{
        std::cout << "/************************ FragTrap *********************/" << std::endl;
        FragTrap ft("Melron");

	    ft.attack("Oristor");
	    ft.takeDamage(8);
	    ft.takeDamage(3);
	    ft.beRepaired(30);
	    ft.attack("Oristor");
        ft.highFivesGuys();
    }
	return (0);
}