#include "PmergeMe.hpp"

PmergeMe::PmergeMe(void)
{}

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
        std::cout << "list is empthy!!" << std::endl;
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

/****************************************
 *                Vector                *
 ****************************************/

void    vectorInsertSort(std::vector<unsigned int> &vec, int begin, int end) 
{
    for (int i = begin; i < end; i++) {
        unsigned int tmp = vec[i + 1];
        int j = i + 1;
        while (j > begin && vec[j - 1] > tmp) {
            vec[j] = vec[j - 1];
            j--;
        }
        vec[j] = tmp;
    }
}

void vectorMerge(std::vector<unsigned int> &vec, int begin, int middle, int end)
{
    int left = middle - begin + 1;
    int right = end - middle;
    std::vector<unsigned int> leftSide(left);
    std::vector<unsigned int> rightSide(right);
    for (int i = 0; i < left; i++)
        leftSide[i] = vec[begin + i];

    for (int i = 0; i < right; i++)
        rightSide[i] = vec[middle + 1 + i];
    int i, j, k;
    i = 0, j = 0, k = begin;
    while (i < left && j < right)
    {
        if (leftSide[i] <= rightSide[j]) {
            vec[k] = leftSide[i];
            i++;
        }
        else {
            vec[k] = rightSide[j];
            j++;
        }
        k++;
    }
    while (i < left)
    {
        vec[k] = leftSide[i];
        i++;
        k++;
    }
    while (j < right)
    {
        vec[k] = rightSide[j];
        j++;
        k++;
    }
    return ;
}

void vecMergeSort(std::vector<unsigned int> &vec, int begin, int end, int mid)
{
    if (begin - end > mid)
    {
        int middle = (begin + end) / 2;
        vecMergeSort(vec, begin, middle, mid);
        vecMergeSort(vec, middle + 1, end, mid);
        vectorMerge(vec, begin, middle, end);
    }
    else
        vectorInsertSort(vec, begin, end);
}

void PmergeMe::vecSorting(void)
{
    clock_t start = clock();
    vecMergeSort(this->v, 0, this->v.size() - 1, this->v.size() / 2);
    clock_t end = clock();
    this->vecTime = (double) (end-start) / CLOCKS_PER_SEC * 1000.0;
}

/****************************************
 *                 List                 *
 ****************************************/

void listInsertionSort(std::list<unsigned int>& lst) {
    std::list<unsigned int> tmp;
    tmp.push_back(lst.back());
    lst.pop_back();
    while (!lst.empty())
    {
        std::list<unsigned int>::iterator itmp = tmp.begin();
        while (lst.back() >= *itmp && itmp != tmp.end())
            itmp++;
        tmp.insert(itmp, lst.back());
        lst.pop_back();
    }
    lst = tmp;
}

std::list<unsigned int> listMerge(std::list<unsigned int>& left, std::list<unsigned int>& right) {
    std::list<unsigned int> result;
    while (!left.empty() && !right.empty()) 
    {
        if (left.front() <= right.front()) {
            result.push_back(left.front());
            left.pop_front();
        }
        else {
            result.push_back(right.front());
            right.pop_front();
        }
    }
    while (!left.empty()) 
    {
        result.push_back(left.front());
        left.pop_front();
    }
    while (!right.empty()) 
    {
        result.push_back(right.front());
        right.pop_front();
    }
    return result;
}

void listMergeSort(std::list<unsigned int>& lst) {
    if (lst.size() <= 1) {
        return;
    }
    if (lst.size() <= 10)
    {
        listInsertionSort(lst);
        return ;
    }
    std::list<unsigned int> left, right;
    std::list<unsigned int>::iterator middle = lst.begin();
    std::advance(middle, lst.size() / 2);
    std::copy(lst.begin(), middle, std::back_inserter(left));
    std::copy(middle, lst.end(), std::back_inserter(right));
    listMergeSort(left);
    listMergeSort(right);
    lst = listMerge(left, right);
}

void PmergeMe::liSorting(void)
{
    clock_t start = clock();
    listMergeSort(this->l);
    clock_t end = clock();
    this->lisTime = (double) (end-start) / CLOCKS_PER_SEC * 1000.0;
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
{}
