#include <iostream>
#include <cstring>
#include <ctype.h>

int main(int ac, char **av)
{
    int i = 1;
    int j = 0;
    char ch;
    while (i < ac)
    {
        j = 0;
        while (j < (int)strlen(av[i]))
        {
            ch = toupper(av[i][j]);
            std::cout << ch;
            j++;
        }
        i++;
    }
    std::cout << "\n";
    return 0;
}
