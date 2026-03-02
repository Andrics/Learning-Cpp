1. The "Standard" Way (Using Math)

Most languages have a built-in library for math. Instead of checking if the number is positive or negative, you can just find the absolute value (the positive version of any number) and then force it to be negative.


#include <stdlib.h> // This is needed for the abs() function

int makeNegative(int num)
{
  return -abs(num); 
}

    Why this is good: It’s just one line. It says: "Take the number, make it positive with abs, then put a minus sign in front."

2. The "Short" Way (Ternary Operator)

If you want to keep your logic but make it take up less space, you can use a ternary operator. Think of this as a "one-line if-else" statement.


int makeNegative(int num)
{
  return (num > 0) ? -num : num;
}

How to read this:

    Is num > 0?

    Yes? Return -num.

    No? Return num.

    According to CodeWars Best Practices:
    int makeNegative(int num) {
  return num > 0 ? -num : num;
}