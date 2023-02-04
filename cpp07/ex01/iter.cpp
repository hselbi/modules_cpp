#include <iostream>

template<typename T>
void iter(T *arr, int len, void (*f)(T))
{
    for (int i = 0; i < len; i++)
        f(arr[i]);
}

template<typename T>
void fprint(T str)
{
    std::cout << str << std::endl;    
}

int main()
{
    int array1[]={1,2,3,4,5};
	char array2[]={'a','b','c','d','e'};
	float array3[]={1.1,2.2,3.3,4.4,5.5};

	::iter(array1, 5, fprint);
	::iter(array2, 5, fprint);
	::iter(array3, 5, fprint);
    return 0;
}
