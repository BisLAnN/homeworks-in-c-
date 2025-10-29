#include <string>
#include <sstream>
#include <iomanip>
#include <ctime>
#include <iostream>
#include "date.h"

using namespace std;

const int MONTHS_IN_YEAR = 12;
const int DAYS_IN_YEAR = 365;

const int daysInMonth[MONTHS_IN_YEAR + 1] =
{
	0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31
};

bool isValidDate(int d, int m, int y)
{
	if (y != 2025) return false;
	if (m < 1 || m > 12) return false;
	if (d < 1 || d > daysInMonth[m]) return false;
	return true;
}

int dayOfYear(int d, int m)
{
	int dayNum = d;
	for (int i = 1; i < m; ++i)
	{
		dayNum += daysInMonth[i];
	}
	return dayNum;
}

int weekNumber(int d, int m, int y)
{
	int doy = dayOfYear(d, m);
	int week = (doy - 1) / 7 + 1;
	return week;
}

int main()
{
	string input;
	cout << "Enter date (dd.mm.yyyy): ";
	cin >> input;

	Date date;
	if (!Date::parse(input, date) || !date.isValid())
	{
		cout << "Invalid date!" << endl;
		return 1;
	}

	cout << "Week number: " << date.weekNumber() << endl;
	return 0;
}