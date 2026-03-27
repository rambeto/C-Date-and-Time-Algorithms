/*
    Problem #04 - Month Calculations (Days, Hours, Minutes, Seconds)

    -------------------------------------------------------
    Description:
    Write a program that reads a month and a year from the user
    and calculates:
    - Number of Days in that month
    - Number of Hours
    - Number of Minutes
    - Number of Seconds

    The program should correctly handle leap years (for February).

    -------------------------------------------------------
    Approach:
    - First check if the year is a leap year:
        divisible by 4 AND not divisible by 100
        OR divisible by 400
    - February:
        28 days (normal year)
        29 days (leap year)
    - Months with 31 days:
        {1, 3, 5, 7, 8, 10, 12}
    - باقي الشهور:
        30 يوم
    - Convert:
        Days → Hours → Minutes → Seconds

    -------------------------------------------------------
    Author: Your Name
*/

#include <iostream>
using namespace std;

// Function to check if the given year is a leap year
bool IsLeapYear(short Year)
{
    return (Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0);
}

// Function to return number of days in a specific month
short GetDaysInMonth(short Month, short Year)
{
    // Validate month input
    if (Month < 1 || Month > 12)
        return 0;

    // Handle February
    if (Month == 2)
        return IsLeapYear(Year) ? 29 : 28;

    // Months with 31 days
    short Months31[] = {1, 3, 5, 7, 8, 10, 12};

    for (short i = 0; i < 7; i++)
    {
        if (Months31[i] == Month)
            return 31;
    }

    // Remaining months have 30 days
    return 30;
}

// Function to calculate hours in a month
int GetHoursInMonth(short Month, short Year)
{
    return GetDaysInMonth(Month, Year) * 24;
}

// Function to calculate minutes in a month
int GetMinutesInMonth(short Month, short Year)
{
    return GetHoursInMonth(Month, Year) * 60;
}

// Function to calculate seconds in a month
long GetSecondsInMonth(short Month, short Year)
{
    return (long)GetMinutesInMonth(Month, Year) * 60;
}

// Function to read month from user
short ReadMonth()
{
    short Month;

    cout << "\nEnter a month (1-12): ";
    cin >> Month;

    return Month;
}

// Function to read year from user
short ReadYear()
{
    short Year;

    cout << "Enter a year: ";
    cin >> Year;

    return Year;
}

int main()
{
    short Year = ReadYear();
    short Month = ReadMonth();

    cout << "\n===== Month Statistics =====\n";
    cout << "Month [" << Month << "] in Year [" << Year << "]\n";
    cout << "----------------------------------\n";

    cout << "Days    : " << GetDaysInMonth(Month, Year) << endl;
    cout << "Hours   : " << GetHoursInMonth(Month, Year) << endl;
    cout << "Minutes : " << GetMinutesInMonth(Month, Year) << endl;
    cout << "Seconds : " << GetSecondsInMonth(Month, Year) << endl;

    return 0;
}
