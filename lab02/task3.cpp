#include <iostream>
#include <cmath>
#include <utility>
#include <vector>

int main()
{
    std::cout << "Enter x0: ";
    long x0;
    std::cin >> x0;

    std::cout << "Enter y0: ";
    long y0;
    std::cin >> y0;

    std::cout << "Enter R0: ";
    double r0;
    std::cin >> r0;
    while (r0 <= .0) {
        std::cout << "Radius must be a positive number" << std::endl << "Enter new R0: ";
        std::cin >> r0;
    }

    std::cout << "Enter x1: ";
    long x1;
    std::cin >> x1;

    std::cout << "Enter y1: ";
    long y1;
    std::cin >> y1;

    std::cout << "Enter R1: ";
    double r1;
    std::cin >> r1;
    while (r1 <= .0) {
        std::cout << "Radius must be a positive number" << std::endl << "Enter new R1: ";
        std::cin >> r1;
    }

    long minX = std::lround(std::min(x0 - r0, x1 - r1)) - 1;
    long minY = std::lround(std::min(y0 - r0, y1 - r1)) - 1;
    long maxX = std::lround(std::max(x0 + r0, x1 + r1)) + 1;
    long maxY = std::lround(std::max(y0 + r0, y1 + r1)) + 1;

    std::vector<std::pair<int, int>> intersectionPoints;
    for (long x = minX; x <= maxX; ++x) {
        for (long y = minY; y <= maxY; ++y) {
            bool isInsideCircle0 = hypot(x - x0, y - y0) <= r0;
            bool isInsideCircle1 = hypot(x - x1, y - y1) <= r1;
            if (isInsideCircle0 && isInsideCircle1) {
                intersectionPoints.emplace_back(x, y);
            }
        }
    }

    std::cout << "There are " << intersectionPoints.size() << " points of intersection: " << std::endl;
    for (auto intersectionPoint: intersectionPoints) {
        std::cout << intersectionPoint.first << ' ' << intersectionPoint.second << std::endl;
    }

    return 0;
}