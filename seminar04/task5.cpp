#include <iostream>
#include <vector>

template<typename T>
void transposeMatrix(std::vector<std::vector<T>> &);

template<typename T>
std::vector<std::vector<T>> readMatrix();

template<typename T>
void printMatrix(const std::vector<std::vector<T>> &vec, std::string_view label);

int main()
{
    auto matrix = readMatrix<int>();
    transposeMatrix(matrix);
    printMatrix(matrix, "Result matrix:\n");
}

template<typename T>
void transposeMatrix(std::vector<std::vector<T>> &matrix)
{
    std::vector<std::vector<T>> newMatrix(matrix.back().size(), std::vector<T>(matrix.size()));
    for (int i = 0; i < matrix.back().size(); ++i) {
        for (int j = 0; j < matrix.size(); ++j) {
            newMatrix[i][j] = matrix[j][i];
        }
    }
    matrix.clear();
    matrix = newMatrix;
}

template<typename T>
std::vector<std::vector<T>> readMatrix()
{
    std::cout << "Enter rows: ";
    std::size_t rows;
    std::cin >> rows;

    std::cout << "Enter columns: ";
    std::size_t columns;
    std::cin >> columns;

    std::cout << "Enter " << rows << 'x' << columns << " matrix:\n";
    std::vector<std::vector<T>> matrix(rows, std::vector<T>(columns));
    for (auto &row: matrix) {
        for (auto &el: row) {
            std::cin >> el;
        }
    }
    return matrix;
}

template<typename T>
void printMatrix(const std::vector<std::vector<T>> &vec, std::string_view label)
{
    std::cout << label;
    for (const auto &row: vec) {
        for (auto el: row) {
            std::cout << el << ' ';
        }
        std::cout << '\n';
    }
}