/*
    Problem #12 - Add Days to Date

    -------------------------------------------------------
    Description:
    Write a program that:
    - Reads a full date (Day, Month, Year)
    - Reads a number of days to add
    - Returns the new date after adding those days

    -------------------------------------------------------
    Example:
    Input:
        Date = 28 / 12 / 2024
        Days = 5

    Output:
        New Date = 2 / 1 / 2025

    -------------------------------------------------------
    Approach:
    1. Convert the date to Day Of Year
    2. Add the extra days
    3. Loop through months and subtract days
    4. Handle year rollover when month > 12

    -------------------------------------------------------
    Key Concepts:
    - Structs
    - Loops
    - Date Arithmetic

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

// Read number of days to add
short ReadDaysToAdd()
{
    short Days;

    cout << "How many days to add? ";
    cin >> Days;

    return Days;
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

// Add days to date
sDate AddDaysToDate(short DaysToAdd, sDate Date)
{
    short RemainingDays = DaysToAdd + GetDayOfYear(Date);

    Date.Month = 1;

    while (true)
    {
        short DaysInMonth = GetDaysInMonth(Date.Month, Date.Year);

        if (RemainingDays > DaysInMonth)
        {
            RemainingDays -= DaysInMonth;
            Date.Month++;

            // Handle year rollover
            if (Date.Month > 12)
            {
                Date.Month = 1;
                Date.Year++;
            }
        }
        else
        {
            Date.Day = RemainingDays;
            break;
        }
    }

    return Date;
}

int main()
{
    sDate Date = ReadDate();
    short Days = ReadDaysToAdd();

    Date = AddDaysToDate(Days, Date);

    cout << "\n-----------------------------\n";
    cout << "New Date: "
         << Date.Day << "/"
         << Date.Month << "/"
         << Date.Year << endl;

    return 0;
}
