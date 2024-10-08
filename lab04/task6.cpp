#include <iostream>
#include <vector>
#include <cstdint>

class Matrix
{
    std::vector<std::vector<int64_t>> matrix_;
    std::size_t rows = 0;
    std::size_t columns = 0;

public:
    explicit Matrix(const std::vector<std::vector<int64_t>> &matrix)
        : matrix_(matrix)
    {
        rows = matrix.size();
        columns = matrix.back().size();
    };

    Matrix() = default;

    void readFromUser()
    {
        std::cout << "Enter number of rows: ";
        std::cin >> rows;
        std::cout << "Enter number of columns: ";
        std::cin >> columns;
        matrix_.resize(rows, std::vector<int64_t>(columns));
        std::cout << "Enter " << rows << 'x' << columns << " matrix:\n";
        for (auto &row: matrix_) {
            for (auto &el: row) {
                std::cin >> el;
            }
        }
    }

    Matrix operator*(const Matrix &b)
    {
        if (columns != b.rows) {
            std::cout << "The number of columns of the 1st matrix must equal the number of rows of the 2nd matrix\n";
            exit(1);
        }
        std::size_t resultRows = rows;
        std::size_t resultColumns = b.columns;
        std::vector<std::vector<int64_t>> newMatrix(resultRows, std::vector<int64_t>(resultColumns));
        for (std::size_t i = 0; i < resultRows; ++i) {
            for (std::size_t j = 0; j < resultColumns; ++j) {
                for (std::size_t k = 0; k < columns; ++k) {
                    newMatrix[i][j] += matrix_[i][k] * b.matrix_[k][j];
                }
            }
        }
        return Matrix(newMatrix);
    }

    void print()
    {
        std::cout << rows << 'x' << columns << " matrix:\n";
        for (const auto &row: matrix_) {
            for (auto number: row) {
                std::cout << number << ' ';
            }
            std::cout << '\n';
        }
    }
};

int main()
{
    Matrix matrix1;
    matrix1.readFromUser();
    Matrix matrix2;
    matrix2.readFromUser();

    Matrix resultMatrix = matrix1 * matrix2;
    resultMatrix.print();
    return 0;
}