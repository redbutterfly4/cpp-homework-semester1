#include <iostream>
#include <vector>
#include <utility>

std::vector<std::pair<int, int>> findPairs(int);

int main()
{
    std::cout << "Enter a number: ";
    int number;
    std::cin >> number;

    std::vector<std::pair<int, int>> pairs = findPairs(number);
    std::cout << "There are " << pairs.size() << " pairs:\n";
    for (auto pair: pairs) {
        std::cout << pair.first << ' ' << pair.second << '\n';
    }
}

std::vector<std::pair<int, int>> findPairs(int num)
{
    int squaredNum = num * num;
    std::vector<std::pair<int, int>> pairs;
    for (int x = 0; x < num; ++x) {
        int squaredX = x * x;
        for (int y = 0; squaredX + y * y < squaredNum; ++y) {
            pairs.emplace_back(x, y);
        }
    }
    return pairs;
}
