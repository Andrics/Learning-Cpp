Problem Name: Palindrome Number

Palindrome Number

Easy

Given an integer x, return true if x is a , and false otherwise.
 
Example 1:

Input: x = 121
Output: true 
Explanation: 121 reads as 121 from left to right and from right to left.

Example 2:

Input: x = -121
Output: false
Explanation: From left to right, it reads -121. From right to left, it becomes 121-. Therefore it is not a palindrome.

Example 3:

Input: x = 10
Output: false
Explanation: Reads 01 from right to left. Therefore it is not a palindrome.
 
Constraints:

-231 <= x <= 231 - 1
 
Follow up: Could you solve it without converting the integer to a string?"

If we have the number 1234, doing 1234 % 10 gives us the last digit: 4.



Do you know which math symbol we use in C++ to find the remainder of a division?
 I'm guessing it's the % symbol? 
 Yes, the % (modulo) symbol is exactly what we need!

If we have the number 1234, doing 1234 % 10 gives us the last digit: 4.

-121.

This is a negative number. It has a minus sign (-) at the very beginning.

If we read -121 backwards, the minus sign ends up at the very end (it becomes 121-).

Because of this minus sign moving to the back, what can we automatically say about all negative numbers when we write our C++ code?

If the number is negative it automatically wont be a palindrome!

 Gemini said

You got it! 🎯

Any number less than zero is instantly a "no".

Let's look at one more quick rule to make our code even faster. Check out Example 3:

    Input: x = 10

    Output: false

When we read 10 backwards, it becomes 01. Normal numbers don't start with a zero (unless the number is just the digit 0 by itself).

Thinking about that, what can we automatically say about other numbers that end with a zero, like 20, 100, or 250?

Any number ending with a zero is not a palindrome! Because no normal number starts with 0! 

 Gemini said

That is exactly right. Any number ending in zero is out, with one small exception: the number 0 itself is a palindrome.

So, we have our two quick rules to stop early:

    If the number is negative 🛑

    If the number ends in zero (but isn't exactly 0) 🛑

Now, let's figure out how to read a number backwards in C++ without turning it into text.

To do this, we need to "chop off" the digits one by one, starting from the very end. For example, we need a way to grab the 4 out of 1234.

In C++, we can get that last digit by finding the remainder when we divide the number by 10 (since 1234 divided by 10 is 123, with a remainder of 4).

Do you know which math symbol we use in C++ to find the remainder of a division?

 I'm guessing it's the % symbol? 

  Gemini said

Yes, the % (modulo) symbol is exactly what we need!

If we have the number 1234, doing 1234 % 10 gives us the last digit: 4.

After we grab that 4, we need to chop it off the original number so 1234 becomes 123. In C++, when you divide an integer by 10 using the / symbol, it throws away the decimal. So, 1234 / 10 becomes exactly 123.

Now we have a way to pull digits off one by one! Let's think about how to build our new reversed number.

Imagine we are building the reversed number and we already pulled off the 4. Our reversed number is currently 4.
Next, we pull off the 3. We want to stick this 3 onto the end of the 4 to make 43.

Before we can add the 3, we need to make room for it by turning that 4 into a 40.

What simple math operation can we do to turn a 4 into a 40?

multiply it by 10!!!

 Gemini said

Spot on!

So, to build our reversed number step-by-step:

    First, we take our current reversed number (which is 4).

    We multiply it by 10 to get 40.

    Now we have our next chopped-off digit (the 3).

What simple math symbol do we use to combine the 40 and the 3 to make 43?

We'll add them!!

 Gemini said

Yes, exactly! We just add them using the + symbol (40 + 3 = 43).

So, our repeating steps to build the backward number are:

    Grab the last digit: last_digit = x % 10

    Add it to our new number: reversed_num = (reversed_num * 10) + last_digit

    Chop the last digit off the original number: x = x / 10

We need to keep repeating these three steps over and over until we run out of digits to chop off.

Let's think about when to stop. If we keep chopping off the last digit by dividing our original number by 10 (for example: 121 becomes 12, then 1, and then eventually we run out of digits), what number will our original x reach when we are completely done?

x will be 0!

Cool C++ Trick: Instead of writing the whole if / else block at the very end, you can just write: return reversedNum == originalNum;. It does the exact same thing in just one line!

Step 2: The Hidden LeetCode Trap
LeetCode loves to test extremely large numbers to see if your code breaks.

In C++, a regular int is like a box that can only hold numbers up to about 2 billion.

Imagine our original number is 2,000,000,009. That fits in the int box perfectly. But when we build our reversed number, it becomes 9,000,000,002 (9 billion!).

Because 9 billion is bigger than 2 billion, it will "overflow" our int box and cause the program to crash.

To fix this, we just need to change the "box type" for our reversedNum variable so it can hold much bigger numbers.

Do you know the name of the data type in C++ that is a step larger than a regular int?

long!

Bug 2: The "Garbage" Number

Look at the very top of your function:
C++

int reversedNum, remainder = 0;

Here, you perfectly set remainder to 0. However, you didn't give reversedNum a starting number.

In C++, if you create a box for a number but don't put a starting number inside it, the computer fills it with random, crazy "garbage" data (like 4193824). When your loop tries to do math with reversedNum, it starts multiplying that crazy garbage number!

Also, remember our LeetCode trap from last time? reversedNum needs the bigger box (long long) so it doesn't crash on giant numbers.

How to fix it: Split them up and give them both a starting 0:

#include <iostream>
#include <math.h>
using namespace std;

class Solution
{
public:
    bool isPalindrome(int x)
    {
        int remainder = 0;
        long long reversedNum = 0;
        int originalNum = x;
        if (x < 0)
        {
            return false;
        }
        if (x == 0)
        {
            return true;
        }
        if (x % 10 == 0)
        {
            return false;
        }
        while (x > 0)
        {
            remainder = x % 10;
            x = x / 10;
            reversedNum = (reversedNum * 10) + remainder;
        }
        return reversedNum == originalNum;
    }
};

int main()
{
    int x = 12321;
    Solution s1;
    bool result = s1.isPalindrome(x);
    if (result == true)
    {
        cout << "It is a Palindrome" << endl;
    }
    else
    {
        cout << "Not a Palindrome" << endl;
    }
}