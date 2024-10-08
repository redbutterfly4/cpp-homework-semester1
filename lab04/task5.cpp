#include <iostream>
#include <string_view>
#include <vector>

template<typename T>
std::vector<T> readVector(std::string_view vectorName = "vector");

template<typename T>
void printVector(const std::vector<T> &vec, std::string_view label, std::string_view separator);

template<typename T>
T readVariable(std::string_view label);

void reverseFrom(std::vector<int> &vec, int n);

int main()
{
    std::vector<int> vec = readVector<int>();
    int n = readVariable<int>("Enter n: ");
    reverseFrom(vec, n);
    printVector(vec, "Result vector: ", ", ");
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

template<typename T>
void printVector(const std::vector<T> &vec, std::string_view label, std::string_view separator)
{
    std::cout << label;
    for (auto it = vec.begin(); it != vec.end(); ++it) {
        std::cout << *it;

        // Output the separator only if the current element is not the last one
        if (it + 1 != vec.end()) {
            std::cout << separator;
        }
    }
    std::cout << std::endl;
}

template<typename T>
T readVariable(std::string_view label)
{
    std::cout << label;
    T tmp;
    std::cin >> tmp;
    return tmp;
}

void reverseFrom(std::vector<int> &vec, int n)
{
    // if N > M, assign a value of M to N so that the algorithm works correctly
    // M = vec.size() - N
    if (2 * n > vec.size()) {
        n = static_cast<int>(vec.size()) - n;
    }

    for (int i = 0; i + n < vec.size(); ++i) {
        std::swap(vec[i], vec[i + n]);
    }
}