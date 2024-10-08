#include <iostream>
#include <array>
#include <algorithm>

template<std::size_t SIZE>
void rearrange(std::array<int, SIZE> &);

template<std::size_t SIZE>
void printArray(const std::array<int, SIZE> &arr);

template<std::size_t SIZE>
std::array<int, SIZE> readArray();

int main()
{
    constexpr std::size_t ARRAY_SIZE = 7;
    auto arr = readArray<ARRAY_SIZE>();
    rearrange(arr);
    printArray(arr);
}

template<std::size_t SIZE>
void rearrange(std::array<int, SIZE> &arr)
{
    // Put the negative elements at the beginning
    for (std::size_t i = 0, j = 1; j < arr.size(); ++i, ++j) {
        // Skip elements that are already negative
        while (i < arr.size() && arr[i] < 0) {
            ++i;
        }
        if (i == arr.size()) {
            break;
        }
        // Find nearest negative element
        while (j < arr.size() && (arr[j] >= 0 || j <= i)) {
            ++j;
        }
        if (j == arr.size()) {
            break;
        }
        std::swap(arr[i], arr[j]);

    }
    // Put the positive elements at the end
    for (int i = arr.size() - 1, j = i - 1; j >= 0 && arr[j] >= 0; --i, --j) {
        // Skip element if it's already positive
        if (arr[i] > 0) {
            continue;
        }
        // Find nearest positive element
        while (j >= 0 && arr[j] <= 0) {
            --j;
        }
        if (j < 0) {
            break;
        }
        std::swap(arr[i], arr[j]);
    }
}

template<std::size_t SIZE>
void printArray(const std::array<int, SIZE> &arr)
{
    std::cout << "Result array: ";
    for (auto el: arr) {
        std::cout << el << ' ';
    }
    std::cout << '\n';
}

template<std::size_t SIZE>
std::array<int, SIZE> readArray()
{
    std::cout << "Enter " << SIZE << " elements or array: ";
    std::array<int, SIZE> arr{};
    for (std::size_t i = 0; i < SIZE; ++i) {
        std::cin >> arr[i];
    }
    return arr;
}