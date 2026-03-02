13. Roman to Integer
Easy

Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.

Symbol       Value
I             1
V             5
X             10
L             50
C             100
D             500
M             1000
For example, 2 is written as II in Roman numeral, just two ones added together. 12 is written as XII, which is simply X + II. The number 27 is written as XXVII, which is XX + V + II.

Roman numerals are usually written largest to smallest from left to right. However, the numeral for four is not IIII. Instead, the number four is written as IV. Because the one is before the five we subtract it making four. The same principle applies to the number nine, which is written as IX. There are six instances where subtraction is used:

I can be placed before V (5) and X (10) to make 4 and 9. 
X can be placed before L (50) and C (100) to make 40 and 90. 
C can be placed before D (500) and M (1000) to make 400 and 900.
Given a roman numeral, convert it to an integer.

 

Example 1:

Input: s = "III"
Output: 3
Explanation: III = 3.
Example 2:

Input: s = "LVIII"
Output: 58
Explanation: L = 50, V= 5, III = 3.
Example 3:

Input: s = "MCMXCIV"
Output: 1994
Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.
 

Constraints:

1 <= s.length <= 15
s contains only the characters ('I', 'V', 'X', 'L', 'C', 'D', 'M').
It is guaranteed that s is a valid roman numeral in the range [1, 3999].


If you have a string like "MCMXCIV", what's the standard way in C++ to go through it, one character at a time?

Oh so that's how you do it!. I was thinking it was something like  roman['I'] = 1;

And the standard way of going through the string is through the enhanced for loop?

You actually nailed it with `roman['I'] = 1;`! That totally works if you make an empty map first. The way I showed is just a quick shortcut to do it all at once. Big brain energy either way! 🧠

About the loop: An enhanced for loop (`for (char c : s)`) is usually the GOAT for strings. 🐐

**BUT**, remember that sneaky subtraction rule? Like in `IV` (4)?

To know we need to subtract, we have to look at our current letter *and* peek at the **next** letter to see if it's bigger. Peeking ahead is kinda tough with an enhanced for loop because it only gives you one letter at a time.

Because of this, a classic index-based `for` loop is the move here. It lets us check our current letter at `s[i]` and easily peek at the next one at `s[i+1]`. 👀

What does the setup for a standard `for` loop look like in C++ to count from `0` up to the end of our string `s`?

something like for (int i = 0; i < s.length(); i++){}?

Exactly! 💯 That loop is perfect.

Now let's build the brain of our loop inside those curly braces `{}`.

We need to check for that sneaky subtraction rule (like in `IV`). The rule kicks in if the value of our *current* letter is **less than** the value of the *next* letter.

Remember, we can look up the math value of the current letter using our cheat sheet like this: `roman[s[i]]`. And we can peek at the next letter using `s[i+1]`.

Based on that, how would you write an `if` statement to check if the current letter's value is strictly less than the next letter's value? 🤔

wait but isn't s a string? how can we use s like s[i], that's confusing

It definitely looks a bit weird at first! In C++, a string is basically just an array (or a list) of single characters lined up next to each other. 🧍🧍🧍

Because they are in a line, each character gets its own numbered "seat" (index), always starting at 0.

For example, if we have a string `s = "CAT"`:

* `s[0]` is 'C'
* `s[1]` is 'A'
* `s[2]` is 'T'

So, using `s[i]` is just a quick way to ask the string, "Hey, what letter is sitting in seat `i`?"

When we combine that with our map, `roman[s[i]]` gets the math value of the letter sitting in seat `i`. And `roman[s[i+1]]` peeks at the value of the letter in the *next* seat. 👀

Knowing this, how would you write the `if` statement to check if the current letter's value is strictly **less than** the next letter's value?

something like this?
if (romanMap[s[i + 1]] > romanMap[s[i]])
            {
                result = romanMap[s[i + 1]] + romanMap[s[i]];
                continue;
            }
            result += romanMap[s[i]];

            You nailed the `if` condition! `if (romanMap[s[i + 1]] > romanMap[s[i]])` is exactly right for spotting the sneaky rule. Big W! 🏆

Let's look at what happens *inside* those curly braces, though. We have a couple of bugs to squash:

* **The Math:** For `IV`, `V` is 5 and `I` is 1. We want 4. Your code uses `+`, which makes $5 + 1 = 6$.
* **The Total Score:** Using `=` by itself wipes out our whole `result` history. We need to update the running total.
* **The Double Counting:** If you process *both* letters at once inside the `if`, the loop is still going to move forward by 1 and look at that second letter again anyway. It gets messy trying to skip ahead.

Here is a massive shortcut that makes the logic way easier: **Just subtract the current letter.** 🧠

Let's look at `IV` again with this trick:

1. We look at `I`. The next letter `V` is bigger.
2. So, instead of adding `I`, we just **subtract** `I` from our total. (`result` is now -1)
3. On the next loop, we look at `V`. There's nothing bigger after it, so we add it normally. (`result` is now -1 + 5 = 4).

How would you rewrite the inside of your `if` statement to *only* subtract the current letter (`romanMap[s[i]]`) from your `result`?

Gemini sama! I gave it a shot:
#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

class Solution
{
public:
    int romanToInt(string s)
    {
        char nextLetter;
        unordered_map<char, int> romanMap = {
            {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};
        int result = 0;
        for (int i = 0; i < s.length(); i++)
        {
            if (romanMap[s[i + 1]] > romanMap[s[i]])
            {
                result -= romanMap[s[i]];
                continue;
            }
            else
            {
                result += romanMap[s[i]];
            }
        }
        return result;
    }
};
int main()
{
    Solution S1;
    string s1 = "III";
    string s2 = "LVIII";
    string s3 = "MCMXCIV";

    int result = S1.romanToInt(s1);
    int result2 = S1.romanToInt(s2);
    int result3 = S1.romanToInt(s3);
    cout << "Results: " << result << endl;
    cout << result2 << endl;
    cout << result3 << endl;
}


Your math logic is completely correct and this code actually outputs the exact right answers! 🎯

There is one sneaky bug hiding at the very end of the word, though. When your loop reaches the *last* letter, `s[i+1]` tries to peek at a seat that doesn't exist.

In C++, this accidentally works out. Looking past the end of a string grabs a blank character (`\0`). Your map sees that blank character, doesn't recognize it, and just assigns it a `0`. Since `0` is never bigger than a Roman numeral, the code safely moves to your `else` block.

However, relying on "Out of Bounds" memory like this is a bad habit that will usually crash your program in other situations. 💥

*(Also, a quick pro-tip: since you have an `else` block handling the alternative, you don't actually need that `continue` keyword inside the `if`!)*

To make this code bulletproof, how could we update your `if` condition to make sure it only peeks at `s[i+1]` if we *aren't* currently sitting on the very last letter?

if (s[i + 1] == s.length())
            {
                break;
            }
like this? I'm assuming you add it to the end of the for loop?

You're totally on the right track! 🚂 You realized we need to use the string's length to know when to stop.

But there are two tiny hiccups with writing it exactly like that:

1. **The Timing:** If we put this check at the *end* of the loop, it's too late! The code already did the illegal peek at `s[i+1]` at the top of the loop. We gotta block the peek *before* it happens.
2. **The Mix-up:** Remember our seat analogy? `i + 1` is the **seat number**, but `s[i + 1]` is the actual **letter** sitting in that seat (like 'V' or 'X'). Right now, your code is trying to compare a letter to a number (`s.length()`), which makes C++ confused. 😵‍💫

Instead of a separate `if` statement, we can actually smush a safety check right into your main `if` statement using the logical AND operator (`&&`).

In C++, `&&` reads left to right. If the first part is false, it completely skips the second part!

Knowing this, how could we update your `if` condition to say:
*"IF the next seat number (`i + 1`) is less than `s.length()` **AND** the next letter is bigger..."*?


like this? 
 if ((i + 1) != s.length() && romanMap[s[i + 1]] > romanMap[s[i]])
            {
                result -= romanMap[s[i]];
            }


            Spot on! 🎯 That is literally perfect.

By putting that safety check `(i + 1) != s.length()` first, you completely protect the code. Because of how `&&` works in C++, if that first part is false (meaning there is no next seat), it just goes "nope!" and skips reading the second half entirely. 🛡️

This means no more out-of-bounds memory bugs, and it safely drops right down into your `else` block. You cooked! 🧑‍🍳

Before we lock in the final code and get that LeetCode submission, let's make sure the logic totally clicks.

When your loop reaches the very last letter of a string, exactly what does your new `if/else` setup do with that final letter's value?

it does a return result; !

You're totally right that `return result;` is the grand finale! 🎆

But right before the loop finishes, let's look at what the `if/else` block actually does to that very last letter.

When we are sitting on the final letter, the next seat number (`i + 1`) is exactly equal to the string's length (`s.length()`).

Because of that, does the first half of our safety check `((i + 1) != s.length())` come out **True** or **False**? 🤔


it will be false

Exactly! 💯 It comes out **False**.

Because of how that `&&` operator works, the moment it sees **False** on the left side, it just stops. It completely skips the dangerous peek at the next letter on the right side.

Since the `if` condition fails, your code drops straight into the `else` block and simply adds the value of that very last letter to your `result`. Which is exactly what we want!

You've officially squashed all the bugs and the logic is rock solid. 🪨

Are you ready to put all these pieces together into one final, clean `romanToInt` function so we can go get that LeetCode "Accepted" screen? Let's see your final code! 🚀

This is my final function:
int romanToInt(string s)
    {
        unordered_map<char, int> romanMap = {
            {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};
        int result = 0;
        for (int i = 0; i < s.length(); i++)
        {

            if ((i + 1) != s.length() && romanMap[s[i + 1]] > romanMap[s[i]])
            {
                result -= romanMap[s[i]];
            }
            else
            {
                result += romanMap[s[i]];
            }
        }
        return result;
    }

Is there a better way of doing this, like, with less runtime complexity or memory usage? or is this the best practice?