#include <iostream>

int main()
{
    // Variant 13
    std::cout << "Enter x: ";
    double x;
    std::cin >> x;

    std::cout << "Enter y: ";
    double y;
    std::cin >> y;

    if (x == 0 || y == 0) {
        std::cout << "x and y cannot be equal to 0\n";
        return 1;
    }

    int quadrant;
    if (x > 0) {
        if (y > 0) {
            quadrant = 1;
        }
        else {
            quadrant = 2;
        }
    }
    else {
        if (y > 0) {
            quadrant = 4;
        }
        else {
            quadrant = 3;
        }
    }
    std::cout << "The point is located in the coordinate quarter number " << quadrant << '\n';

    return 0;
}