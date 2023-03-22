#include "PmergeMe.hpp"

PmergeMe::PmergeMe(void)
{
    std::cout << "Default Constructor!!!" << std::endl;
}

PmergeMe::PmergeMe(char *av[])
{
    int i = 0;
    while (av[++i])
    {
        v.push_back(std::atoi(av[i]));
        l.push_back(std::atoi(av[i]));
    }
}

void PmergeMe::DisVec()
{
    if (v.empty())
        std::cout << "Vector is empthy!!" << std::endl;
    else
    {
        std::vector<unsigned int>::iterator it;
        it = v.begin();
        int index = 0; 
        while (it != v.end())
        {
            index = it - v.begin();
            if (index > 15)
            {
                std::cout << " [...]" ;
                break;
            }
            std::cout << " " << *it ;
            it++;
        }
        std::cout << std::endl;
    }
}

void PmergeMe::DisLis()
{
    if (l.empty())
        std::cout << "Vector is empthy!!" << std::endl;
    else
    {
        std::list<unsigned int>::iterator it;
        it = l.begin();
        while (it != l.end())
        {
            std::cout << " " << *it ;
            it++;
        }
        std::cout << std::endl;
    }
}


// ! sorting for vector

void PmergeMe::vecSorting(void)
{
    //  the start time taken by the current process (before sorting)
    clock_t start = clock();
    std::vector<unsigned int> tmp;

    tmp.push_back(v.back());
    v.pop_back();
    while (!v.empty())
    {
        std::vector<unsigned int>::iterator itmp = tmp.begin();
        while (v.back() >= *itmp && itmp != tmp.end())
            itmp++;
        tmp.insert(itmp, v.back());
        v.pop_back();
    }
    v = tmp;
    
    //  the end time taken by the current process (after sorting)
    clock_t end = clock();

    //  the difference
    this->vecTime = (double) (end-start) / CLOCKS_PER_SEC * 1000.0;
    // std::cout << vecTime << std::endl;
}

// ! sorting for list

void PmergeMe::liSorting(void)
{
    //  the start time taken by the current process (before sorting)
    clock_t start = clock();
    std::list<unsigned int> tmp;
    
    tmp.push_back(l.back());
    l.pop_back();
    while (!l.empty())
    {
        std::list<unsigned int>::iterator itmp = tmp.begin();
        while (l.back() >= *itmp && itmp != tmp.end())
            itmp++;
        tmp.insert(itmp, l.back());
        l.pop_back();
    }
    l = tmp;
    
    //  the end time taken by the current process (after sorting)
    clock_t end = clock();

    //  the difference
    this->lisTime = (double) (end-start) / CLOCKS_PER_SEC * 1000.0;
    // std::cout << lisTime << std::endl;

}

void PmergeMe::displayTiming()
{
    std::cout << "Time to process a range of " << v.size() << " elements with std::vector : " << vecTime << " us" << std::endl;
    std::cout << "Time to process a range of " << l.size() << " elements with std::list : " << lisTime << " us" << std::endl;
}

PmergeMe::PmergeMe(const PmergeMe &target)
{
    v = target.v;
    l = target.l;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &target)
{
    if (this != &target)
    {
        v = target.v;
        l = target.l;
    }
    return (*this);
}

PmergeMe::~PmergeMe()
{
    // std::cout << "Destructor!!!" << std::endl;
}
