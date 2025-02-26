#include "date.h"
#include <iostream>
#include <sstream>

Date::Date() {
        month = 0;
        day = 0;
        year = 0;

} // End Constructor

void Date::init(std::string dateString) {
    char delim;
    std::stringstream ss(dateString);
    ss >> month >> delim >> day >> delim >> year;

    if (month < 1 || month > 12 || day < 1 || day > 31 || year < 1000) {
        month = day = year = 0;  // Reset invalid dates
        std::cout << "Invalid date provided!" << std::endl;
    }
}

void Date::printDate() {
    static const std::string months[] = {
        "", "January", "February", "March", "April", "May", "June",
        "July", "August", "September", "October", "November", "December"
    };

    if (month >= 1 && month <= 12) {
        std::cout << months[month] << " " << day << ", " << year << std::endl;
    } else {
        std::cout << "Invalid Date" << std::endl;
    }
}
