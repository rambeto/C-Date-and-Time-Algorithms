/*
    Problem #13 - Compare Two Dates (Equality Check)

    -------------------------------------------------------
    Description:
    Write a program that reads two dates and checks
    whether they are equal or not.

    -------------------------------------------------------
    Example:
    Input:
        Date1 = 10 / 3 / 2024
        Date2 = 10 / 3 / 2024

    Output:
        Equal

    -------------------------------------------------------
    Approach:
    - Compare Year first
    - Then Month
    - Then Day
    - If all are equal → Dates are equal

    -------------------------------------------------------
    Key Concepts:
    - Structs
    - Comparison Logic
    - Clean Code

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

// Check if two dates are equal
bool AreDatesEqual(sDate Date1, sDate Date2)
{
    return (Date1.Year == Date2.Year &&
            Date1.Month == Date2.Month &&
            Date1.Day == Date2.Day);
}

int main()
{
    cout << "Enter First Date\n";
    sDate Date1 = ReadDate();

    cout << "\nEnter Second Date\n";
    sDate Date2 = ReadDate();

    cout << "\n-----------------------------\n";

    if (AreDatesEqual(Date1, Date2))
        cout << "Dates are Equal\n";
    else
        cout << "Dates are NOT Equal\n";

    return 0;
}
