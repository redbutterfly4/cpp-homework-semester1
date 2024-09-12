#include <iostream>
#include <vector>


int nth_prime_boundary(const int n) {
    if (n < 4)
        return 10;
    if (n < 25)
        return 100;
    if (n < 168)
        return 1000;
    if (n < 1229)
        return 1e4;
    if (n < 9592)
        return 1e5;
    if (n < 78498)
        return 1e6;
    if (n < 664579)
        return 1e7;
    if (n < 5761455)
        return 1e8;

    return 1e9;
}

// Find the first N prime numbers.
int main() {
    int number;
    std::cout << "Enter a number: ";
    std::cin >> number;

    // Determine the upper limit for the sieve
    int upper_limit_for_sieve = nth_prime_boundary(number);

    // Run sieve of Eratosthenes up to "upper_limit_for_sieve"
    std::vector<bool> is_prime(upper_limit_for_sieve + 1, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i <= upper_limit_for_sieve; ++i)
        if(is_prime[i])
            if(i * 1ll * i <= upper_limit_for_sieve)
                for (int j = i * i; j <= upper_limit_for_sieve; j += i)
                    is_prime[j] = false;


    // Push back the first N numbers for which is_prime[i] is true
    std::vector<int> primes;
    for (int i = 2; i <= upper_limit_for_sieve; ++i) {
        if(is_prime[i])
            primes.push_back(i);

        if(primes.size() == number) {
            break;
        }
    }

    // Output the first N prime numbers
    std::cout << "First " << primes.size() << " prime numbers:\n";
    for (int j : primes)
        std::cout << j << ' ';
    std::cout << '\n';


    return 0;
}

