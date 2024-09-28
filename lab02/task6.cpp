#include <iostream>
#include <vector>

int main()
{
    std::cout << "Enter the date (day, month, year, e.g. 1 2 2000): ";
    int day;
    int month;
    int year;
    std::cin >> day >> month >> year;


    --day;
    if (day == 0) {
        --month;
        if (month == 0) {
            --year;
            month = 12;
            day = 31;
        }
        else {
            bool isLeapYear = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
            const int DAYS_IN_FEBRUARY = isLeapYear ? 29 : 28;
            std::vector<int> daysInMonth = {31, DAYS_IN_FEBRUARY, 31, 30, 31, 30,
                                            31, 31, 30, 31, 30, 31};
            day = daysInMonth[month - 1];
        }
    }
    std::cout << "The previous day is: " << day << "." << month << "." << year << std::endl;

    return 0;
}