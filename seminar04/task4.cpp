#include <iostream>
#include <unordered_map>

template<typename T>
std::vector<T> readVector(std::string_view vectorName = "vector");

bool isPermutation(const std::vector<int> &v1, const std::vector<int> &v2);

int main()
{
    auto vec1 = readVector<int>();
    auto vec2 = readVector<int>();
    bool vecIsPermutation = isPermutation(vec1, vec2);
    std::cout << "Vector 1 is a permutation of vector 2 - " << std::boolalpha << vecIsPermutation << '\n';
}

bool isPermutation(const std::vector<int> &v1, const std::vector<int> &v2)
{
    if (v1.size() != v2.size()) {
        return false;
    }
    std::unordered_map<int, int> numberCount1;
    for (int el: v1) {
        ++numberCount1[el];
    }
    std::unordered_map<int, int> numberCount2;
    for (int el: v2) {
        ++numberCount2[el];
    }

    for (auto el: numberCount1) {
        int count1 = el.second;
        int count2 = numberCount2[el.first];
        if (count1 != count2) {
            return false;
        }
    }
    return true;
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