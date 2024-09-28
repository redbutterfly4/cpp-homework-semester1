#include <iostream>
#include <bitset>

void outputSequence();

int main()
{
    outputSequence();
    // The output figure is a triangular fractal or Sierpinski triangle
}

void outputSequence()
{
    constexpr std::size_t TOTAL_NUMBERS = 10000;
    std::bitset<TOTAL_NUMBERS + 1> lastBitset(1);
    std::cout << "1\n"; // Print the initial number
    for (int i = 0; i < TOTAL_NUMBERS; ++i) {
        std::bitset<TOTAL_NUMBERS + 1>
            newBitset = (lastBitset << 1) ^ lastBitset; // Calculate a new bitset using a given formula
        for (int j = 0; j <= TOTAL_NUMBERS; ++j) {
            if (newBitset[j]) {
                std::cout << '1';
            }
            else {
                std::cout << ' ';
            }
        }
        std::cout << '\n'; // Move to the next line after printing the current bitset
        lastBitset = newBitset;
    }
}






