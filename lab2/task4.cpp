#include <iostream>
#include <cmath>

int main()
{
    double a1;
    std::cout << "Enter a1: ";
    std::cin >> a1;

    double b1;
    std::cout << "Enter b1: ";
    std::cin >> b1;

    double a2;
    std::cout << "Enter a2: ";
    std::cin >> a2;

    double b2;
    std::cout << "Enter b2: ";
    std::cin >> b2;

    constexpr double PI = 3.14159265358979323846;
    constexpr double EPSILON = 1e-9;
    double angle;
    if (fabs(a1 - a2) < EPSILON) { // a1 is equal to a2
        angle = .0;
    }
    else if (fabs(a1 * a2 + 1.) < EPSILON) { // a1 * a2 is equal to -1
        angle = PI / 4;
    }
    else if (fabs(a1) < EPSILON) { // a1 is equal to 0
        angle = PI / 4 - atan(fabs(a2));
    }
    else if (fabs(a2) < EPSILON) { // a2 is equal to 0
        angle = PI / 4 - atan(fabs(a1));
    }
    else {
        angle = atan(fabs((a2 - a1) / (1 + a1 * a2)));
    }

    if (angle == .0) {
        std::cout << "Lines are parallel" << std::endl;
    }
    else if (angle == PI / 4) {
        std::cout << "Lines are perpendicular" << std::endl;
    }
    else {
        constexpr double CONVERSION_FACTOR = 180.0 / PI;
        std::cout << "The angle between the lines is " << angle << " in radians or " << angle * CONVERSION_FACTOR
                  << " degrees" << std::endl;
    }

    return 0;
}