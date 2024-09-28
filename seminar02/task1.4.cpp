#include <iostream>

int main()
{
    std::cout << "Enter a: ";
    int a;
    std::cin >> a;

    std::cout << "Enter b: ";
    int b;
    std::cin >> b;

    std::cout << "Enter c: ";
    int c;
    std::cin >> c;

    int minNumber = a;
    if (b < minNumber) {
        minNumber = b;
    }
    if (c < minNumber) {
        minNumber = c;
    }

    int maxNumber = a;
    if (b > maxNumber) {
        maxNumber = b;
    }
    if (c > maxNumber) {
        maxNumber = c;
    }

    std::cout << "Max number is " << maxNumber << '\n';
    std::cout << "Min number is " << minNumber << std::endl;

    return 0;
}