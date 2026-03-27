#include <iostream>
using namespace std;

// Defining an Enum for better code readability and clarity
enum enTypeYear { eLeap = 1, eNotLeap = 2 };

// Function to handle user input
int ReadYear()
{
    int Year;
    cout << "Enter year: ";
    cin >> Year;
    return Year;
}

/**
 * Optimized logic to check for leap year in one expression:
 * A year is leap if:
 * (Divisible by 4 AND NOT divisible by 100) OR (Divisible by 400)
 */
enTypeYear IsCheckYear(int Year)
{
    if ((Year % 4 == 0 && Year % 100 != 0) || Year % 400 == 0)
    {
        return enTypeYear::eLeap;
    }
    else
    {
        return enTypeYear::eNotLeap;
    }
}

// Function to handle the output display logic
void PrintTypeYear()
{
    // Calling functions inside the condition for cleaner main()
    if (IsCheckYear(ReadYear()) == enTypeYear::eLeap)
        cout << "Result: It is a Leap Year.\n";
    else
        cout << "Result: It is NOT a Leap Year.\n";
}

int main()
{
    // The main function is now very clean, calling only one high-level function
    PrintTypeYear();

    return 0;
}
