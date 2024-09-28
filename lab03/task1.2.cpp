#include <iostream>

void invokeFunctionNTimes(void (*)(unsigned), unsigned);
void myFunction(unsigned);

int main()
{
    std::cout << "Enter n: ";
    unsigned n;
    std::cin >> n;

    invokeFunctionNTimes(myFunction, n);
    return 0;
}

void invokeFunctionNTimes(void (*func)(unsigned), unsigned n)
{
    for (unsigned i = n - 1; i < n; --i) {
        func(i);
    }
}

void myFunction(unsigned i)
{
    std::cout << "Do something, i = " << i << '\n';
}