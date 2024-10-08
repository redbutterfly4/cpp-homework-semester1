#include <iostream>
#include <algorithm>


void removeZeros(std::vector<int> &);

template<typename T>
std::vector<T> readVector(std::string_view vectorName = "vector");

template<typename T>
void printVector(const std::vector<T> &vec, std::string_view label, std::string_view separator);

int main()
{
    auto vec = readVector<int>();
    removeZeros(vec);
    printVector(vec, "Result vector: ", ", ");
}

void removeZeros(std::vector<int> &vec)
{
    for (int i = 0, j = 0; j < vec.size(); ++i, ++j) {
        while (j < vec.size() && vec[j] == 0) {
            ++j;
        }
        if (j == vec.size()) {
            break;
        }
        if (vec[i] == 0) {
            std::swap(vec[i], vec[j]);
        }
    }
    auto firstZeroIt = std::find(vec.begin(), vec.end(), 0);
    std::size_t newSize = static_cast<std::size_t>(firstZeroIt - vec.begin());
    vec.resize(newSize);
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
// 1 2 0 4 5 0 7
// 1 2 4 5 0