---

# Week Number Calculator in C++

This simple C++ program calculates the week number of a given date in the year 2025.
It asks the user to input a date in the format dd.mm.yyyy, validates it, and outputs which week of the year that date falls into.

---

## Features

* Validates user input format (`dd.mm.yyyy`)
* Ensures the year entered is 2025
* Checks that the day and month values are valid
* Calculates the day of the year and week number
* Outputs the result directly to the console

---

## Example Usage
Enter date (dd.mm.yyyy): 14.02.2025
Week number: 7

If an invalid date or year is entered:
Enter date (dd.mm.yyyy): 31.02.2024
Invalid date!

---

## How It Works

1. Date Validation
   The program checks:

   * The year must be 2025
   * The month must be between 1 and 12
   * The day must not exceed the number of days in that month

2. Day of the Year Calculation
   It sums all days from previous months and adds the given day.

3. Week Number Calculation
   The week number is computed by dividing the day-of-year by 7:

     int week = (dayOfYear - 1) / 7 + 1;
   
---

## Code Structure

| Function                           | Description                                |
| ---------------------------------- | ------------------------------------------ |
| isValidDate(int d, int m, int y) | Checks if the date is valid for 2025       |
| dayOfYear(int d, int m)          | Returns the day number in the year         |
| weekNumber(int d, int m, int y)  | Computes the week number                   |
| main()                           | Handles user input/output and program flow |

---

## Compilation & Execution

To compile and run:
g++ main.cpp -o week_number
./week_number

---

## Notes

* This program is designed only for the year 2025 (as per the validation rule).
* Leap years are not handled, since 2025 is not a leap year.
* Week calculation starts from January 1st as Week 1.

---

##
