#include <iostream>
#include <vector>

int main()
{
    std::cout << "Enter the day: ";
    int day;
    std::cin >> day;
    std::cout << "Enter the month: ";
    int month;
    std::cin >> month;


    --day;
    if (day == 0) {
        --month;
        if (month == 0) {
            month = 12;
            day = 31;
        }
        else {
            std::vector<int> daysInMonth = {31, 28, 31, 30, 31, 30,
                                            31, 31, 30, 31, 30, 31};
            day = daysInMonth[month - 1];
        }
    }
    std::cout << "The previous day is: " << day << "." << month << std::endl;

    return 0;
}