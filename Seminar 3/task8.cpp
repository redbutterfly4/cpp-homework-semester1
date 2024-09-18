#include <iostream>
#include <vector>


int main() {
    std::cout << "Enter a number: ";
    size_t number;
    std::cin >> number;


    std::vector<uint64_t> fibonacciNumbers(number);
    fibonacciNumbers[0] = 0;
    fibonacciNumbers[1] = 1;
    for (size_t i = 2; i < number; ++i) {
        fibonacciNumbers[i] = fibonacciNumbers[i - 1] + fibonacciNumbers[i - 2];
    }


    if (fibonacciNumbers.size() == number) {
        std::cout << "Successfully found " << fibonacciNumbers.size() << " Fibonacci numbers: ";
    } else {
        std::cout << "Found only " << fibonacciNumbers.size() << " Fibonacci numbers: ";
    }
    for (uint64_t fibonacciNumber : fibonacciNumbers) {
        std::cout << fibonacciNumber << ' ';
    }
    std::cout << std::endl;
    return 0;
}
