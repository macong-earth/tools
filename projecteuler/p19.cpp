#include <iostream>
#include <string>

const int normalYearDays[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
const int leapYearDays[] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

const int * getDays(int year) {
    if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)) {
        return leapYearDays;
    } else {
        return normalYearDays;
    }
}


int main(int argc, char const* argv[])
{
    int sumMonthDays = 0;
    int sundays = 0;

    std::cout << argv[1] << std::endl;
    int endYear = std::stoi(argv[1]);

    for (int i = 1900; i <= endYear; i++) {
        const int * monthDays = getDays(i);
        for (int j = 0; j < 12; j++) {
            sundays += (sumMonthDays + 1 ) % 7 == 0 ? 1: 0;
            sumMonthDays += monthDays[j];
        }
    }

    std::cout << sundays << std::endl;
    return 0;
}
