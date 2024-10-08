#include <iostream>
#include <string_view>
#include <vector>

std::vector<int> readVector();
void reverseVector(std::vector<int> &);

template<typename T>
void printVector(const std::vector<T> &vec, std::string_view label, std::string_view separator);

int main()
{
    std::vector<int> initialVector = readVector();
    reverseVector(initialVector);
    printVector(initialVector, "Result vector: ", ", ");
    return 0;
}

std::vector<int> readVector()
{
    std::cout << "Enter size of the vector: ";
    std::size_t size;
    std::cin >> size;

    std::cout << "Enter " << size << " elements of the vector: ";
    std::vector<int> vec(size);
    for (int &el: vec) {
        std::cin >> el;
    }
    return vec;
}

void reverseVector(std::vector<int> &vec)
{
    // Reverses the vector 'vec' in place by swapping elements from both ends.
    for (std::size_t i = 0, j = vec.size() - 1; i < j; ++i, --j) {
        std::swap(vec[i], vec[j]);
    }
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