#include <iostream>

int main()
{
    std::cout << "Enter speed of the first car in km/h: ";
    double speed1;
    std::cin >> speed1;

    std::cout << "Enter speed of the second car in km/h: ";
    double speed2;
    std::cin >> speed2;

    if (speed1 <= speed2) {
        std::cout << "The speed of the first car must be greater than the speed of the second car." << std::endl;
        return 0;
    }

    std::cout << "Enter the distance in kilometers by which the first car is ahead of the second car: ";
    double initialDistance;
    std::cin >> initialDistance;

    constexpr double HOURS = 0.5;

    // Find the requested distance
    double distance = initialDistance + HOURS * (speed1 - speed2);

    std::cout << "The first car is " << distance << " kilometers ahead of the second car." << std::endl;
}