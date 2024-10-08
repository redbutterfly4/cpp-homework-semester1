#include <iostream>
#include <vector>
#include <string_view>

template<typename T>
std::vector<T> readVector(std::string_view);

template<typename T>
std::vector<T> findCommonElements(const std::vector<T> &, const std::vector<T> &);

template<typename T>
void printVector(const std::vector<T> &vec, std::string_view label, std::string_view separator);

int main()
{
    // Assuming that both vectors are non-decreasing, find the number of common elements
    std::vector<int> vec1 = readVector<int>("first vector");
    std::vector<int> vec2 = readVector<int>("second vector");
    std::vector<int> commonElements = findCommonElements(vec1, vec2);
    printVector(commonElements, "Common elements: ", ", ");
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
std::vector<T> findCommonElements(const std::vector<T> &vec1, const std::vector<T> &vec2)
{
    std::vector<T> commonElements;
    auto it1 = vec1.begin();
    auto it2 = vec2.begin();
    while (it1 != vec1.end() && it2 != vec2.end()) {
        if (*it1 == *it2) {
            commonElements.push_back(*it1);
            ++it1;
            ++it2;
        }
        else if (*it1 < *it2) {
            ++it1;
        }
        else {
            ++it2;
        }
    }
    return commonElements;
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