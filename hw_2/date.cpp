#include "date.h"
#include <sstream>

const int Date::daysInMonth[Date::MONTHS_IN_YEAR + 1] =
{
    0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31
};

Date::Date(int d, int m, int y)
    : day(d), month(m), year(y) {}

bool Date::isValid() const
{
    if (year != 2025) return false;
    if (month < 1 || month > MONTHS_IN_YEAR) return false;
    if (day < 1 || day > daysInMonth[month]) return false;
    return true;
}

int Date::dayOfYear() const
{
    int dayNum = day;
    for (int i = 1; i < month; ++i)
        dayNum += daysInMonth[i];
    return dayNum;
}

int Date::weekNumber() const
{
    int doy = dayOfYear();
    return (doy - 1) / 7 + 1;
}

bool Date::parse(const string& input, Date& outDate)
{
    int d, m, y;
    char firstDotInDate, secondDotInDate;
    stringstream ss(input);
    ss >> d >> firstDotInDate >> m >> secondDotInDate >> y;
    if (ss.fail() || firstDotInDate != '.' || secondDotInDate != '.')
        return false;

    outDate = Date(d, m, y);
    return true;
}