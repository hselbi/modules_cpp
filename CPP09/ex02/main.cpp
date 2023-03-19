#include "PmergeMe.hpp"

int checkIn(int ac, char *av[])
{
    if (ac < 2)
    {
        std::cout << "there's no arguments, try again!!" << std::endl;
        return 1;
    }
    int i = 0;
    while (av[++i])
    {
        int nbr = std::atoi(av[i]);
        if (nbr < 0 && nbr > INT32_MAX)
        {
            std::cout << "this is number is negative, try again!!" << std::endl;
            return 1;
        }
    }
    return 0;
}

int main(int ac, char *av[])
{
    
    if (checkIn(ac, av))
        return 1;
    else
    {
        PmergeMe merge(av);
        std::cout << "Before: " ;
        merge.DisCon();
        merge.vecSorting();
        std::cout << "after: " ;
        merge.DisCon();

    // if (merge == false)
    //     cout << "\nVector is not empty";
    // else
    //     cout << "\nVector is empty";
    }
    
    return 0;
}