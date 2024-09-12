#include <iostream>
#include <vector>

// Find all divisors of a number
int main() {
    int number;
    std::cout << "Enter a number: ";
    std::cin >> number;

    // Find all divisors and push_back them into a vector.
    std::vector<int> divisors;
    for(int i = 1; i * i <= number; ++i) {
        if(number % i == 0) {
            divisors.push_back(i);
            if(i != number / i)
                divisors.push_back(number / i);
        }
    }

    std::sort(divisors.begin(), divisors.end());

    std::cout << "Divisors of " << number << " are: ";
    for(int i : divisors) {
        std::cout << i << ' ';
    }
    std::cout << '\n';

    return 0;
}

