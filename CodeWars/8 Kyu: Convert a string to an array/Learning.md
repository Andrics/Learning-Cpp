Convert a string to an array
Write a function to split a string and convert it into an array of words.
Examples (Input ==> Output):

"Robin Singh" ==> ["Robin", "Singh"]

"I love arrays they are my favorite" ==> ["I", "love", "arrays", "they", "are", "my", "favorite"]

 Gemini said

Let's break this down into easy, step-by-step pieces. I will ask you a few simple questions to guide you along the way.

First, do not worry about forgetting arrays! If you look closely at the starter code, it actually asks you to return a vector<string>.

In C++, a vector 📦 is just a smart, flexible array. A regular array has a strict, fixed size, but a vector can grow automatically as we add more words to it. It is the perfect tool for making a list.

Just like our last problem where we first created an empty string to hold our answer, our very first step here is to create an empty vector to hold our final list of words.

If creating a normal string looks like this:
string myText;

How do you think we would write the code to create a new, empty vector of strings named words?
I fixed it thank you, I did word = ""; but there's another flaw. The letters are only added when ' ' is detected. Meaning the end of the sentence will always be cut out! How do I fix this?!

You spotted the exact bug. 🐞 The loop finishes its job, but that final word is still sitting inside the `word` variable waiting to be added.

Because there is no space at the very end of the string, the loop stops before it can trigger `strArray.push_back(word);` for that final piece.

Think about the order of your code. Once the `for` loop is completely finished looking at every single letter, the computer moves on to the very next line of code below the loop.

What command can we write *right after* the loop closes, but *before* we `return strArray;`, to catch that leftover word and add it to our list?

Let's look at a C++ tool called `stringstream`. Think of it as an automatic word-chopper ⚙️. It finds the spaces and separates the words for you, so you do not have to check each letter one by one.

Here is how we set it up in two easy steps:

1. **Add the tool**: Put `#include <sstream>` at the very top of your file.
2. **Load the machine**: Put your sentence inside the word-chopper ⚙️ like this:
`stringstream chopper(s);`

Once the sentence is inside, we use the extraction arrows (`>>`) to pull out one word at a time. It looks just like getting input from a user with `cin`.

The command `chopper >> word` will automatically grab the first word, stop exactly when it hits a space, and save it into your `word` variable.

If we want to keep grabbing words and putting them into our `strArray` 📦 until the sentence is completely empty, what kind of loop could we use with the condition `chopper >> word` to keep repeating that action?

My logic is so bad I can't think of how could I loop through individual words until the end :(

    Please don't be hard on yourself! Learning how to build these loops is like training a new muscle. It takes a little time to feel natural. 💪

Let's make it super simple.

Think of the command `chopper >> word` as a question that asks the computer: *"Is there another word left to grab?"*

If the answer is **yes**, it grabs the word. If the answer is **no** (because the sentence is completely empty), it automatically stops.

When we want to keep doing something *as long as* a question is true, we use a `while` loop. It looks like this:

```cpp
while (chopper >> word) {
    // We have our word! Now we just need to save it.
}

```

That is the whole loop! It automatically handles all the logic and stops the exact moment it runs out of words.

Inside those curly brackets `{}`, we need to put the newly grabbed `word` into our `strArray` box 📦.

Do you remember the exact command we used in your last code to add the `word` to the end of `strArray`?

Your logic is spot on. You built the word-chopper machine exactly once, and your `while` loop cleanly grabs every single word until the sentence is empty. This is highly optimized and very clean C++ code.

There is just one tiny detail to fix before you paste this into Codewars. Look closely at the very first line of your function compared to the original Codewars template:

**Your line:**
`vector<string> string_to_array(string &s)`

**Original template:**
`vector<string> string_to_array(const string& s)`

You are missing the `const` lock 🔒. Codewars uses strict tests, and it will try to pass "locked" strings into your function. If your function does not promise to keep them locked by using `const`, Codewars will throw a compiler error.

Add that `const` back in, and your code is ready to test.

When you run this exact code on Codewars, it might pass everything, or it might fail exactly *one* tricky hidden test involving a completely empty sentence `""`.

Would you like to test it on Codewars now and let me know if it passes all the tests, or does it give you a red error on one of them?

Codewars test return failed for empty string!

You are incredibly close! Your `if` statement perfectly catches the empty string. 🎯

Let's look exactly at what that Codewars error message is telling us:

* **Actual: `[ ]**` ➡️ This is what your `return {};` gave back. It is a completely empty list with zero items.
* **Expected: `[ "" ]**` ➡️ This is what Codewars wants. It is a list that has *exactly one* item inside it, and that item is an empty string (`""`).

Right now, your curly brackets `{}` are totally empty.

How could you change `return {};` to put an empty string `""` right inside those curly brackets, so it matches exactly what Codewars expects?