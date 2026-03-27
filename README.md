# 🚀 C-Date-and-Time-Algorithms

A collection of C++ problems and solutions focused on date and time manipulation, including leap years, calendars, date comparison, and real-world scenarios. Designed to improve problem-solving skills and build strong logic in handling date-based algorithms.

---

## 📊 Problems Table

| #  | File Name | Description | Key Concept |
|----|----------|------------|-------------|
| 01 | [01_NumberToText.cpp](./01_NumberToText.cpp) | Convert numbers into their textual representation | Recursion, Strings |
| 02 | [02_LeapYear.cpp](./02_LeapYear.cpp) | Check if a year is a leap year | Leap Year Logic |
| 03 | [03_LeapYear2.cpp](./03_LeapYear2.cpp) | Alternative leap year implementation | Conditional Logic |
| 04 | [04_NumberOf-Days-Hours-Minutes-Sec.cpp](./04_NumberOf-Days-Hours-Minutes-Sec.cpp) | Convert time units | Time Conversion |
| 05 | [05_NumberOfD-H-M-SInMonth.cpp](./05_NumberOfD-H-M-SInMonth.cpp) | Calculate time in a month | Aggregation |
| 06 | [06_NumberOfDaysInMonthShortLogic.cpp](./06_NumberOfDaysInMonthShortLogic.cpp) | Days in month using short logic | Optimization |
| 07 | [07_DayName.cpp](./07_DayName.cpp) | Get day name from number | Mapping |
| 08 | [08_MonthCalendar.cpp](./08_MonthCalendar.cpp) | Print month calendar | Nested Loops |
| 09 | [09_YearCalendar.cpp](./09_YearCalendar.cpp) | Print full year calendar | Loops & Formatting |
| 10 | [10_DaysFromTheBeginningOfYear.cpp](./10_DaysFromTheBeginningOfYear.cpp) | Calculate days from start of year | Accumulation |
| 11 | [11_DateFromDayInOrderInYear.cpp](./11_DateFromDayInOrderInYear.cpp) | Convert day order to date | Reverse Calculation |
| 12 | [12_AddDaysToDate.cpp](./12_AddDaysToDate.cpp) | Add days to a date | Date Arithmetic |
| 13 | [13_Date1LessThenDate2.cpp](./13_Date1LessThenDate2.cpp) | Compare two dates | Comparison |
| 14 | [14_Date1EqualDate2.cpp](./14_Date1EqualDate2.cpp) | Check if dates are equal | Equality Check |
| 15 | [15_isLastDayANdIsLastMonth.cpp](./15_isLastDayANdIsLastMonth.cpp) | Check last day/month | Edge Cases |
| 16 | [16_IncreaseDateByOneDay.cpp](./16_IncreaseDateByOneDay.cpp) | Increment date by one day | Date Increment |
| 17 | [17_GetDiffDate1-Date2.cpp](./17_GetDiffDate1-Date2.cpp) | Difference between two dates | Date Difference |
| 18 | [18_YourAgeInDays.cpp](./18_YourAgeInDays.cpp) | Calculate age in days | Real-world Problem |


### 🔹 01_NumberToText
- **🎯 Goal:** Convert a number into its textual representation (e.g., 123 → One Hundred Twenty Three).
- **🧠 Logic:**  
  - Break the number into parts (units, tens, hundreds, etc.)  
  - Map each part to its word equivalent  
- **💡 Key Skill:** **Recursion + String Manipulation**

---

### 🔹 02_LeapYear
- **🎯 Goal:** Determine whether a given year is a leap year.
- **🧠 Logic:**  
  - Divisible by 4  
  - Not divisible by 100 unless divisible by 400  
- **💡 Key Skill:** **Compound Conditions**

---

### 🔹 04_NumberOf-Days-Hours-Minutes-Sec
- **🎯 Goal:** Convert between time units.
- **🧠 Logic:**  
  - 1 day = 24 hours  
  - 1 hour = 60 minutes  
  - 1 minute = 60 seconds  
- **💡 Key Skill:** **Unit Conversion**

---

### 🔹 06_NumberOfDaysInMonthShortLogic
- **🎯 Goal:** Calculate number of days in a month efficiently.
- **🧠 Logic:**  
  - Use optimized conditions instead of long branching  
- **💡 Key Skill:** **Clean Code & Optimization**

---

### 🔹 08_MonthCalendar
- **🎯 Goal:** Print a formatted monthly calendar.
- **🧠 Logic:**  
  - Use nested loops to align days properly  
- **💡 Key Skill:** **Nested Loops + Formatting**

---

### 🔹 09_YearCalendar
- **🎯 Goal:** Print a full year calendar.
- **🧠 Logic:**  
  - Reuse month logic across 12 months  
- **💡 Key Skill:** **Reusability**

---

### 🔹 12_AddDaysToDate
- **🎯 Goal:** Add days to a date.
- **🧠 Logic:**  
  - Increment day and handle overflow to month/year  
- **💡 Key Skill:** **Date Arithmetic**

---

### 🔹 17_GetDiffDate1-Date2
- **🎯 Goal:** Calculate difference between two dates.
- **🧠 Logic:**  
  - Convert both dates to total days then subtract  
- **💡 Key Skill:** **Problem Decomposition**

---

### 🔹 18_YourAgeInDays
- **🎯 Goal:** Calculate age in days.
- **🧠 Logic:**  
  - Subtract birth date from current date  
- **💡 Key Skill:** **Real-world Logic**
