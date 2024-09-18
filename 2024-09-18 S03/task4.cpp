#include <iostream>
#include <vector>


int main() {
    int numberOfPrimes;
    std::cout << "Enter a number: ";
    std::cin >> numberOfPrimes;


    int upperLimitForSieve;
    if (numberOfPrimes < 1229) {
        upperLimitForSieve = 1e4;
    } else if (numberOfPrimes < 9592) {
        upperLimitForSieve = 1e5;
    } else if (numberOfPrimes < 78498) {
        upperLimitForSieve = 1e6;
    } else if (numberOfPrimes < 664579) {
        upperLimitForSieve = 1e7;
    } else if (numberOfPrimes < 5368709) {
        upperLimitForSieve = 1e8;
    } else {
        upperLimitForSieve = 1e9;
    }


    // Run sieve of Eratosthenes up to "upper_limit_for_sieve"
    std::vector<bool> isPrime(upperLimitForSieve + 1, true);
    isPrime[0] = false;
    isPrime[1] = false;
    for (int i = 2; i <= upperLimitForSieve; ++i) {
        if(isPrime[i]) {
            if(i * 1ll * i <= upperLimitForSieve) {
                for (int j = i * i; j <= upperLimitForSieve; j += i) {
                    isPrime[j] = false;
                }
            }
        }
    }


    // Push back the first N numbers for which isPrime[i] is true
    std::vector<int> primes;
    for (int i = 2; i <= upperLimitForSieve && primes.size() < numberOfPrimes; ++i) {
        if(isPrime[i]) {
            primes.push_back(i);
        }
    }


    // If needed, check additional numbers for being prime and add them to the vector.
    int lastCheckedNumber = primes.back();
    while (primes.size() < numberOfPrimes) {
        ++lastCheckedNumber;
        int number = lastCheckedNumber;
        bool isPrimeNumber = true;
        for (int i = 2; i * i <= number; ++i) {
            if (number % i == 0) {
                isPrimeNumber = false;
            }
        }
        if(isPrimeNumber) {
            primes.push_back(number);
        }
    }


    std::cout << "First " << primes.size() << " prime numbers are: ";
    for (int primeNumber : primes) {
        std::cout << primeNumber << ' ';
    }
    std::cout << std::endl;


    return 0;
}
