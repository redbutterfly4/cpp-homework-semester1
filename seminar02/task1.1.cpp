#include <iostream>

int main()
{
    std::cout << "Enter a: ";
    int a;
    std::cin >> a;

    std::cout << "Enter b: ";
    int b;
    std::cin >> b;

    std::cout << "Enter c: ";
    int c;
    std::cin >> c;

    if (a < 0) {
        a = a * a;
    }
    else if (a > 0) {
        a = a * a * a;
    }

    if (b < 0) {
        b = b * b;
    }
    else if (b > 0) {
        b = b * b * b;
    }

    if (c < 0) {
        c = c * c;
    }
    else if (c > 0) {
        c = c * c * c;
    }

    std::cout << "a = " << a << '\n';
    std::cout << "b = " << b << '\n';
    std::cout << "c = " << c << std::endl;

    return 0;
}