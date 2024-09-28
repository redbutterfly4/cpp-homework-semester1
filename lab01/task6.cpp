#include <iostream>

int main()
{
    // Compute powers of 'a' for specific exponents: a^4, a^6, a^7, a^8, a^9, a^10, a^13, a^15, a^21, a^28, a^64
    // using only the multiplication operator
    // Variables 'a[n]' represent 'a' raised to the power of 'n' (a^n).

    std::cout << "Enter a: ";
    double a;
    std::cin >> a;

    double a2 = a * a;

    double a4 = a2 * a2;
    std::cout << "a^4 = " << a4 << '\n';

    double a6 = a2 * a4;
    std::cout << "a^6 = " << a6 << '\n';

    double a7 = a6 * a;
    std::cout << "a^7 = " << a7 << '\n';

    double a8 = a4 * a4;
    std::cout << "a^8 = " << a8 << '\n';

    double a9 = a8 * a;
    std::cout << "a^9 = " << a9 << '\n';

    double a10 = a8 * a2;
    std::cout << "a^10 = " << a10 << '\n';

    double a13 = a8 * a4 * a;
    std::cout << "a^13 = " << a13 << '\n';

    double a15 = a8 * a7;
    std::cout << "a^15 = " << a15 << '\n';

    double a16 = a8 * a8;

    double a21 = a16 * a4 * a;
    std::cout << "a^21 = " << a21 << '\n';

    double a28 = a16 * a8 * a4;
    std::cout << "a^28 = " << a28 << '\n';

    double a32 = a16 * a16;

    double a64 = a32 * a32;
    std::cout << "a^64 = " << a64 << '\n';
}