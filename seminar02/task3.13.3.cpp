#include <iostream>
#include <cmath>

int main()
{
    // Variant 13
    std::cout << "Enter x: ";
    double x;
    std::cin >> x;

    std::cout << "Enter y: ";
    double y;
    std::cin >> y;

    if (y == 0) {
        std::cout << "y cannot be equal to zero because it is in the denominator\n";
        return 1;
    }

    // Calculate result using a given formula
    double result;
    if (x / y > 0) {
        result = std::pow(x + std::log(std::abs(y)), 3.0);
    }
    else if (x / y < 0) {
        result = 2.0 / 3.0 + std::log(std::abs(std::sin(y)));
    }
    else {
        result = std::pow(x, 2. / 3.) + y;
    }

    std::cout << "result = " << result << std::endl;
    return 0;
}