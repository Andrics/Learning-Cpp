Create a function that takes an integer as an argument and returns "Even" for even numbers or "Odd" for odd numbers.

Let’s dive right into your C++ code, and I’ll ask some guiding questions along the way to explore it further.

Your logic correctly solves the problem. It is completely valid and already hits the best baseline for performance. Here is the breakdown:

* ⏱️ **Time Complexity:** O(1) — It takes constant time. You are doing one quick math check, so it runs instantly no matter how huge the number is.
* 💾 **Memory Usage:** O(1) — It takes constant space. You aren't creating any extra arrays or variables, just returning a string.

Honestly, using the modulo operator (`%`) is the standard, most readable way to do this in the industry. No cap.

However, since you're studying Software Engineering, there is a low-level hardware trick we can use to check for even or odd numbers that is technically a tiny bit faster than using `%` (which uses division behind the scenes).

To figure out this alternative method, let's think about how numbers are stored under the hood. Do you know what the very last bit (the rightmost digit) of a binary number tells us about whether it is even or odd?

In the tens place?

You're thinking of our everyday counting system (base-10), where we have the ones, tens, hundreds, and so on.

Binary (base-2) works differently since computers only use `0`s and `1`s. Instead of multiplying by 10 as you move left, the place values double each time.

Here's a quick look at how the place values line up in binary:

| ... | Sixteens (16) | Eights (8) | Fours (4) | Twos (2) | Ones (1) |
| --- | --- | --- | --- | --- | --- |
| ... | 0 | 1 | 0 | 1 | **?** |

Notice that every single place value as you move left (2, 4, 8, 16...) is an even number. The *only* exception is that very last spot on the far right, which is the **ones** place.

If every other bit adds an even amount to the total value, what digit (a `0` or a `1`) do you think needs to be in that rightmost "ones" place to make the entire number odd?

a 1

Spot on! Huge W.

Exactly. If that very last bit is a `1`, the number is odd. If it's a `0`, it's even.

Because computers speak binary natively, checking just that last bit is super fast for the CPU. It's a total big brain move compared to using modulo (`%`), which actually forces the computer to do heavier division math under the hood.

To check this in C++, we use the **Bitwise AND** operator, which is just a single ampersand: `&`.

When you run `number & 1`, it basically masks (hides) all the other bits and *only* looks at that rightmost ones place.

Here is how the logic plays out:

* If the number is odd, `number & 1` gives you `1` (which C++ reads as `true`).
* If the number is even, `number & 1` gives you `0` (which C++ reads as `false`).

Do you want to take a stab at rewriting your function using this `&` trick, or should I drop the updated code for you to see?

so something like:
return number & 1 ? "Odd" : "Even";?

Exactly! You cooked. That is 100% correct.

Since `number & 1` results in `1` (which means `true` in C++) for odd numbers, your ternary operator perfectly catches "Odd" first, and defaults to "Even" if it's `false`.

Here is your final, fully optimized code:

```cpp
#include <string>
using namespace std;

string even_or_odd(int number) 
{
  return (number & 1) ? "Odd" : "Even";
}

```

*(Just a quick tip: I added parentheses around `(number & 1)`. C++ usually figures it out without them, but adding them is a super common habit to make the code easier to read and to prevent weird order-of-operation bugs later down the line!)*

