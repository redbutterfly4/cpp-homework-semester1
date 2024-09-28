#include <iostream>

void invokeFunctionNTimes(void (*)(), int);
void myFunction();

int main()
{
    std::cout << "Enter n: ";
    int n;
    std::cin >> n;

    invokeFunctionNTimes(myFunction, n);
    return 0;
}

void invokeFunctionNTimes(void (*func)(), int n)
{
    while (n--) {
        func();
    }
}

void myFunction()
{
    std::cout << "Function called.\n";
}