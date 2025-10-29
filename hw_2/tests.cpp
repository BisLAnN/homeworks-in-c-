#include <iostream>
#include "date.h"
using namespace std;

void runTest(int testNum, const string& testName, bool condition)
{
    cout << "Unit-test #" << testNum << " (" << testName << ") - "
        << (condition ? "OK" : "FAIL") << endl;
}

int main()
{
    int testCount = 1;

    Date d1(15, 1, 2025);
    runTest(testCount++, "Valid date", d1.isValid());

    Date d2(10, 13, 2025);
    runTest(testCount++, "Invalid month", !d2.isValid());

    Date d3(32, 1, 2025);
    runTest(testCount++, "Invalid day", !d3.isValid());

    Date d4(10, 5, 2024);
    runTest(testCount++, "Wrong year", !d4.isValid());

    Date d5(31, 1, 2025);
    runTest(testCount++, "Day of year (31.01)", d5.dayOfYear() == 31);

    Date d6(1, 3, 2025);
    runTest(testCount++, "Day of year (1.03)", d6.dayOfYear() == 60);

    Date d7(7, 1, 2025);
    runTest(testCount++, "Week number (7.01)", d7.weekNumber() == 1);

    Date d8;
    bool parsedOk = Date::parse("15.02.2025", d8);
    runTest(testCount++, "Parse valid date", parsedOk && d8.getMonth() == 2 && d8.getDay() == 15);

    Date d9;
    runTest(testCount++, "Parse invalid format", !Date::parse("15-02-2025", d9));

    Date d10(31, 12, 2025);
    runTest(testCount++, "Week number (31.12)", d10.weekNumber() == 53);

    return 0;
}