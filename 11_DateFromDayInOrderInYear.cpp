/*
    Problem #11 - Date ↔ Day Of Year Conversion

    -------------------------------------------------------
    Description:
    Write a program that:
    1. Reads a date (Day, Month, Year)
    2. Converts it to its order in the year (Day Of Year)
    3. Converts it back from Day Of Year to full date

    -------------------------------------------------------
    Example:
    Input : 10 / 3 / 2024
    Output:
        Day Of Year = 70
        Converted Back = 10 / 3 / 2024

    -------------------------------------------------------
    Approach:
    - Convert Date → DayOfYear:
        Sum days of all previous months + current day
    - Convert DayOfYear → Date:
        Subtract days of each month until reaching target

    -------------------------------------------------------
    Key Concepts:
    - Structs
    - Loops
    - Date Algorithms

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
    short Year;
};

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

// Read date from user
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

// Convert date to day of year
short GetDayOfYear(sDate Date)
{
    short TotalDays = 0;

    for (short i = 1; i < Date.Month; i++)
    {
        TotalDays += GetDaysInMonth(i, Date.Year);
    }

    TotalDays += Date.Day;

    return TotalDays;
}

// Convert day of year back to date
sDate GetDateFromDayOfYear(short DayOfYear, short Year)
{
    sDate Date;
    Date.Year = Year;
    Date.Month = 1;

    while (true)
    {
        short DaysInMonth = GetDaysInMonth(Date.Month, Year);

        if (DayOfYear > DaysInMonth)
        {
            DayOfYear -= DaysInMonth;
            Date.Month++;
        }
        else
        {
            Date.Day = DayOfYear;
            break;
        }
    }

    return Date;
}

int main()
{
    sDate Date = ReadDate();

    short DayOfYear = GetDayOfYear(Date);

    cout << "\n-----------------------------\n";
    cout << "Day Of Year = " << DayOfYear << endl;

    sDate ConvertedDate = GetDateFromDayOfYear(DayOfYear, Date.Year);

    cout << "Converted Back = "
         << ConvertedDate.Day << "/"
         << ConvertedDate.Month << "/"
         << ConvertedDate.Year << endl;

    return 0;
}
