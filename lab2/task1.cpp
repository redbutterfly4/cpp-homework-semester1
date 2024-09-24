#include <iostream>
#include <vector>

int main()
{
    constexpr int NUMBER_OF_TV_SHOWS = 3;
    std::vector<std::string> tvShowNames(NUMBER_OF_TV_SHOWS);
    std::vector<int> tvShowStartTimes(NUMBER_OF_TV_SHOWS); // Assuming times are in minutes from 0:00
    std::vector<int> tvShowDurations(NUMBER_OF_TV_SHOWS);  // Assuming durations are in minutes

    for (int i = 0; i < NUMBER_OF_TV_SHOWS; ++i) {
        std::cout << "Enter the name of TV show number " << i + 1 << ": ";
        std::cin >> tvShowNames[i];

        std::cout << "Enter the start time of TV show number " << i + 1 << " (e.g. 9 45): ";
        int startHour;
        int startMinute;
        std::cin >> startHour >> startMinute;
        while (startHour < 0 || startHour > 23) {
            std::cout << "The start of the TV show in hours must be between 0 and 23." << std::endl;
            std::cout << "Enter the new starting hour of the TV show: ";
            std::cin >> startHour;
        }
        while (startMinute < 0 || startMinute > 59) {
            std::cout << "The starting minute of the TV show must be between 0 and 59." << std::endl;
            std::cout << "Enter the new starting minute of the TV show: ";
            std::cin >> startMinute;
        }
        tvShowStartTimes[i] = startHour * 60 + startMinute;

        std::cout << "Enter the duration of TV show number " << i + 1 << " in minutes: ";
        std::cin >> tvShowDurations[i];
        while (tvShowDurations[i] < 0) {
            std::cout << "The duration of the TV show must be positive." << std::endl;
            std::cout << "Enter the new duration of the TV show: ";
            std::cin >> tvShowDurations[i];
        }
    }

    int hour;
    int minute;
    std::cout << "Enter the time when Andrei turned on the TV (e.g. 9 45): ";
    std::cin >> hour >> minute;
    while (hour < 0 || hour > 23) {
        std::cout << "Hour must be between 0 and 23." << std::endl;
        std::cout << "Enter a new hour: ";
        std::cin >> hour;
    }
    while (minute < 0 || minute > 59) {
        std::cout << "Minute must be between 0 and 59." << std::endl;
        std::cout << "Enter a new minute: ";
        std::cin >> minute;
    }
    int currentMinute = hour * 60 + minute;

    constexpr int TV_SHOW_NOT_FOUND = -1;
    int tvShowIndex = TV_SHOW_NOT_FOUND;
    for (int i = 0; i < NUMBER_OF_TV_SHOWS; ++i) {
        int tvShowEndTime = tvShowStartTimes[i] + tvShowDurations[i];

        // Check if the current minute is between the beginning and the end of the current TV show
        if (tvShowStartTimes[i] <= currentMinute && currentMinute <= tvShowEndTime) {
            tvShowIndex = i;
        }
    }

    if (tvShowIndex >= 0) {
        std::cout << "Andrei is watching TV show number " << tvShowIndex + 1 << " called '" << tvShowNames[tvShowIndex]
                  << "'." << std::endl;
    }
    else {
        std::cout << "Andrei doesn't watch any TV show." << std::endl;
    }

    return 0;
}