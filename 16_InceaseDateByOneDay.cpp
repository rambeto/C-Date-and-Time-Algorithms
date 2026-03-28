/*
    Problem #15 - Increase Date By One Day

    -------------------------------------------------------
    Description:
    Write a program that reads a date and returns
    the next day.

    -------------------------------------------------------
    Example:
    Input:
        Date = 31 / 12 / 2024

    Output:
        1 / 1 / 2025

    -------------------------------------------------------
    Approach:
    - If it's the last day of the month:
        - If it's December → reset to 1/1 and increase year
        - Otherwise → move to next month
    - Otherwise:
        - Just increase the day by 1

    -------------------------------------------------------
    Key Concepts:
    - Date Arithmetic
    - Conditional Logic
    - Structs

    -------------------------------------------------------
    Author: Your Name
*/

#include <iostream>
using namespace std;

// Struct to represent a date
struct sDate
{
    short Day;
    short Month;
    int Year;
};

// Check if year is leap year
bool IsLeapYear(int Year)
{
    return (Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0);
}

// Get number of days in a month
short GetDaysInMonth(short Month, int Year)
{
    if (Month < 1 || Month > 12)
        return 0;

    short DaysInMonths[12] =
    { 31,28,31,30,31,30,31,31,30,31,30,31 };

    if (Month == 2)
        return IsLeapYear(Year) ? 29 : 28;

    return DaysInMonths[Month - 1];
}

// Read full date
sDate ReadDate()
{
    sDate Date;

    cout << "Enter Day: ";
    cin >> Date.Day;

    cout << "Enter Month: ";
    cin >> Date.Month;

    cout << "Enter Year: ";
    cin >> Date.Year;

    return Date;
}

// Check if last day in month
bool IsLastDayInMonth(const sDate& Date)
{
    return Date.Day == GetDaysInMonth(Date.Month, Date.Year);
}

// Check if last month in year
bool IsLastMonthInYear(const sDate& Date)
{
    return Date.Month == 12;
}

// Increase date by one day
sDate IncreaseDateByOneDay(sDate Date)
{
    if (IsLastDayInMonth(Date))
    {
        if (IsLastMonthInYear(Date))
        {
            // End of year → reset to next year
            Date.Day = 1;
            Date.Month = 1;
            Date.Year++;
        }
        else
        {
            // End of month → move to next month
            Date.Day = 1;
            Date.Month++;
        }
    }
    else
    {
        // Normal case → just increase day
        Date.Day++;
    }

    return Date;
}

int main()
{
    sDate Date = ReadDate();

    sDate NextDate = IncreaseDateByOneDay(Date);

    cout << "\n-----------------------------\n";
    cout << "Next Date: "
         << NextDate.Day << "/"
         << NextDate.Month << "/"
         << NextDate.Year << endl;

    return 0;
}
