/*
    Problem #03 - Year Calculations (Leap Year)

    -------------------------------------------------------
    Description:
    Write a program that reads a year from the user and determines:
    - Number of Days in that year
    - Number of Hours
    - Number of Minutes
    - Number of Seconds

    The program should correctly handle leap years.

    -------------------------------------------------------
    Approach:
    - A leap year is:
        divisible by 4 AND not divisible by 100
        OR divisible by 400
    - Based on that:
        Leap Year  -> 366 days
        Normal Year -> 365 days
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

// Function to read year from user
short ReadYear()
{
    short Year;

    cout << "\nEnter a year: ";
    cin >> Year;

    return Year;
}

// Function to return number of days in a year
short GetDaysInYear(short Year)
{
    return IsLeapYear(Year) ? 366 : 365;
}

// Function to calculate number of hours in a year
int GetHoursInYear(short Year)
{
    return GetDaysInYear(Year) * 24;
}

// Function to calculate number of minutes in a year
int GetMinutesInYear(short Year)
{
    return GetHoursInYear(Year) * 60;
}

// Function to calculate number of seconds in a year
long GetSecondsInYear(short Year)
{
    return (long)GetMinutesInYear(Year) * 60;
}

int main()
{
    short Year = ReadYear();

    cout << "\n===== Year Statistics =====\n";
    cout << "Year [" << Year << "] Details:\n";
    cout << "----------------------------\n";

    cout << "Days    : " << GetDaysInYear(Year) << endl;
    cout << "Hours   : " << GetHoursInYear(Year) << endl;
    cout << "Minutes : " << GetMinutesInYear(Year) << endl;
    cout << "Seconds : " << GetSecondsInYear(Year) << endl;

    return 0;
}
