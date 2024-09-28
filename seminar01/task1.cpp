#include <iostream>

int main()
{
    std::cout << "Enter x: ";
    double x;
    std::cin >> x;

    // Calculate y = 17x^2 – 6x + 13
    double y = 17.0 * x * x - 6.0 * x + 13.0;
    std::cout << "y = " << y << std::endl;
}