#include <iostream>

int main()
{
    std::cout << "Enter x: ";
    int x;
    std::cin >> x;

    std::cout << "Enter y: ";
    int y;
    std::cin >> y;

    // Use all arithmetic operators
    int unaryPlusResult = +x;
    std::cout << "unaryPlusResult = " << unaryPlusResult << '\n';

    int unaryMinusResult = -x;
    std::cout << "unaryMinusResult = " << unaryMinusResult << '\n';

    int additionResult = x + y;
    std::cout << "additionResult = " << additionResult << '\n';

    int subtractionResult = x - y;
    std::cout << "subtractionResult = " << subtractionResult << '\n';

    int multiplicationResult = x * y;
    std::cout << "multiplicationResult = " << multiplicationResult << '\n';

    int divisionResult = x / y;
    std::cout << "divisionResult = " << divisionResult << '\n';

    int remainderResult = x % y;
    std::cout << "remainderResult = " << remainderResult << '\n';

    int bitwiseNotResult = ~x;
    std::cout << "bitwiseNotResult = " << bitwiseNotResult << '\n';

    int bitwiseAndResult = x & y;
    std::cout << "bitwiseAndResult = " << bitwiseAndResult << '\n';

    int bitwiseOrResult = x | y;
    std::cout << "bitwiseOrResult = " << bitwiseOrResult << '\n';

    int bitwiseXorResult = x ^ y;
    std::cout << "bitwiseXorResult = " << bitwiseXorResult << '\n';

    int bitwiseLeftShiftResult = x << y;
    std::cout << "bitwiseLeftShiftResult = " << bitwiseLeftShiftResult << '\n';

    int bitwiseRightShiftResult = x >> y;
    std::cout << "bitwiseRightShiftResult = " << bitwiseRightShiftResult << std::endl;
}