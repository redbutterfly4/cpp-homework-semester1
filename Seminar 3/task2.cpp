#include <iostream>


int main() {
    std::cout << "Enter a number: ";
    int number;
    std::cin >> number;


    int tmp = number;
    int bitCount = 0;
    while (tmp > 0) {
        bitCount += (tmp & 1);
        tmp >>= 1;
    }
    std::cout << "Number of bits equal to 1: " << bitCount << std::endl;


    return 0;
}

