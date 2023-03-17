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

    {
        std::cout << "/************************ DiamondTrap *********************/" << std::endl;
        DiamondTrap dt("UnderTaker");

	    dt.attack("Oristor");
	    dt.takeDamage(8);
	    dt.takeDamage(3);
	    dt.beRepaired(30);
	    dt.attack("Oristor");
        dt.whoAmI();
    }
	return (0);
}