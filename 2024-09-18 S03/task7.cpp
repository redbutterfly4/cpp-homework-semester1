#include <iostream>
#include <vector>


int main() {
    uint64_t inputNumber;
    std::cout << "Enter a number: ";
    std::cin >> inputNumber;

    
    int levelOfPalindromicity = 0;
    uint64_t number = inputNumber;
    uint64_t tmp = number;
    uint64_t reversedNumber = 0;
    while (true) {
        while (tmp != 0) {
            reversedNumber *= 10;
            reversedNumber += tmp % 10;
            tmp /= 10;
        }
        if (number != reversedNumber) {
            ++levelOfPalindromicity;
            number += reversedNumber;
            tmp = number;
            reversedNumber = 0;
        } else {
            break;
        }
    }


    std::cout << "Level of Palindromicity: " << levelOfPalindromicity << std::endl;
    std::cout << "Number: " << number << std::endl;
    return 0;
}
