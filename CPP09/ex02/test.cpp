#include "PmergeMe.hpp"


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

int main(int ac, char *av[])
{
    if (ac < 2)
        std::cout << "try again!!" << std::endl;
    else {
        std::vector<unsigned int> v;
        int i = 0;
        while (av[++i])
            v.push_back(std::atoi(av[i]));
        
        // ? print the vector

        std::vector<unsigned int>::iterator it;
        it = v.begin();
        std::cout << "v ==> ";
        while (it != v.end())
        {
            std::cout << " " << *it;
            it++;
        }
        std::cout << std::endl;
        std::cout << "size = "<< v.size() << std::endl;
        
        // ! algo merge
        vecMergeSort(v, 0, v.size() - 1, v.size()/2);
        std::cout << "v ==> ";
        it = v.begin();
        while (it != v.end())
        {
            std::cout << " " << *it;
            it++;
        }
        std::cout << std::endl;
        std::cout << "size = "<< v.size() << std::endl;
    }
}