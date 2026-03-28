/*
    Problem #16 - Difference Between Two Dates

    -------------------------------------------------------
    Description:
    Write a program that reads two dates and calculates
    the difference in days between them.

    Optionally include the end day in the result.

    -------------------------------------------------------
    Example:
    Input:
        Date1 = 1 / 1 / 2024
        Date2 = 3 / 1 / 2024

    Output:
        Difference = 2 days
        Including End Day = 3 days

    -------------------------------------------------------
    Approach:
    - Start from Date1
    - Keep increasing it day by day
    - Count how many days until reaching Date2
    - Optionally include the last day

    -------------------------------------------------------
    Key Concepts:
    - Date Arithmetic
    - Looping
    - Incremental Simulation

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

// Check if Date1 is before Date2
bool IsDate1BeforeDate2(const sDate& Date1, const sDate& Date2)
{
    return (Date1.Year < Date2.Year) ||
           (Date1.Year == Date2.Year && Date1.Month < Date2.Month) ||
           (Date1.Year == Date2.Year && Date1.Month == Date2.Month && Date1.Day < Date2.Day);
}

// Check if last day in month
bool IsLastDayInMonth(const sDate& Date)
{
    return Date.Day == GetDaysInMonth(Date.Month, Date.Year);
}

// Check if last month in year
bool IsLastMonthInYear(short Month)
{
    return Month == 12;
}

// Increase date by one day
sDate IncreaseDateByOneDay(sDate Date)
{
    if (IsLastDayInMonth(Date))
    {
        if (IsLastMonthInYear(Date.Month))
        {
            Date.Day = 1;
            Date.Month = 1;
            Date.Year++;
        }
        else
        {
            Date.Day = 1;
            Date.Month++;
        }
    }
    else
    {
        Date.Day++;
    }

    return Date;
}

// Calculate difference in days
int GetDifferenceInDays(sDate Date1, sDate Date2, bool IncludeEndDay = false)
{
    int Days = 0;

    while (IsDate1BeforeDate2(Date1, Date2))
    {
        Days++;
        Date1 = IncreaseDateByOneDay(Date1);
    }

    return IncludeEndDay ? Days + 1 : Days;
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

int main()
{
    cout << "Enter First Date:\n";
    sDate Date1 = ReadDate();

    cout << "\nEnter Second Date:\n";
    sDate Date2 = ReadDate();

    cout << "\n-----------------------------\n";

    cout << "Difference = "
         << GetDifferenceInDays(Date1, Date2) << " Day(s)\n";

    cout << "Including End Day = "
         << GetDifferenceInDays(Date1, Date2, true) << " Day(s)\n";

    return 0;
}
