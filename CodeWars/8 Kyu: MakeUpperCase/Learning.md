Problem: MakeUpperCase
Write a function which converts the input string to uppercase.

 Gemini said

Let's tackle this C++ problem together. I will help guide you through it step-by-step with a few simple questions.

To make the whole string uppercase, we need to handle it one letter at a time. Notice that the input str has const 🔒 next to it. This means the original string is "locked" and we cannot change it directly.

Because we cannot change the original string, what is the very first thing we should create inside our function to hold our final result?

a variable that would be the uppercased version of the original string? 

 Gemini said

Spot on. We will create a new, empty string to hold our answer. In C++, it looks like this:

string result = "";

Now that we have our empty result 🧵, we need to look at every single letter inside the original str, one by one.

What kind of programming tool can we use to repeat an action and go through each letter?

for loop! 

 Gemini said

Exactly! A for loop is perfect for this. 🔄

Here is how our code is shaping up so far:
C++

string result = "";
for (char letter : str) {
    // we will do something with 'letter' here
}

Inside that loop, we need to change each letter to uppercase. C++ has a handy built-in tool just for this exact job called toupper().

Once we use toupper() to make the letter uppercase, what do we need to do with it so it becomes part of our final result string?

 Gemini said

You nailed it! That is exactly what it is called: concatenation. ➕

Let's break down the pieces we have so far in plain and simple steps:

1. The Shortcut Loop 🔄
The loop for (char letter : str) is just a handy shortcut. Instead of counting with int i, it does the work for you. You can read it like this: "For every character (let's call it letter) inside our string str, do this." It automatically goes through the word from start to finish.

2. Concatenation 🔗
In C++, the easiest way to glue a new letter to the end of a string is by using the += operator.

Now, let's put your ideas together! We know we need to use toupper(letter) to get the big, uppercase version of the letter.

How would you write the exact line of code inside the loop to add that uppercase letter to our result string?

 Gemini said

Your code is exactly right! 🎉 You put all the pieces together perfectly, and this will solve the Codewars problem.

It is completely normal to be confused about int main(). That is a very smart question to ask.

Here is the simple reason why it uses int (which stands for integer, or a whole number) instead of string:

    Normal functions 🛠️ (like your makeUpperCase) talk to your code. You wanted it to give you back a word, so it returns a string.

    The main() function 👑 is special. It does not talk to your code; it talks directly to the computer (the operating system).

The computer does not care about the words or text your program makes. It only wants to know one thing: "Did this program finish successfully, or did it crash?"

To answer the computer, main() uses numbers:

    Returning 0 tells the computer: "Zero problems! The job is done."

    Returning any other number means: "We had an error."

(Note: In modern C++, if you forget to type return 0; at the very end of main, the program is smart enough to do it for you automatically!)


#include <string>
#include <iostream>
using namespace std;

string makeUpperCase(const string &str)
{
    string result = "";
    for (char letter : str)
    {
        result += toupper(letter);
    }
    return result;
};

int main()
{
    string str = "exAmplE";
    string result = makeUpperCase(str);
    cout << result;
}