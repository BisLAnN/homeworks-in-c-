#include <limits>
#include <iomanip>
#include <string>
#include <cctype>
#include <cmath>
#include <iostream>
using namespace std;

const double TRIANGLE_COEFF = 0.5;

double parallelogramArea(double base, double height)
{
	return base * height;
}

double triangleArea(double base, double height)
{
	return TRIANGLE_COEFF * base * height;
}

bool getPositiveInput(const string& prompt, double& value)
{
	string input;
	cout << prompt;
	cin >> input;

	for (char& c : input)
	{
		if (c == ',') c = '.';
	}

	int dotCount = 0;

	for (char c : input)
	{
		if (!(isdigit(c) || c == '.'))
		{
			cout << "Invalid input! Use only digits and '.' or ','.\n";
			return false;
		}

		if (c == '.') dotCount++;

		if (dotCount > 1)
		{
			cout << "Invalid number! Too many decimal points.\n";
			return false;
		}
	}

	try
	{
		value = stod(input);
	}

	catch (...)
	{
		cout << "Conversion error. Try again.\n";
		return false;
	}

	if (value <= 0)
	{
		cout << "Value must be greater than zero.\n";
		return false;
	}

	return true;
}

int main()
{
	int userChoice;
	double base, height;

	cout << fixed << setprecision(2);

	while (true) {
		cout << "\nChoose a figure to calculate area:\n";
		cout << "1 - Triangle\n";
		cout << "2 - Parallelogram\n";
		cout << "0 - Exit\n";
		cout << "Enter your choice: ";
		cin >> userChoice;

		if (cin.fail()) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Invalid input! Please enter 0, 1, or 2.\n";
			continue;
		}

		if (userChoice == 0) {
			cout << "Exiting program. Bye!\n";
			break;
		}

		if (userChoice != 1 && userChoice != 2) {
			cout << "Wrong choice! Please enter 0, 1, or 2.\n";
			continue;
		}

		while (!getPositiveInput("Enter base: ", base)) {}
		while (!getPositiveInput("Enter height: ", height)) {}

		if (fabs(base) > numeric_limits<double>::max() / fabs(height))
		{
			cout << "Overflow detected! Numbers are too large.\n";
			continue;
		}

		if (userChoice == 1)
		{
			cout << "\nArea of Triangle = " << triangleArea(base, height) << endl;
		}

		else
		{
			cout << "\nArea of Parallelogram = " << parallelogramArea(base, height) << endl;
		}
	}

	return 0;
}