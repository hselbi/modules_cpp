#include "PmergeMe.hpp"

int checkIn(int ac, char *av[])
{
    if (ac < 2)
    {
        std::cout << "There's No Arguments, Try Again!!" << std::endl;
        return 1;
    }
    int i = 0;
    while (av[++i])
    {
        int nbr = std::atoi(av[i]);
        if (nbr < 0 || nbr > INT32_MAX)
        {
            std::cout << "This is number is Negative, Try Again!!" << std::endl;
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
        merge.DisVec();
        // merge.DisLis();
        merge.vecSorting();
        merge.liSorting();
        std::cout << "after: " ;
        merge.DisVec();
        // merge.DisLis();
        merge.displayTiming();
    }
    return 0;
}