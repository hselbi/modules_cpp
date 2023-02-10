#include "ScavTrap.hpp"

int main()
{
    ScavTrap st("Slime");

    st.attack("Giant");
    st.takeDamage(8);
    st.takeDamage(5);
    st.beRepaired(2);
    st.attack("Giant");
    st.guardGate();
    return 0;
}