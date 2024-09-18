#include <iostream>


int main() {
    std::cout << "Enter a number: ";
    int number;
    std::cin >> number;


    int tmp = number;
    int sum = 0;
    while(tmp > 0) {
        sum += tmp % 10;
        tmp /= 10;
    }


    std::cout << "The sum is: " << sum << std::endl;
    return 0;
}

