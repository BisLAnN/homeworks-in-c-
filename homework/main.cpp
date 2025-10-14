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

    int dotCount = 0;

    for (char& c : input)
    {
        if (c == ',') c = '.';

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

void runSimpleTests()
{

    struct TestCase
    {
        string shape;
        double base;
        double height;
        double expected;
    };

    TestCase tests[] = {
      {"Triangle", 10.0, 5.0, triangleArea(10.0, 5.0)},
      {"Parallelogram", 8.0, 4.0, parallelogramArea(8.0, 4.0)},
      {"Triangle", 3.5, 2.0, triangleArea(3.5, 2.0)},
      {"Parallelogram", 12.3, 7.1, parallelogramArea(12.3, 7.1)}
    };

    for (const auto& t : tests)
    {
        cout << "\nShape: " << t.shape
            << "\nBase: " << t.base
            << "\nHeight: " << t.height
            << "\nExpected Area: " << fixed << setprecision(2) << t.expected
    }
}

int main()
{
    int userChoice;
    double base, height;

    cout << fixed << setprecision(2);

    while (true)
    {
        cout << "Choose a figure to calculate area:\n";
        cout << "1 - Triangle\n";
        cout << "2 - Parallelogram\n";
        cout << "3 - Simple tests\n";
        cout << "0 - Exit\n";
        cout << "Enter your choice: ";
        cin >> userChoice;

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input! Please enter 0–3.\n";
            continue;
        }

        if (userChoice == 0)
        {
            cout << "Exiting program. Bye!\n";
            break;
        }

        if (userChoice == 3)
        {
            runSimpleTests();
            continue;
        }

        if (userChoice != 1 && userChoice != 2)
        {
            cout << "Wrong choice! Please enter 0–3.\n";
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