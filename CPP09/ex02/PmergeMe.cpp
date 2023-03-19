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
    }
}

void PmergeMe::DisCon()
{
    if (v.empty())
        std::cout << "Vector is empthy!!" << std::endl;
    else
    {
        std::vector<unsigned int>::iterator it;
        it = v.begin();
        while (it != v.end())
        {
            std::cout << " " << *it ;
            it++;
        }
        std::cout << std::endl;
    }
}

void PmergeMe::vecSorting(void)
{
    clock_t st;
    clock_t en;

    st = clock();
    
    // 1st sorting
    std::sort(v.begin(), v.end());
    
    // 2nd sorting 
    
    // std::vector<unsigned int> tmp;
    // tmp.push_back(v.back());
    // v.pop_back();
    // while (!v.empty())
    // {
    //     std::vector<unsigned int>::iterator itmp = tmp.begin();
    //     while (v.back() >= *itmp && itmp != tmp.end())
    //         itmp++;
    //     tmp.insert(itmp, v.back());
    //     v.pop_back();
    // }
    // v = tmp;
    
    en = clock();

    std::cout << "start = " << st << "\tend = " << en << std::endl;
    this->vecTime = (en - st)/static_cast<double>(CLOCKS_PER_SEC);
    std::cout << vecTime * 1000 << std::endl;


}


void PmergeMe::liSorting(void)
{
    clock_t st;
    clock_t en;

    st = clock();
    
    // 1st sorting
    std::sort(l.begin(), l.end());
    
    // 2nd sorting 
    
    // std::list<unsigned int> tmp;
    // tmp.push_back(l.back());
    // l.pop_back();
    // while (!l.empty())
    // {
    //     std::list<unsigned int>::iterator itmp = tmp.begin();
    //     while (l.back() >= *itmp && itmp != tmp.end())
    //         itmp++;
    //     tmp.insert(itmp, l.back());
    //     l.pop_back();
    // }
    // l = tmp;
    
    en = clock();

    std::cout << "start = " << st << "\tend = " << en << std::endl;
    this->lisTime = (en - st)/static_cast<double>(CLOCKS_PER_SEC);
    std::cout << lisTime * 1000 << std::endl;

}

PmergeMe::PmergeMe(const PmergeMe &target)
{
    v = target.v;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &target)
{
    if (this != &target)
    {
        v = target.v;
    }
    return (*this);
}

PmergeMe::~PmergeMe()
{
    std::cout << "Destructor!!!" << std::endl;
}
