#include <iostream>
#include <string>
#include <string_view>

bool isValidCardNumber(std::string_view);

int main()
{
    std::cout << "Enter card number: ";
    std::string cardNumber;
    std::cin >> cardNumber;

    std::cout << "Card is valid - " << std::boolalpha << isValidCardNumber(cardNumber) << std::endl;
    return 0;
}

bool isValidCardNumber(std::string_view cardNumber)
{
    int sum1 = 0; // Sum of products' digits that were multiplied by 2
    int sum2 = 0; // Sum of digits that weren't multiplied by 2
    int i = 0;
    for (char c: cardNumber) {
        if (i % 2 == 0) {
            int doubledDigit = (c - '0') * 2;
            while (doubledDigit) {
                sum1 += doubledDigit % 10;
                doubledDigit /= 10;
            }
        }
        else {
            int digit = c - '0';
            sum2 += digit;
        }
        ++i;
    }
    int total = sum1 + sum2;
    return total % 10 == 0;
}