#include <iostream>
#include <vector>

std::vector<std::vector<int>> readSets(std::size_t);

void printResult(const std::vector<std::vector<int>> &);

template<typename T>
T readVariable(std::string_view label);

int main()
{
    auto k = readVariable<std::size_t>("Enter k: ");
    auto sets = readSets(k);
    printResult(sets);
}

template<typename T>
T readVariable(std::string_view label)
{
    std::cout << label;
    T tmp;
    std::cin >> tmp;
    return tmp;
}

std::vector<std::vector<int>> readSets(std::size_t k)
{
    std::vector<std::vector<int>> sets(k);
    for (int i = 0; i < k; ++i) {
        std::cout << "Enter row " << i + 1 << ": ";
        int num;
        do {
            std::cin >> num;
            if (num != 0) {
                sets[i].push_back(num);
            }
        }
        while (num != 0);
    }
    return sets;
}

void printResult(const std::vector<std::vector<int>> &vec)
{
    std::size_t totalSize = 0;
    for (auto it = vec.begin(); it != vec.end(); ++it) {
        std::cout << "Row " << (it - vec.begin()) << " has " << it->size() << " elements.\n";
        totalSize += it->size();
    }
    std::cout << "Total number of elements: " << totalSize << '\n';
}