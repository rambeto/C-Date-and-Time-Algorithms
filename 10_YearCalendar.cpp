/*
    Problem #08 - Full Year Calendar

    -------------------------------------------------------
    Description:
    Write a program that reads a year from the user,
    then prints the full calendar for all 12 months.

    -------------------------------------------------------
    Features:
    - Prints all months in a year
    - Displays month names
    - Aligns days correctly under weekdays
    - Handles leap years

    -------------------------------------------------------
    Approach:
    1. Loop through all months (1 → 12)
    2. For each month:
        - Calculate the first day of the month
        - Get number of days
        - Print formatted calendar
    3. Repeat for all months

    -------------------------------------------------------
    Key Concepts:
    - Modular Arithmetic
    - Arrays
    - Functions & Reusability
    - Calendar Algorithms

    -------------------------------------------------------
    Author: Your Name
*/

#include <iostream>
#include <iomanip>
using namespace std;

// Check if year is leap year
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

// Get month name
string GetMonthName(short Month)
{
    string Months[12] =
    { "Jan", "Feb", "Mar", "Apr", "May", "Jun",
      "Jul", "Aug", "Sep", "Oct", "Nov", "Dec" };

    return (Month >= 1 && Month <= 12) ? Months[Month - 1] : "Invalid";
}

// Calculate day of week (0 = Sunday)
short GetDayOfWeek(short Day, short Month, short Year)
{
    short a = (14 - Month) / 12;
    short y = Year - a;
    short m = Month + (12 * a) - 2;

    return (Day + y + y/4 - y/100 + y/400 + (31 * m)/12) % 7;
}

// Print one month calendar
void PrintMonthCalendar(short Month, short Year)
{
    short FirstDay = GetDayOfWeek(1, Month, Year);
    short TotalDays = GetDaysInMonth(Month, Year);

    cout << "\n------------ " << GetMonthName(Month) << " ------------\n";
    cout << " Sun  Mon  Tue  Wed  Thu  Fri  Sat\n";

    short Current = 0;

    // Print leading spaces
    for (short i = 0; i < FirstDay; i++)
    {
        cout << setw(5) << " ";
        Current++;
    }

    // Print days
    for (short Day = 1; Day <= TotalDays; Day++)
    {
        cout << setw(5) << Day;
        Current++;

        if (Current == 7)
        {
            cout << endl;
            Current = 0;
        }
    }

    if (Current != 0)
        cout << endl;

    cout << "------------------------------------\n";
}

// Print full year calendar
void PrintYearCalendar(short Year)
{
    cout << "\n========== Calendar - " << Year << " ==========\n";

    for (short Month = 1; Month <= 12; Month++)
    {
        PrintMonthCalendar(Month, Year);
    }
}

// Read year from user
short ReadYear()
{
    short Year;

    cout << "Enter Year: ";
    cin >> Year;

    return Year;
}

int main()
{
    short Year = ReadYear();

    PrintYearCalendar(Year);

    return 0;
}
