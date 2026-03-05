Complete the solution so that it reverses the string passed into it.

'world'  =>  'dlrow'
'word'   =>  'drow'

Meow! I got a new C++ problem!
Complete the solution so that it reverses the string passed into it.
'world'  =>  'dlrow'
'word'   =>  'drow'
I tried to do it myself and came up with this!
#include <iostream>
#include <string>
using namespace std;

string reverseString(const string &str)
{
    int stringSize = str.size();
    string reversedString = "";
    char letter;
    while (stringSize > -1)
    {
        letter = str[stringSize];
        reversedString += letter;
        stringSize--;
    }
    return reversedString;
}

int main()
{
    string str = "Hello Meow";
    string result = reverseString(str);
    cout << result << endl;
}
What do you think?

Yo! Nice work on the logic! You’ve got the right idea—looping through the string backward and building a new one. That's a classic way to handle this. 💻✨

However, if you run this, you might notice something "sus" happening. In C++, strings use **0-based indexing**. This means if a string has a size of 5 (like "world"), the letters are at positions **0, 1, 2, 3, and 4**.

Take a look at your `while` loop start:

```cpp
int stringSize = str.size(); // If str is "world", this is 5
...
letter = str[stringSize]; // This is looking for str[5]

```

Since the last valid index is actually **4**, looking for index **5** is like trying to find a seat that doesn't exist. This usually causes a crash or adds a weird hidden character (the null terminator) to the start of your result.

How do you think we should tweak the starting value of `stringSize` so it points to the actual last letter of the string? 🔍🐢

We do this? int stringSize = str.size() - 1;

Spot on! 🎯 Since the index starts at **0**, the last character is always at **size - 1**.

Now that we've fixed the starting point, let's look at the "stop" condition in your loop. Currently, you have:

```cpp
while (stringSize > -1)

```

This works, but in C++, it's usually cleaner to use `>= 0`.

There's one more sneaky detail though. In your original code, you used an `int` for `stringSize`. However, `.size()` actually returns a type called `size_t` (which is an **unsigned** integer). Unsigned numbers can never be negative—if they go below zero, they "wrap around" to a massive positive number.

If we changed `int stringSize` to `size_t stringSize`, how do you think that might affect our `while (stringSize >= 0)` loop? 🤔

this is the first time i've heard of unisigned and signed int or size_t, what're these things?

Let's break those down!

* **Signed `int**`: This is your default integer. It has a plus or minus "sign". It can hold positive numbers, negative numbers, and zero (like temperature: -10, 0, 25). 🌡️
* **Unsigned `int**`: This type **cannot** be negative. It only holds zero and positive numbers (like a step counter: 0, 10, 500). Because it doesn't need to save space in memory for a minus sign, its maximum positive limit is twice as big as a normal `int`. 👟
* **`size_t`**: This is just C++'s specific version of an unsigned integer used specifically for measuring the *size* or *length* of things in memory. Since a string can never have a negative length (you can't have a string with -3 letters), functions like `.size()` always return a `size_t`. 📏

Here is the sneaky part: if an unsigned number is at `0` and you subtract `1`, it physically cannot go to `-1`. Instead, it "underflows" and wraps all the way around to its absolute maximum possible value (which is usually over 4 billion!). 🔄

Knowing that it wraps around to a massive positive number instead of going negative, what do you think would happen to our `while (stringSize >= 0)` loop when `stringSize` is exactly `0` and we run `stringSize--`?

stringSize will turn into a crazy value!     

Exactly! Big W. 🏆

Because it wraps around to that massive positive number, it will *never* be less than 0. Your `while` condition would always be true, and your program would get stuck in an **infinite loop** until it crashes. ♾️💀

This is why your original instinct to use a regular, signed `int` was actually super smart. It allows the counter to safely drop to `-1` so the loop knows when to stop.

If we put your fixes together, the core of your code looks like this:

```cpp
int stringSize = str.size() - 1; // Starts at the actual last letter
string reversedString = "";
char letter;

while (stringSize >= 0) // Safely stops when it drops below 0
{
    letter = str[stringSize];
    reversedString += letter;
    stringSize--; // Moves backwards!
}

```

If you plug this back into your `reverseString` function, it'll work perfectly!

Since you've totally nailed the logic here, would you like to see how to write this exact same thing using a `for` loop (which is super common for this kind of problem in C++), or are you ready to tackle a brand new problem? 🚀

Bet! Let's level up. 🚀

Right now, your code creates a brand new string to hold the reversed word. That means if your string is a million characters long, you need memory for *another* million characters. That's `O(N)` memory space. Not the best vibe for memory usage! 🙅‍♂️

To save memory and get that `O(1)` space complexity, we can do an **in-place** reversal. This means we don't create a new string at all. Instead, we just shuffle the letters around inside the original string.

Think of a technique called **Two Pointers**:

1. You put one pointer at the start of the word (index `0`).
2. You put another pointer at the end of the word (index `size - 1`).

If the word is "word", the start pointer is looking at **'w'** and the end pointer is looking at **'d'**. If we swap those two letters, the string becomes "dorw". 🔄

After swapping the first and last letters, what do you think we should do with our two pointers to keep reversing the rest of the word? 👀🧠

Hmm, I'll give it a try, also look at this I gave it a try with for lop:
string reversedString = "";
        for (int i = str.size() - 1; i >= 0; i--)
        {
            reversedString += str[i];
        }
        return reversedString;

        W logic! That `for` loop is super clean and much easier to read than the `while` loop. It’s basically the industry standard for this kind of task.

But since you're looking for that **peak performance** (less memory and faster speed), let's dive into that "in-place" swap idea.

Right now, your code is like buying a whole new notebook just to write a word backward. The "in-place" way is like just erasing and rewriting the letters in the notebook you already have.

We have our two pointers:

1. **`left`** starts at `0`.
2. **`right`** starts at `str.size() - 1`.

To swap them, C++ has a built-in helper called `swap(str[left], str[right])`.

Once we swap the first and last letters, we need to move the pointers toward the middle so we can swap the next pair. If we want to move `left` forward and `right` backward, what should we do to their values? 🏎️💨

ok I understand the logic we will increment from the left and decrement from the right, but how do we form the loop?

That’s exactly the move! 🏎️ By incrementing `left` and decrementing `right`, they’ll eventually meet in the middle of the string.

To form the loop, we need a condition that tells the program to keep swapping as long as the pointers haven't crossed each other yet.

If we have a word like "cat":

1. **Start:** `left` is at 'c' (index 0), `right` is at 't' (index 2). We swap them. 🔄
2. **Move:** `left` becomes 1, `right` becomes 1. They are now both pointing at 'a'.

Once they meet at the same letter (or pass each other), there’s nothing left to swap!

Based on that, what do you think the condition inside our `while` loop should be to keep it running? 💡🦑

I gave it a shot, I'm getting an error on the word swap : "no instance of overloaded function "swap" matches the argument list argument types are: (const char, const char)"
int right = str.size() - 1;
    while (i != right)
    {
        swap(str[i], str[right]);
        i++;
        right--;
    }

    That error is happening because of a small but important detail in your function signature! 🕵️‍♂️

In your original code, you defined the function like this:
`string reverseString(const string &str)`

The keyword **`const`** is like a "read-only" lock. It tells C++ that the function is allowed to look at the string, but it is strictly forbidden from changing it. Since `swap` tries to move the letters around inside that string, C++ blocks it to protect the "read-only" rule. 🔒

To do an **in-place** reversal, we need to work on a version of the string that we are allowed to change. 🛠️

If you remove the `const` and the `&` from the parameter, or if you create a copy of the string inside the function, you'll have a version you can freely swap.

Also, looking at your loop condition:

```cpp
while (i != right)

```

This works perfectly for strings with an **odd** number of letters (like "cat"), where they meet exactly at the middle letter. But what do you think happens with an **even** number of letters (like "word"), where the pointers might "jump" past each other without ever being equal? 🧐 Envisioning them crossing paths, what operator could we use instead of `!=` to make sure the loop stops correctly in both cases?

:(

    No worries! Think of it like a race where two people are running toward each other from opposite ends of a track. 🏃‍♂️....🏃‍♂️

If they keep running, they eventually pass each other. In our string reversal, if `left` becomes **greater** than `right`, it means we've already swapped everything and are now just swapping them back to their original spots!

To prevent that, we want the loop to run only while the pointers haven't crossed.

Check out this logic:

```cpp
// We removed 'const' and '&' so we can modify 'str'
string reverseString(string str) 
{
    int left = 0;
    int right = str.size() - 1;

    // What condition goes here to make sure they don't cross?
    while (left < right) 
    {
        swap(str[left], str[right]);
        left++;
        right--;
    }
    return str;
}

```

By using **`left < right`**, the loop stops the moment they meet (for odd strings) or pass each other (for even strings). This is the "Gold Standard" because:

1. **Speed**: We only loop through *half* the string. ⚡
2. **Memory**: We don't create a second string; we just flip the letters in the one we have. 🧠

Since you mentioned you're a beginner, do you want to try writing the `main` function to test this new version, or should we look at how `swap` actually works under the hood? 🛠️


#include <iostream>
#include <string>
using namespace std;

string reverseString(const string &str)
{
    int right = str.size() - 1;
    int i = 0;
    string toReverse = str;
    while (i < right)
    {
        swap(toReverse[i], toReverse[right]);
        i++;
        right--;
    }
    return toReverse;
}
int main()
{
    string str = "Hello Meow";
    string result = reverseString(str);
    cout << result << endl;
}
Here you go, and yes, teach me more about swap


This code looks great! 🚀 By using `string toReverse = str;`, you created a copy that you're allowed to change, and your `while (i < right)` condition perfectly handles both even and odd-length strings. You just implemented a **Two-Pointer** algorithm, which is a big deal in technical interviews!

### How `swap` Works Under the Hood 🛠️

Think of `swap` like having a glass of **Mango Lassi** 🥭 and a glass of **Rooh Afza** 🌹. If you want to switch the liquids into each other's glasses, you can't just pour one into the other, or they'll mix. You need a **third, empty glass** to help.

In C++, `swap(a, b)` essentially does this:

1. **Temp Glass**: It takes a temporary variable and puts the value of `a` into it.
2. **Move B**: It puts the value of `b` into `a`.
3. **Move Temp**: It takes the value from the temporary variable and puts it into `b`.

Here is how that looks in basic logic:

```cpp
char temp = a;
a = b;
b = temp;

```

### Why this is "Peak Performance" 🏎️

By swapping "in-place" like this, you aren't building a whole new string character-by-character in a loop. You are just rearranging what’s already there.

* **Time Complexity**: We only go through half the string, so it's very fast.
* **Memory Usage**: Since we are just moving letters around inside the string, we don't need extra space for a second string (other than the copy we made).

### What's Next?

Now that you've mastered reversing a string, we could try something slightly harder using the same "Two-Pointer" logic. Which of these sounds more fun?

1. **Palindrome Checker**: Check if a word is the same forward and backward (like "level" or "racecar"). 🏎️
2. **Vowel Remover**: Write a loop that "yeets" all the vowels out of a string. 🚫🍎
3. **Array Basics**: See how these same logic rules apply to a list of numbers instead of letters. 🔢