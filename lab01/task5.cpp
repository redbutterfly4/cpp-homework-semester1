#include <iostream>

int main()
{
    std::cout << "Enter how many seconds have passed since the beginning of the year: ";
    int inputSecond;
    std::cin >> inputSecond;

    constexpr int SECONDS_PER_MINUTE = 60;
    constexpr int SECONDS_PER_HOUR = 3600;
    constexpr int SECONDS_PER_DAY = SECONDS_PER_HOUR * 24;

    int currentDaySecond = inputSecond % SECONDS_PER_DAY;
    int currentHour = currentDaySecond / SECONDS_PER_HOUR;
    currentDaySecond %= SECONDS_PER_HOUR;
    int currentMinute = currentDaySecond / SECONDS_PER_MINUTE;
    currentDaySecond %= SECONDS_PER_MINUTE;
    int currentSecond = currentDaySecond;

    std::cout << "Current time: " << currentHour << ':' << currentMinute << ':' << currentSecond << std::endl;
}