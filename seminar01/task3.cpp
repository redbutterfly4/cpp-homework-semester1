#include <iostream>
#include <cmath>

int main()
{
    std::cout << "Enter x: ";
    double x;
    std::cin >> x;

    std::cout << "Enter y: ";
    double y;
    std::cin >> y;

    // Calculate z using a given formula
    double zNumerator = x + ((2.0 + y) / (x * x));
    double zDenominator = y + 1.0 / std::sqrt(x * x + 10);
    double z = zNumerator / zDenominator;

    // Calculate q using a given formula
    double q = 7.25 * std::sin(x) - std::abs(y);

    std::cout << "z = " << z << '\n' << "q = " << q << std::endl;
}