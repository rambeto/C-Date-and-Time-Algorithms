/*
    Problem #07 - Print Month Calendar

    -------------------------------------------------------
    Description:
    Write a program that reads a month and a year from the user,
    then prints a formatted calendar for that month.

    -------------------------------------------------------
    Features:
    - Displays month name and year
    - Prints days aligned under correct weekdays
    - Handles leap years correctly
    - Clean and formatted output

    -------------------------------------------------------
    Approach:
    1. Calculate the day of the week for the first day of the month
    2. Get number of days in the month
    3. Print leading spaces for alignment
    4. Print days in a weekly format (7 days per row)

    -------------------------------------------------------
    Key Concepts:
    - Date Algorithms
    - Arrays
    - Formatting Output
    - Modular Arithmetic

    -------------------------------------------------------
    Author: Your Name
*/

#include <iostream>
#include <iomanip> // for setw
using namespace std;

// Check if year is leap year
bool IsLeapYear(int Year)
{
    return (Year % 400 == 0) || (Year % 4 == 0 && Year % 100 != 0);
}

// Get number of days in a month
short GetDaysInMonth(int Month, int Year)
{
    if (Month < 1 || Month > 12)
        return 0;

    if (Month == 2)
        return IsLeapYear(Year) ? 29 : 28;

    short Days31[] = {1, 3, 5, 7, 8, 10, 12};

    for (short i = 0; i < 7; i++)
    {
        if (Days31[i] == Month)
            return 31;
    }

    return 30;
}

// Get month name
string GetMonthName(short Month)
{
    string Months[12] = {
        "January", "February", "March", "April",
        "May", "June", "July", "August",
        "September", "October", "November", "December"
    };

    return Months[Month - 1];
}

// Calculate day of week (0 = Sunday)
short GetDayOfWeek(short Day, short Month, short Year)
{
    short a = (14 - Month) / 12;
    short y = Year - a;
    short m = Month + (12 * a) - 2;

    return (Day + y + y/4 - y/100 + y/400 + (31 * m)/12) % 7;
}

// Print calendar
void PrintMonthCalendar(short Month, short Year)
{
    short FirstDay = GetDayOfWeek(1, Month, Year);
    short TotalDays = GetDaysInMonth(Month, Year);

    cout << "\n------------ " << GetMonthName(Month) << " " << Year << " ------------\n";
    cout << " Sun  Mon  Tue  Wed  Thu  Fri  Sat\n";

    // Print leading spaces
    short Current = 0;
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

    cout << "----------------------------------------\n";
}

// Read year
int ReadYear()
{
    int Year;
    cout << "Enter Year: ";
    cin >> Year;
    return Year;
}

// Read month
int ReadMonth()
{
    int Month;
    cout << "Enter Month (1-12): ";
    cin >> Month;
    return Month;
}

int main()
{
    int Year = ReadYear();
    int Month = ReadMonth();

    PrintMonthCalendar(Month, Year);

    return 0;
}
