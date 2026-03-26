/*
    Problem #05 - Days in Month (Using Array Optimization)

    -------------------------------------------------------
    Description:
    Write a program that reads a month and a year from the user,
    then returns the number of days in that month.

    The program must correctly handle leap years.

    -------------------------------------------------------
    Approach:
    - Store number of days for each month in an array.
    - February is handled as a special case:
        28 days in a normal year
        29 days in a leap year
    - All other months are retrieved directly from the array.

    -------------------------------------------------------
    Advantages:
    - O(1) time complexity (no loops needed)
    - Cleaner and more readable code
    - More efficient than conditional checks

    -------------------------------------------------------
    Author: Your Name
*/

#include <iostream>
using namespace std;

// Check if a year is a leap year
bool IsLeapYear(short Year)
{
    return (Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0);
}

// Get number of days in a given month
short GetDaysInMonth(short Month, short Year)
{
    // Validate month input
    if (Month < 1 || Month > 12)
        return 0;

    // Days in each month (default)
    short DaysInMonths[12] = 
    { 31,28,31,30,31,30,31,31,30,31,30,31 };

    // Handle February (leap year case)
    if (Month == 2)
        return IsLeapYear(Year) ? 29 : 28;

    // Return value from array
    return DaysInMonths[Month - 1];
}

// Read month from user
short ReadMonth()
{
    short Month;

    cout << "\nEnter month (1-12): ";
    cin >> Month;

    return Month;
}

// Read year from user
short ReadYear()
{
    short Year;

    cout << "Enter year: ";
    cin >> Year;

    return Year;
}

int main()
{
    short Year = ReadYear();
    short Month = ReadMonth();

    cout << "\n-----------------------------\n";
    cout << "Month [" << Month << "] in Year [" << Year << "]\n";
    cout << "Number of Days = " << GetDaysInMonth(Month, Year) << endl;

    return 0;
}
