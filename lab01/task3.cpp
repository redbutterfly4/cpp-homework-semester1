#include <iostream>

int main()
{
    std::cout << "Enter x: ";
    int x;
    std::cin >> x;

    std::cout << "Enter y: ";
    int y;
    std::cin >> y;

    // Swap x and y values in three ways

    // First way
    int tmp = x;
    x = y;
    y = tmp;
    std::cout << "After the first swap: x = " << x << " and y = " << y << '\n';

    // Second way
    x += y;
    y = x - y;
    x -= y;
    std::cout << "After the second swap: x = " << x << " and y = " << y << '\n';

    // Third way
    x = x ^ y;
    y = x ^ y;
    x = x ^ y;
    std::cout << "After the third swap x = " << x << " and y = " << y << '\n';
}
