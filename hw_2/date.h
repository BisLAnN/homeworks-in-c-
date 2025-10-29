#pragma once
#include <string>
using namespace std;

class Date
{
private:
    int day;
    int month;
    int year;

    static const int MONTHS_IN_YEAR = 12;
    static const int daysInMonth[MONTHS_IN_YEAR + 1];

public:
    Date(int d = 1, int m = 1, int y = 2025);

    bool isValid() const;
    int dayOfYear() const;
    int weekNumber() const;

    int getDay() const { return day; }
    int getMonth() const { return month; }
    int getYear() const { return year; }

    static bool parse(const string& input, Date& outDate);
};