12. Integer to Roman
Medium

Seven different symbols represent Roman numerals with the following values:

Symbol	Value
I	1
V	5
X	10
L	50
C	100
D	500
M	1000
Roman numerals are formed by appending the conversions of decimal place values from highest to lowest. Converting a decimal place value into a Roman numeral has the following rules:

If the value does not start with 4 or 9, select the symbol of the maximal value that can be subtracted from the input, append that symbol to the result, subtract its value, and convert the remainder to a Roman numeral.
If the value starts with 4 or 9 use the subtractive form representing one symbol subtracted from the following symbol, for example, 4 is 1 (I) less than 5 (V): IV and 9 is 1 (I) less than 10 (X): IX. Only the following subtractive forms are used: 4 (IV), 9 (IX), 40 (XL), 90 (XC), 400 (CD) and 900 (CM).
Only powers of 10 (I, X, C, M) can be appended consecutively at most 3 times to represent multiples of 10. You cannot append 5 (V), 50 (L), or 500 (D) multiple times. If you need to append a symbol 4 times use the subtractive form.
Given an integer, convert it to a Roman numeral.

 

Example 1:

Input: num = 3749

Output: "MMMDCCXLIX"

Explanation:

3000 = MMM as 1000 (M) + 1000 (M) + 1000 (M)
 700 = DCC as 500 (D) + 100 (C) + 100 (C)
  40 = XL as 10 (X) less of 50 (L)
   9 = IX as 1 (I) less of 10 (X)
Note: 49 is not 1 (I) less of 50 (L) because the conversion is based on decimal places
Example 2:

Input: num = 58

Output: "LVIII"

Explanation:

50 = L
 8 = VIII
Example 3:

Input: num = 1994

Output: "MCMXCIV"

Explanation:

1000 = M
 900 = CM
  90 = XC
   4 = IV
 

Constraints:

1 <= num <= 3999

### 🛑 Hold Up, Let's Reset!

Hey, absolutely no stress! Please don't apologize. LeetCode Mediums are notoriously confusing, and the jump from Easy to Medium is no joke. It is completely normal to feel lost here.

Since the logic is feeling super messy, let's drop the tech talk entirely. Let's look at a real-world example that makes this click.

### 🏧 The ATM Cheat Code

Think of this problem exactly like an ATM giving you cash.

If you go to an ATM and ask for **3749**, it doesn't spit out thousands of tiny coins. It is greedy; it gives you the **biggest notes possible** first.

Our Roman numerals are basically just cash notes: `M` is a 1000 note, `D` is a 500 note, `C` is a 100 note, etc.

If the ATM needs to give you **3749**:

1. **The 1000 Notes:** It checks if it can give you 1000s. It gives you three of them. (You get `MMM`). You still need 749.
2. **The 500 Notes:** It checks the 500s. It gives you one. (You get `D`). You still need 249.
3. **The 100 Notes:** It checks the 100s. It gives you two. (You get `CC`). You still need 49.

It just keeps going down the line of smaller and smaller notes until it hits 0.

### 💻 The Final Code

Instead of making you guess how to write it, here is the exact code. It's actually way shorter than it looks!

```cpp
class Solution {
public:
    string intToRoman(int num) {
        // Our "cash notes" lined up from biggest to smallest
        int values[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        string symbols[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        
        string result = "";
        
        // Step 1: Walk down the line of all 13 notes
        for (int i = 0; i < 13; i++) {
            
            // Step 2: While our number is big enough to use the current note...
            while (num >= values[i]) {
                result += symbols[i]; // Add the letter to our answer
                num -= values[i];     // Subtract the math value from our total
            }
        }
        
        return result;
    }
};

```

**Why this works in plain English:**
The `for` loop just says "Look at every note on the list, one by one."
The `while` loop is the ATM logic. It just says, "As long as the money I owe is bigger than this note, keep handing out this note and subtracting the value."

Does the ATM analogy make the logic feel a bit less crazy, or do you want to just copy-paste this into LeetCode to watch it get that "Accepted" screen? Let me know what you're thinking! 🧠✨