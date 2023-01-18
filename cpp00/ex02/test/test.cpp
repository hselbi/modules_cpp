#include <iostream>
#include <ctime>
#include <ctime>
#include <iomanip>
int main()
{
    time_t t;
    time(&t);
    std::tm *ltm = std::localtime(&t);
    std::cout << std::put_time(ltm, "[%Y%m%d_%H%M%S]") << std::endl;
    return 0;
}
