#include <iostream>

int main()
{
    unsigned x1;
    std::cout << "Enter x1: ";
    std::cin >> x1;
    --x1;
    // Since x1 is an unsigned integer, after decrementing, the condition x1 > 7 ensures that
    // the original value was between 1 and 8, inclusive. This prevents inputs less than 1 or greater than 8.
    while (x1 > 7) {
        std::cout << "x1 must be between 1 and 8." << std::endl;
        std::cout << "Enter new x1: ";
        std::cin >> x1;
        --x1;
    }

    unsigned y1;
    std::cout << "Enter y1: ";
    std::cin >> y1;
    --y1;
    // The condition y1 > 7 ensures that the original value was between 1 and 8, inclusive.
    while (y1 > 7) {
        std::cout << "y1 must be between 1 and 8." << std::endl;
        std::cout << "Enter new y1: ";
        std::cin >> y1;
        --y1;
    }

    unsigned x2;
    std::cout << "Enter x2: ";
    std::cin >> x2;
    --x2;
    // The condition x2 > 7 ensures that the original value was between 1 and 8, inclusive.
    while (x2 > 7) {
        std::cout << "x2 must be between 1 and 8." << std::endl;
        std::cout << "Enter new x2: ";
        std::cin >> x2;
        --x2;
    }

    unsigned y2;
    std::cout << "Enter y2: ";
    std::cin >> y2;
    --y2;
    // The condition y2 > 7 ensures that the original value was between 1 and 8, inclusive.
    while (y2 > 7) {
        std::cout << "y2 must be between 1 and 8." << std::endl;
        std::cout << "Enter new y2: ";
        std::cin >> y2;
        --y2;
    }

    bool canMove = x1 == x2 || y1 == y2;
    if (canMove) {
        std::cout << "The rook can move from the first square to another square in 1 move." << std::endl;
    }
    else {
        std::cout << "The rook can't move from the first square to another square in 1 move." << std::endl;
    }

    return 0;
}