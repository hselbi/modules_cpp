#include "easyfind.hpp"

std::string notFound(void)
{
    return "Did not Found it!!";
}

std::string foundIt(void)
{
    return "Found it!!";
}

template <typename T>
std::string easyfind(T &container, int toBeFound)
{
    typename T::iterator it;
    it = std::find(container.begin(), container.end(), toBeFound);
    if (it == container.end())
        return notFound();
    else
        return foundIt();
}

int main()
{
    std::vector<int> v;

    for (int i = 0; i < 10; i++)
    {
        srand((unsigned) time(NULL));
        int rd = rand() % 13;
        usleep(1000000);
        v.push_back(rd);
        std::cout << v[i] << std::endl;
    }
    
    std::cout << easyfind(v, 12) << std::endl;
    
    return 0;
}