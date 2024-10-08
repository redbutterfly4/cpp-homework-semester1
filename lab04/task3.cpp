#include <iostream>
#include <vector>

std::vector<int> readVector();
bool isPermutation(const std::vector<int> &);

int main()
{
    std::vector<int> numbers = readVector();
    bool vectorIsPermutation = isPermutation(numbers);
    if (vectorIsPermutation) {
        std::cout << "Vector is a permutation." << std::endl;
    }
    else {
        std::cout << "Vector isn't a permutation." << std::endl;
    }
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

bool isPermutation(const std::vector<int> &numbers)
{
    constexpr int FIRST_NUMBER = 1;
    const int LAST_NUMBER = static_cast<int>(numbers.size());
    std::vector<bool> hasNumber(LAST_NUMBER + 1);
    for (int el: numbers) {
        if (FIRST_NUMBER <= el && el <= LAST_NUMBER) {
            hasNumber[el] = true;
        }
        else {
            // Return false when a vector contains a number that a permutation could not contain
            return false;
        }
    }

    // Check that the vector contains all numbers that the permutation must contain
    for (int i = FIRST_NUMBER; i <= LAST_NUMBER; ++i) {
        if (!hasNumber[i]) {
            // Return false when the vector doesn't contain the number that the permutation must contain
            return false;
        }
    }

    return true;
}