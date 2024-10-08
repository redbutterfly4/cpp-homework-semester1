#include <iostream>
#include <vector>
#include <string_view>
#include <numeric>

struct fraction
{
    int numerator;
    int denominator;

    bool operator<(fraction b) const
    {
        double value1 = numerator * 1.0 / denominator;
        double value2 = b.numerator * 1.0 / b.denominator;
        return value1 < value2;
    }
};

template<typename T>
T readVariable(std::string_view label);

std::vector<fraction> calculateSequence(int k);
void printSequence(const std::vector<fraction> &vec, std::string_view label);

int main()
{
    int n = readVariable<int>("Enter n: ");
    auto sequence = calculateSequence(n);
    printSequence(sequence, "Result sequence:\n");
}

std::vector<fraction> calculateSequence(int k)
{
    std::vector<fraction> result;
    for (int denominator = k - 1; denominator >= 2; --denominator) {
        for (int numerator = 1; numerator < denominator; ++numerator) {
            if (std::gcd(numerator, denominator) == 1) {
                result.push_back({numerator, denominator});
            }
        }
    }
    std::sort(result.begin(), result.end());
    return result;
}

template<typename T>
T readVariable(std::string_view label)
{
    std::cout << label;
    T tmp;
    std::cin >> tmp;
    return tmp;
}

void printSequence(const std::vector<fraction> &vec, std::string_view label)
{
    std::cout << label;
    for (auto el: vec) {
        std::cout << el.numerator << '/' << el.denominator << '\n';
    }
}