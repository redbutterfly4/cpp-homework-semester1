#include <iostream>
#include <vector>

int main()
{
    std::vector<std::string> cycleColors{"Green", "Red", "Yellow", "White", "Black"};
    std::vector<std::string> subcycleAnimals
        {"Rat", "Ox", "Tiger", "Rabbit", "Dragon", "Snake", "Horse", "Goat", "Monkey", "Rooster", "Dog", "Pig"};

    unsigned year;
    std::cout << "Enter year: ";
    std::cin >> year;

    constexpr unsigned CYCLE_LENGTH = 60;
    constexpr unsigned ANIMAL_CYCLE_LENGTH = 12;
    constexpr unsigned COLOR_CYCLE_LENGTH = 10;  // Color cycle length (5 colors, each lasts 2 years)

    // The 60-year cycle starts at 0004
    unsigned baseYear = 4;

    // Find the offset from the base year
    unsigned yearOffset = (year - baseYear) % CYCLE_LENGTH;
    unsigned yearAnimalIndex = yearOffset % ANIMAL_CYCLE_LENGTH;

    // Calculate the color index (each color lasts for 2 years, hence divide by 2)
    unsigned cycleColorIndex = (yearOffset % COLOR_CYCLE_LENGTH) / 2;

    const std::string &yearColor = cycleColors[cycleColorIndex];
    const std::string &yearAnimal = subcycleAnimals[yearAnimalIndex];

    std::cout << year << " is " << yearColor << ' ' << yearAnimal << " year." << std::endl;

    return 0;
}