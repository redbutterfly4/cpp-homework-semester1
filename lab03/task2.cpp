#include <iostream>
#include <string_view>

bool isCycled(int64_t);
int64_t readNumber(std::string_view);

int main()
{
    int64_t number = readNumber("Enter a number: ");

    bool isCycledNumber = isCycled(number);
    std::cout << "The number is cycled - " << std::boolalpha << isCycledNumber << std::endl;
    return 0;
}

bool isCycled(int64_t a)
{
    constexpr int NUMBER_OF_ITERATIONS = 100000;
    for (int i = 0; i < NUMBER_OF_ITERATIONS; ++i) {
        if (a % 2 == 1) {
            a = a * 3 + 1;
        }
        else {
            a /= 2;
        }
        if (a == 1) {
            return false;
        }
    }
    return true;
}

int64_t readNumber(std::string_view label)
{
    std::cout << label;
    int64_t number;
    std::cin >> number;
    return number;
}