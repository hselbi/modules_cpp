#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <limits>
#include <vector>
#include <list>
#include <algorithm>
# include <cstdlib>
# include <stdexcept>
# include <ctime>

class PmergeMe
{
private:
    std::vector<unsigned int> v;
    std::list<unsigned int> l;
    double  vecTime;
    double  lisTime;
public:
    PmergeMe(void);
    PmergeMe(char *av[]);
    PmergeMe(const PmergeMe &target);
    PmergeMe &operator=(const PmergeMe &target);

    void DisCon(void);
    void vecSorting(void);
    void liSorting(void);
    ~PmergeMe();
};



#endif