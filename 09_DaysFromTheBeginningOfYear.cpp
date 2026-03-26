/*
    Problem #09 - Day of Year (Order in Year)

    -------------------------------------------------------
    Description:
    Write a program that reads a date (Day, Month, Year)
    and calculates its order (number of days) from the
    beginning of the year.

    Example:
    Input:  1 / 1 / 2024  → Output: 1
    Input:  31 / 12 / 2024 → Output: 366 (leap year)

    -------------------------------------------------------
    Approach:
    - Loop through all months before the given month
    - Sum their number of days
    - Add the current day

    -------------------------------------------------------
    Key Concepts:
    - Arrays
    - Loops
    - Date Calculations

    -------------------------------------------------------
    Author: Your Name
*/

#include <iostream>
using namespace std;

// Check if year is a leap year
bool IsLeapYear(short Year)
{
    return (Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0);
}

// Get number of days in a month
short GetDaysInMonth(short Month, short Year)
{
    if (Month < 1 || Month > 12)
        return 0;

    short DaysInMonths[12] =
    { 31,28,31,30,31,30,31,31,30,31,30,31 };

    if (Month == 2)
        return IsLeapYear(Year) ? 29 : 28;

    return DaysInMonths[Month - 1];
}

// Read day from user
short ReadDay()
{
    short Day;

    cout << "Enter Day: ";
    cin >> Day;

    return Day;
}

// Read month from user
short ReadMonth()
{
    short Month;

    cout << "Enter Month: ";
    cin >> Month;

    return Month;
}

// Read year from user
short ReadYear()
{
    short Year;

    cout << "Enter Year: ";
    cin >> Year;

    return Year;
}

// Calculate day order in year
short GetDayOfYear(short Day, short Month, short Year)
{
    short TotalDays = 0;

    // Sum days of previous months
    for (short i = 1; i < Month; i++)
    {
        TotalDays += GetDaysInMonth(i, Year);
    }

    // Add current day
    TotalDays += Day;

    return TotalDays;
}

int main()
{
    short Day = ReadDay();
    short Month = ReadMonth();
    short Year = ReadYear();

    cout << "\n-----------------------------\n";
    cout << "Date: " << Day << "/" << Month << "/" << Year << endl;
    cout << "Day Order in Year = " 
         << GetDayOfYear(Day, Month, Year) << endl;

    return 0;
}
