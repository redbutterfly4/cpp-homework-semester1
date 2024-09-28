#include <iostream>
#include <cmath>

int main()
{
    std::cout << "Enter a: ";
    double a;
    std::cin >> a;

    // Calculate y = sqrt( (2a + sin|3a|) / 3.56 )
    double numerator = 2 * a + std::sin(std::abs(3.0 * a));
    double y = std::sqrt(numerator / 3.56);
    std::cout << "y = " << y << std::endl;
}
