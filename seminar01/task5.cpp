#include <iostream>

int main()
{
    std::cout << "Enter the temperature in Celsius: ";
    double celsiusTemperature;
    std::cin >> celsiusTemperature;

    constexpr double FAHRENHEIT_FACTOR = 1.8;
    constexpr double FAHRENHEIT_OFFSET = 32;
    double fahrenheitTemperature = celsiusTemperature * FAHRENHEIT_FACTOR + FAHRENHEIT_OFFSET;

    constexpr double KELVIN_OFFSET = 273.15;
    double kelvinTemperature = celsiusTemperature + KELVIN_OFFSET;

    std::cout << "Temperature in Kelvin = " << kelvinTemperature << '\n';
    std::cout << "Temperature in Fahrenheit = " << fahrenheitTemperature << std::endl;
}