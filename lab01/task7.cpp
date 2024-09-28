#include <iostream>

int main()
{
    // Without using any other arithmetic operations other than addition, subtraction and multiplication
    // calculate expressions 4x^3 + 3x^2 + 2x + 1 and -4x^3 + 3x^2 - 2x + 1
    // No more than 8 operations should be used in total
    // Variables 'a[n]' represent 'a' raised to the power of 'n' (a^n).

    std::cout << "Enter x: ";
    double x;
    std::cin >> x;

    double doubledX = x * 2.0; // 1 operation, 1 in total
    double doubledSquare = doubledX * x; // 1 operation, 2 in total
    double fourTimesCubic = doubledX * doubledSquare; // 1 operation, 3 in total
    double threeTimesSquare = doubledSquare * 1.5; // 1 operation, 4 in total
    double tmp1 = threeTimesSquare + 1; // 1 operation, 5 in total, tmp1 = 3x^2 + 1
    double tmp2 = fourTimesCubic + doubledX; // 1 operation, 6 in total, tmp2 = 4x^3 + 2x
    double result1 = tmp1 + tmp2; // 1 operation, 7 in total
    double result2 = tmp1 - tmp2; // 1 operation, 8 in total

    std::cout << "First expression equals " << result1 << '\n';
    std::cout << "Second expression equals " << result2 << std::endl;
}