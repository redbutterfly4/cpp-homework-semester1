#include <iostream>
#include <cstdint>
#include <limits>
#include <string>
#include <string_view>

int findLowestMissingDigit(int64_t num);
int64_t readNumber(std::string_view);

int main()
{
    int64_t number = readNumber("Enter n: ");
    int missingDigit = findLowestMissingDigit(number);

    constexpr int NONEXISTENT_DIGIT = -1;
    if (missingDigit == NONEXISTENT_DIGIT) {
        std::cout << "Number has all digits from 0 to 9\n";
    }
    else {
        std::cout << "First missing digit is " << missingDigit << '\n';
    }

    return 0;
}

int64_t readNumber(std::string_view label)
{
    std::cout << label;
    std::string input;
    std::cin >> input;
    int64_t number;
    try {
        number = std::stoll(input);
    }
    catch (const std::exception &exception) {
        std::cout << "Number has to be in range from 0 to " << std::numeric_limits<int64_t>::max() << '\n';
        std::cout << "Exception: " << exception.what() << '\n';
        exit(1);
    }
    if (number < 0) {
        std::cout << "Number has to be in range from 0 to " << std::numeric_limits<int64_t>::max() << '\n';
        exit(1);
    }
    return number;
}

int findLowestMissingDigit(int64_t num)
{
    bool hasDigit[10]
        {false}; // Using an array of bool values is faster than using std::set, std::unordered_set, or std::map

    while (num > 0) {
        int currentDigit = static_cast<int>(num % 10LL);
        hasDigit[currentDigit] = true;
        num /= 10;
    }

    constexpr int MAX_DIGIT = 9;
    for (int i = 0; i <= MAX_DIGIT; ++i) {
        if (!hasDigit[i]) {
            return i;
        }
    }

    constexpr int NONEXISTENT_DIGIT = -1;
    return NONEXISTENT_DIGIT;
}