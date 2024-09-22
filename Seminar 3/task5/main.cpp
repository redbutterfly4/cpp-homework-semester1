#include <iostream>
#include <vector>

int main() {
    long long number;
    std::cout << "Enter a number: ";
    std::cin >> number;

    long long tmp = number;
    std::vector<long long> factors;
    while (tmp % 2 == 0) {
        factors.push_back(2);
        tmp /= 2;
    }
    for (long long i = 3; i * i <= tmp; i += 2) {
        while (tmp % i == 0) {
            factors.push_back(i);
            tmp /= i;
        }
    }
    if (tmp > 1) {
        factors.push_back(tmp);
    }

    std::cout << "Prime factors: ";
    for (long long factor : factors) {
        std::cout << factor << ' ';
    }
    std::cout << std::endl;

    return 0;
}
