/*
    Problem #15 - Check Last Day & Last Month

    -------------------------------------------------------
    Description:
    Write a program that reads a date and checks:
    - Is it the last day in the month?
    - Is it the last month in the year?

    -------------------------------------------------------
    Example:
    Input:
        Date = 31 / 12 / 2024

    Output:
        Yes, Last Day
        Yes, Last Month

    -------------------------------------------------------
    Approach:
    - Compare the day with total days in that month
    - Check if month == 12

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

// Read full date from user
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

// Print results
void PrintResults(const sDate& Date)
{
    cout << "\n-----------------------------\n";

    cout << (IsLastDayInMonth(Date) ? "Yes, Last Day\n" : "No, Not Last Day\n");
    cout << (IsLastMonthInYear(Date) ? "Yes, Last Month\n" : "No, Not Last Month\n");
}

int main()
{
    sDate Date = ReadDate();

    PrintResults(Date);

    return 0;
}
