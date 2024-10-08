#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <cmath>

std::pair<double, double> findAverage(const std::vector<int> &);

template<typename T>
std::vector<T> readVector(std::string_view vectorName = "vector");

int main()
{
    auto vec = readVector<int>();
    auto [geometricAverage, arithmeticAverage] = findAverage(vec);
    std::cout << "Geometric average of positive numbers = " << geometricAverage << '\n';
    std::cout << "Arithmetic average of negative numbers = " << arithmeticAverage << '\n';
}

std::pair<double, double> findAverage(const std::vector<int> &vec)
{
    const int countPositive = static_cast<int>(std::count_if(vec.begin(), vec.end(), [](int i)
    { return i > 0; }));
    const int countNegative = static_cast<int>(std::count_if(vec.begin(), vec.end(), [](int i)
    { return i < 0; }));

    double arithmeticAverage = .0;
    double geometricAverage = 1.;
    const double power = 1. / countPositive;
    for (int el: vec) {
        if (el < 0) {
            arithmeticAverage += (el * 1.0) / countNegative;
        }
        else if (el > 0) {
            geometricAverage *= std::pow(el, power);
        }
    }
    return {geometricAverage, arithmeticAverage};
}

template<typename T>
std::vector<T> readVector(std::string_view vectorName)
{
    std::cout << "Enter size of the " << vectorName << ": ";
    std::size_t size;
    std::cin >> size;
    std::cout << "Enter " << size << " elements of the vector: ";
    std::vector<int> vec(size);
    for (int &el: vec) {
        std::cin >> el;
    }
    return vec;
}