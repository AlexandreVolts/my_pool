#include <iomanip>
#include <iostream>

std::string ltrim(const std::string &str)
{
    size_t start = str.find_first_not_of(" \t");

    return (start == std::string::npos ? "" : str.substr(start));
}
double celcius_to_fahrenheit(double celcius)
{
    return (celcius * 9.0 / 5.0 + 32);
}
double fahrenheit_to_celcius(double fahrenheit)
{
    return (fahrenheit - 32) * 5.0 / 9.0;
}
double convert(const std::string &unit, double temp)
{
    if (unit.compare("Fahrenheit") == 0) {
        return (fahrenheit_to_celcius(temp));
    }

    return (celcius_to_fahrenheit(temp));
}

int main(int argc, char **argv)
{
    std::string str;
    std::string unit;
    double temp;
    size_t index;

    std::getline(std::cin, str);
    index = str.find(' ');
    if (index == std::string::npos) {
        return (1);
    }
    temp = stod(str.substr(0, index));
    unit = ltrim(str.substr(index));
    temp = convert(unit, temp);
    unit = unit.compare("Celcius") == 0 ? "Fahrenheit" : "Celcius";
    std::cout << std::setw(16) << std::setprecision(3) << std::fixed << temp;
    std::cout << std::setw(16) << unit << std::endl;
    return (0);
}