#include <iostream>
using namespace std;

// Function to prompt the user for a year input
int ReadYear()
{
    int Year;
    cout << "Please Enter a Year: ";
    cin >> Year;
    return Year;
}

/**
 * Core Logic: Determines leap year status
 * - Divisible by 400? -> Leap Year
 * - Divisible by 100? -> Not a Leap Year
 * - Divisible by 4?   -> Leap Year
 * - Otherwise?        -> Common Year
 */
bool IsLeapYear(int Year)
{
    // Rule 1: Centuries divisible by 400 are leap years
    if (Year % 400 == 0)
    {
        return true;
    }
    // Rule 2: Other centuries are NOT leap years
    else if (Year % 100 == 0)
    {
        return false;
    }
    // Rule 3: Regular years divisible by 4 are leap years
    else if (Year % 4 == 0)
    {
        return true;
    }
    // Rule 4: All other cases are common years
    else
    {
        return false;
    }
}

int main()
{
    // Step 1: Read Year from User
    int Year = ReadYear();

    // Step 2: Check the Year and Display Results
    if (IsLeapYear(Year))
    {
        cout << "\nYes, Year [" << Year << "] is a leap year.\n";
    }
    else
    {
        cout << "\nNo, Year [" << Year << "] is NOT a leap year.\n";
    }

    // Prevents the console from closing immediately (optional)
    system("pause>0"); 

    return 0;
}
