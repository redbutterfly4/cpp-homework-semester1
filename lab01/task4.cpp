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

    // Calculate result using a given formula
    double resultNumerator = (3 + x * x - std::pow(y, 3.0)) * std::pow(x + 3, 2.0);
    double resultDenominator = x - y * y;
    if (resultDenominator == 0.0) {
        std::cout << "Denominator cannot be equal to 0." << std::endl;
        return 0;
    }
    double result = resultNumerator / resultDenominator;

    std::cout << "result = " << result << std::endl;
}