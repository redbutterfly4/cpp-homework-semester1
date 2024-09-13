#include <iostream>
#include <vector>

// Check if number is a palindrome
int main() {
    int number;
    std::cout << "Enter a number: ";
    std::cin >> number;

    if (number < 0) {
        std::cout << "Number " << number << " is not a palindrome.\n";
        return 0;
    }

    // Find the reversed version of the initial number
    int reversed_number = 0;
    int temp = number;
    while (temp != 0) {
        reversed_number *= 10;
        reversed_number += temp % 10;
        temp /= 10;
    }

    if(reversed_number == number) {
        std::cout << "Number " << number << " is a palindrome.\n";
    } else {
        std::cout << "Number " << number << " is not a palindrome.\n";
    }


    return 0;
}

