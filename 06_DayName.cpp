/*
    Problem #06 - Day of Week from Date

    -------------------------------------------------------
    Description:
    Write a program that reads a full date (Day, Month, Year)
    and returns the day of the week (e.g., Sun, Mon, Tue...).

    -------------------------------------------------------
    Approach:
    - Use a mathematical formula (Gregorian Calendar Algorithm)
      to calculate the day index.
    - The formula returns a number from 0 to 6:
        0 = Sunday, 1 = Monday, ..., 6 = Saturday
    - Map the result to a string using an array.

    -------------------------------------------------------
    Key Concept:
    - Date Algorithms
    - Modular Arithmetic

    -------------------------------------------------------
    Author: Your Name
*/

#include <iostream>
using namespace std;

// Read year from user
int ReadYear()
{
    int Year;

    cout << "Enter Year: ";
    cin >> Year;

    return Year;
}

// Read month from user
int ReadMonth()
{
    int Month;

    cout << "Enter Month (1-12): ";
    cin >> Month;

    return Month;
}

// Read day from user
int ReadDay()
{
    int Day;

    cout << "Enter Day: ";
    cin >> Day;

    return Day;
}

// Calculate day of week using Gregorian algorithm
short GetDayOfWeekOrder(short Day, short Month, short Year)
{
    short a, y, m;

    a = (14 - Month) / 12;
    y = Year - a;
    m = Month + (12 * a) - 2;

    // Formula result:
    // 0 = Sunday, 1 = Monday, ..., 6 = Saturday
    return (Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
}

// Convert day index to day name
string GetDayName(short DayOrder)
{
    string Days[] = { "Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat" };
    return Days[DayOrder];
}

int main()
{
    int Year = ReadYear();
    int Month = ReadMonth();
    int Day = ReadDay();

    short DayOrder = GetDayOfWeekOrder(Day, Month, Year);
    string DayName = GetDayName(DayOrder);

    cout << "\n--------------------------\n";
    cout << "Date: " << Day << "/" << Month << "/" << Year << endl;
    cout << "Day : " << DayName << endl;

    return 0;
}
