#include <iostream>

int main()
{
    std::cout << "Enter length unit number: ";
    int lengthUnitNumber;
    std::cin >> lengthUnitNumber;

    std::cout << "Enter length: ";
    double inputLength;
    std::cin >> inputLength;

    constexpr double CONVERSION_FACTOR_DECIMETER = 0.1;
    constexpr double CONVERSION_FACTOR_KILOMETER = 1000.0;
    constexpr double CONVERSION_FACTOR_METER = 1.0;
    constexpr double CONVERSION_FACTOR_MILLIMETER = 0.001;
    constexpr double CONVERSION_FACTOR_CENTIMETER = 0.01;

    double length = inputLength;
    switch (lengthUnitNumber) {
        case 1:
            length *= CONVERSION_FACTOR_DECIMETER;
            break;
        case 2:
            length *= CONVERSION_FACTOR_KILOMETER;
            break;
        case 3:
            length *= CONVERSION_FACTOR_METER;
            break;
        case 4:
            length *= CONVERSION_FACTOR_MILLIMETER;
            break;
        case 5:
            length *= CONVERSION_FACTOR_CENTIMETER;
            break;
        default:
            std::cout << "Invalid length unit number\n";
            return 1;
    }
    std::cout << "Length is " << length << " meters\n";

    return 0;
}