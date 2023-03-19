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
    std::vector<unsigned int> v; // vector container
    std::list<unsigned int> l; // list container
    double  vecTime; // time to process to using ur algo of sorting
    double  lisTime; // time to process to using ur algo of sorting
public:
    PmergeMe(void);
    PmergeMe(char *av[]);
    PmergeMe(const PmergeMe &target);
    PmergeMe &operator=(const PmergeMe &target);

    void DisVec(void);
    void DisLis(void);
    void vecSorting(void);
    void liSorting(void);
    void displayTiming(void);
    ~PmergeMe();
};



#endif