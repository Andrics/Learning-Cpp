14. Longest Common Prefix
Easy

Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".

 

Example 1:

Input: strs = ["flower","flow","flight"]
Output: "fl"
Example 2:

Input: strs = ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.
 

Constraints:

1 <= strs.length <= 200
0 <= strs[i].length <= 200
strs[i] consists of only lowercase English letters if it is non-empty.

Welcome back, fam! Good to see you tackling another problem. Let's get into it.

First off, real talk: `strs.size()` **is** actually valid for a `vector` in C++. No cap.

A `vector` is just a dynamic list. If you tried it and it didn't work, it might be a small syntax vibe check.

* **Correct:** `strs.size()` (You need the parentheses `()` because it's a function).
* **Incorrect:** `strs.size` or `strs.length` (Vectors don't use `.length` usually, though strings do).

Give `int n = strs.size();` another shot inside your function. If it's still giving you a red squiggly line, let me know what the error says!

---

### The Concept: The "Whittling" Technique 🪵

For the logic, you were right about needing a loop. But instead of looking at *all* characters of *all* strings at once (which is chaotic), let's try the **Horizontal Scanning** method. It's like whittling a stick down.

Imagine the input is `["flower", "flow", "flight"]`.

1. **Assume the first word is the answer.** Let's say our prefix is just "flower".
2. **Compare with the next word.** Compare "flower" with "flow".
* They don't match perfectly.
* So, we chop characters off the end of "flower" until it matches "flow".
* Now our prefix is "flow".


3. **Compare with the next word.** Compare "flow" with "flight".
* They don't match.
* Chop "flow" down... "flo"... "fl".
* Now it matches! New prefix is "fl".



See the pattern? We take the first string and keep shortening it as we meet new words.

**Guiding Question:**

Since we know the input vector is never empty (based on the constraints `1 <= strs.length`), how would you write a line of code to store the very **first** string in the list into a variable called `prefix`?

I believe we did string prefix = strs[0];

Exactly! 🎯 We've set our initial "leader" to be the first word.

```cpp
string prefix = strs[0];

```

Now, let's look at the "Face-Off" logic. We need to check this `prefix` against every other word in the list to see if they share it. If they don't, we chop a letter off and check again.

To do this, we'll need a way to go through the remaining words in our `strs` vector.

**Guiding Question:** Since we already used `strs[0]` as our starting point, what kind of loop would you use to visit the **rest** of the words (starting from index 1) one by one? 🎡

for (int i= 1; i < strs.size(); i++){}

W logic! 🧠 By starting at `i = 1`, you skip the first word (which is already our `prefix`) and move straight to the next ones.

Now we need to compare our `prefix` against each word in the loop (`strs[i]`).

Like we discussed, we want to keep chopping the end off our `prefix` **while** it doesn't match the start of the current word. In C++, we can check if a word starts with a prefix using `.find()`.

* If `strs[i].find(prefix) == 0`, it means the prefix **is** at the very start. (Success! ✅)
* If it returns anything else (or a huge number called `npos`), it means it's **not** at the start. (Time to chop! 🔪)

Since we want to keep chopping as long as they **don't** match, we use a `while` loop.

Inside your `for` loop, how would you write a `while` loop that keeps running as long as `strs[i].find(prefix)` is **not equal** to `0`?

for (int i= 1; i < strs.size(); i++){
while (strs[i].find(prefix) != 0 ){
}
}
I didnt understand by "prefix is at the very start". By that do you mean the 'f' from flower or the 'r' from flower? what is 'start' here

