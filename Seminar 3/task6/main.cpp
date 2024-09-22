#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    uint64_t number;
    std::cout << "Enter a number: ";
    std::cin >> number;

    constexpr int HEX_BASE = 16;
    std::string result;
    uint64_t tmp = number;
    while (tmp != 0) {
        int digit = tmp % HEX_BASE;
        char digitChar;
        if (digit < 10) {
            digitChar = '0' + digit;
        } else {
            digitChar = 'a' + (digit - 10);
        }
        result.push_back(digitChar);
        tmp /= HEX_BASE;
    }
    std::reverse(result.begin(), result.end());

    std::cout << "Result is " << result << std::endl;
    std::cout << "Result using std::hex is " << std::hex << number << std::endl;
    return 0;
}

