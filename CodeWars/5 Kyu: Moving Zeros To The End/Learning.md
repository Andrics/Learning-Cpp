Write an algorithm that takes an array and moves all of the zeros to the end, preserving the order of the other elements.

move_zeros({1, 0, 1, 2, 0, 1, 3}) // returns {1, 1, 2, 1, 3, 0, 0}

Gemini today I've taken a challenge!! a 5kyu question from codewars in c++!!!
I gave it a shot but I'm hitting a problem, when I submit my code the terminal screen is just blank  :(
Write an algorithm that takes an array and moves all of the zeros to the end, preserving the order of the other elements.
move_zeros({1, 0, 1, 2, 0, 1, 3}) // returns {1, 1, 2, 1, 3, 0, 0}
#include <vector>

std::vector<int> move_zeroes(const std::vector<int>& input) {
  // your code here
}

This is what I did:
#include <iostream>
#include <vector>
using namespace std;

vector<int> removeZero(vector<int> &nums)
{
    for (int i = 0; i < nums.size(); i++)
    {
        if (i + 1 == nums.size())
            break;
        if (nums[i] == 0)
        {
            nums.push_back(0);
            nums.erase(nums.begin() + i);
            i--;
        }
    }
    return nums;
}

int main()
{
    vector<int> nums = {1, 0, 1, 2, 0, 1, 3};
    vector<int> result = removeZero(nums);
    for (int numbers : result)
    {
        cout << numbers << " ";
    }
}

Please guide me, what went wrong?

A 5kyu challenge! That is a huge step up for a beginner, so props to you for taking that on. 🚀

The reason your screen is going blank (or likely getting stuck in an infinite loop) is because of how you're handling the zeros. Let's break down the logic together. I'll ask some questions to help us fix the "loop of doom." ♾️

### The Logic Trap 🪤

In your code, every time you find a `0`, you do two things:

1. `nums.push_back(0)` (Add a zero to the very end).
2. `nums.erase(...)` (Remove the zero from the current spot).

Think about what happens to the size of your `vector` when you do both of those in one go. If you start with 7 elements and you add one then remove one, how many elements do you have now?

And here is the kicker: If you keep adding a new `0` to the end, and your loop is designed to keep going until it reaches the "end" of the vector, will it ever actually finish if the vector keeps growing or staying the same size while moving zeros?

### A Different Strategy 💡

Instead of moving elements around inside the original vector (which is actually quite "expensive" for the computer to do), what if we just built a **new** result vector from scratch?

Let's try to visualize this:

1. **Step 1:** Create an empty vector called `result`.
2. **Step 2:** Look at every number in the original list. If it is **not** a zero, what should we do with it in our `result` vector? 📥
3. **Step 3:** After checking all numbers, if our `result` vector is shorter than the original, what does that tell us about the missing numbers?

How would you write a simple `for` loop to just grab the non-zero numbers first?

Here is my new version!!
#include <iostream>
#include <vector>
using namespace std;

vector<int> removeZero(vector<int> &nums)
{
    vector<int> result;
    int zeroes = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] != 0)
        {
            result.push_back(nums[i]);
        }
        else
        {
            zeroes++;
        }
    }
    while (zeroes > 0)
    {
        result.push_back(0);
        zeroes--;
    }
    return result;
}
int main()
{
    vector<int> nums = {1, 0, 1, 2, 0, 1, 3};
    vector<int> result = removeZero(nums);
    for (int numbers : result)
    {
        cout << numbers << " ";
    }
}

Alright I want to ask, is there a better way of doing this? a best industry practice or some library, anything that yields less time complexity and memory usage.

Moving from "it works" to "it's fast and uses less memory" is the exact right mindset for interviews and industry code.

Your current solution runs in **O(N)** time (it only goes through the numbers once), which is as fast as it gets! But, it uses extra memory because you created a whole new `result` vector. We call that **O(N)** space.

In the industry, the best practice is to do this **in-place**. That means modifying the original vector without creating any new ones, giving us **O(1)** space complexity.

### The "Two-Pointer" Strat ✌️

There is a goated built-in C++ library function for this (which we can talk about later), but writing the logic yourself first is the best way to level up.

To do this in-place, we use two "pointers" (just regular variables keeping track of index numbers) inside the same vector.

1. One pointer is your regular `i` loop going through every number.
2. The second pointer, let's call it `insertIndex`, stays behind and only moves when it finds a good spot for a non-zero number.

Imagine `insertIndex` starts at `0`. We loop through the array with `i`. Every time `nums[i]` is *not* zero, we copy that number to `nums[insertIndex]`, and then add `1` to `insertIndex`.

Let's test this logic. If our array is `{5, 0, 2}`:

* We look at `5`. It's not zero, so we put it at `insertIndex` (which is `0`). `insertIndex` becomes `1`.
* We look at `0`. It's zero, so we do nothing. `insertIndex` is still `1`.
* We look at `2`.

Based on this pattern, what exactly happens with the `2` and the `insertIndex` on that last step?

Me no comprehendo

No sweat at all! Two-pointer logic is totally a mind-bender the first time you see it. Let's ditch the coding jargon and look at it like a real-world task.

Imagine you and your friend are organizing a row of boxes on the floor. Some boxes have cool stuff (numbers), and some are empty (zeros).

* **You (`i`)**: Your job is to walk down the line and look inside *every single box*.
* **Your friend (`insertIndex`)**: Their job is to just stand at the *next available spot* to pack a cool item.

Let's look at our mini array: `{5, 0, 2}`

**Step 1:** You both start at the first spot (index 0).

* You look inside and see a `5`. It's a cool item!
* You tell your friend, "Pack this!" Your friend puts the `5` in their current spot (index 0), and then takes one step forward to wait at index 1.

**Step 2:** You move to the next box (index 1).

* You see a `0` (empty box).
* You just ignore it and keep walking. Your friend *stays* at index 1, still waiting patiently for you to find another cool item.

**Step 3:** You move to the last box (index 2).

* You see a `2`. It's a cool item!

Right now, your friend is still standing at index 1, holding that spot open. If you hand them the `2` to pack into their spot, what will the row of boxes look like now?

5,2,0. So are we using the swap function here?


Spot on! You nailed the final result: `{5, 2, 0}`.

And you just pointed out the absolute best way to solve this. Using `swap` is a massive brain play here! 🧠

If we just *copied* the number (like my original hint), the array would temporarily look like `{5, 2, 2}`, and we'd have to write a whole second loop to turn that last `2` into a `0`.

But by **swapping** the boxes instead of copying them, you do two things at once:

1. You put the cool item (`2`) exactly where your friend is waiting (`insertIndex`).
2. You automatically throw the empty box (the `0`) further down the line!

This means you only need *one* loop to solve the whole problem.

Since you've got the logic down perfectly, how would you write that `if` statement inside your `for` loop using C++'s built-in `swap(a, b)` function?


  for (int i = 1; i < nums.size(); i++)
    {
        if (i + 1 != nums.size() && nums[i - 1] == 0)
        {
            swap(nums[insertIndex], nums[i]);
            insertIndex++;
        }
    }

Here's my attempt, also what if i - 1 and i both are 0, wouldn't that turn into an endless loop?

First off, to answer your question: **No, it won't turn into an endless loop!** 🛑

Endless loops usually happen when the finish line keeps moving (like when you were using `push_back` to add new numbers in your first attempt). Here, your `for` loop rigidly counts `i` up to `nums.size()`. Whatever numbers are actually *inside* the array won't stop `i` from ticking forward.

But looking at your code, I think you are overcooking the logic a little bit! 🍳 You're looking backward (`i - 1`) and worrying about the end of the array (`i + 1 != nums.size()`).

Let's bring it back to the box analogy. It is actually way simpler.

### Keep It Simple 📦

Remember your job: You walk down the line and look inside the **current** box. You don't need to look at the box behind you, and you don't need to worry about the box ahead of you.

* **Your loop:** You start at the very first box: `for (int i = 0; i < nums.size(); i++)`
* **Your check:** You just look at the item right in front of you (`nums[i]`). Is it a cool item (not a zero), or is it empty (a zero)?

If you are standing at index `i`, how would you write a super simple `if` statement to check if your **current** box is NOT zero?

if (nums[i]!=0){}

Exactly! That is the perfect check. 🎯

If `nums[i] != 0`, we want to move that "cool item" to the spot our friend (`insertIndex`) is holding open.

Since we decided to use **`swap`**, we don't need to worry about the zeros manually. Swapping the non-zero element with the element at `insertIndex` will naturally push the zeros toward the back as `i` moves forward.

Here is how the logic looks in your head:

1. **Loop** through every element using `i`.
2. **If** `nums[i]` is not zero:
* **Swap** `nums[i]` with `nums[insertIndex]`.
* **Move** `insertIndex` forward by one (since that spot is now "filled").



Let's try to mental-trace this with a tricky example: `{0, 1, 0, 3}`.

* **Start:** `i = 0`, `insertIndex = 0`. `nums[0]` is `0`. (Do nothing).
* **Next:** `i = 1`, `insertIndex = 0`. `nums[1]` is `1`. This is **not** zero!

If we swap `nums[i]` and `nums[insertIndex]` right now, what does the array look like, and where does `insertIndex` move to?

the array will look like {1,0,0,3} and insertIndex will move to 1
This is hurting my brain

It is totally normal for this to feel like a brain-melter! 🧠 You are basically trying to track two different moving parts in your head at once.

You are 100% right about `insertIndex` moving to **1**. But let's look at the array again. If we **swap** the `0` at index 0 with the `1` at index 1:

1. The `1` moves to the front (where the friend was waiting).
2. The `0` moves to where the `1` used to be.

So the array actually becomes `{1, 0, 0, 3}`.

The magic happens in the **next** step. Right now, your friend (`insertIndex`) is standing at index **1** (the first zero). You (`i`) move to index **2**.

* At index 2, you see a `0`. You ignore it.
* At index 3, you see a `3`. It is not a zero!

If you swap the `3` (at index 3) with whatever your friend is holding at `insertIndex` (index 1), what does the array look like now?

damn im kinda dumb

You aren't being "dumb" at all—this is a classic "Aha!" moment in computer science! 💡 Two-pointer logic is a completely new way of thinking. It feels weird because you're essentially rubbing your head and patting your stomach at the same time by tracking two different positions.

Let's look at that result: **{1, 3, 0, 0}**.
By swapping the **3** with the **0** that was at `insertIndex`, the **3** jumped to the front and the **0** got kicked to the back. It’s super efficient because you’re doing the sorting as you walk. 🏃‍♂️

Now that you've got the mental map, let's look at the actual C++ code for this. If you were to write this into a function, where should you declare that `insertIndex` variable so it stays "alive" and keeps track of its spot throughout the whole loop? 📍

outside of the loop

Exactly! You want to declare `insertIndex` **outside** (before) the loop. This way, it doesn't get reset to 0 every time the loop runs. It stays at its current position, waiting for the next non-zero number you find. 📍

Here is how the structure looks so far:

```cpp
int insertIndex = 0; 
for (int i = 0; i < nums.size(); i++) {
    // If nums[i] is not 0...
    // Swap and move insertIndex
}

```

This approach is super clean. It’s **O(N)** time because we only pass through the array once, and **O(1)** extra space because we’re just reusing the memory we already have. No extra vectors needed! 🚫📑

Since this is for a **Codewars** challenge, they usually want you to return the vector at the end. In our "swap" version, do we need to return a new vector, or can we just return the original `nums` that we've been modifying?


we can just return nums;

You've got it! 🎯 Since we modified the `nums` vector directly using `swap`, it now contains the exact arrangement we want. Returning it is the final step.

This "in-place" approach is a huge win in C++. By avoiding a second vector, you kept the **Space Complexity** at $O(1)$ (constant extra space), which is the "Gold Standard" in technical interviews.

### Let's Put It All Together 🛠️

Now that you've mastered the logic, let's look at the full function structure. Remember that Codewars expects a specific function name and a `const` parameter.

Since the input is `const` (meaning we aren't allowed to change it), but we want to use our "in-place" swap trick, we can simply make a copy of the input at the start of the function and work on that copy.

Here is the "skeleton" based on your logic:

```cpp
#include <vector>
#include <algorithm> // for std::swap

std::vector<int> move_zeroes(const std::vector<int>& input) {
    // 1. Create a copy of 'input' called 'nums' so we can modify it
    // 2. Initialize your insertIndex
    // 3. Run your for-loop with the swap logic
    // 4. Return your modified 'nums'
}

```

Does that structure make sense for passing the challenge? If you're ready, try writing out the final version of the code inside that `move_zeroes` function! 💻

#include <iostream>
#include <vector>
using namespace std;

vector<int> move_zeroes(const vector<int> &nums)
{
  vector<int> result = nums;
    int insertIndex = 0;
    for (int i = 0; i < result.size(); i++)
    {
        if (result[i] != 0)
        {
            swap(result[insertIndex], result[i]);
            insertIndex++;
        }
    }
    return result;
}

This is what I did, but the codewars tester returned a warning along with all the tests passed which is
STDERR
In file included from main.cpp:6:
./solution.cpp:9:23: warning: comparison of integers of different signs: 'int' and 'std::vector::size_type' (aka 'unsigned long') [-Wsign-compare]
    for (int i = 0; i < result.size(); i++)
                    ~ ^ ~~~~~~~~~~~~~
1 warning generated.

Ayy, look at you passing all the tests! 🥳 That is a massive "dub" (win) for your first 5kyu challenge. You successfully turned that "blank screen" into a working, high-performance algorithm.

The warning you're seeing isn't a "fail," it's just the C++ compiler being a bit of a "try-hard" about safety. 🤓

### The "Sign" Problem 🪧

The error says you're comparing a `signed` integer with an `unsigned` integer.

* **`int i`**: This is a **signed** integer. It can be positive or negative (like -1, 0, 1). ➕/➖
* **`result.size()`**: This returns a `size_type` (usually `unsigned long`). It **cannot** be negative because a list can't have "-5" items in it. 🚫➖

In C++, if you compare a signed number to a very large unsigned number, things can occasionally go "glitch mode" because of how the computer stores bits. The compiler is just looking out for you!

### How to Fix It 🛠️

To make the warning vanish, you just need to make both sides "match." The standard "best practice" in C++ is to use `size_t` for loop counters when dealing with vectors. `size_t` is a special type that is guaranteed to be big enough to hold the size of any object.

Look at your loop header:
`for (int i = 0; i < result.size(); i++)`

If you change `int i` to `size_t i`, the types will match perfectly, and the compiler will stop complaining. 🤫

Since you also used `int insertIndex` outside the loop, do you think you should change that one to `size_t` as well? Why or why not?

I just saw the best practices and someone did: 
auto move_zeroes(std::vector<int> v) {
  stable_partition(begin(v), end(v), std::negate());
  return v;
}
This is so cool! I want to learn like this too!!!

That is exactly the kind of "C++ Magic" that makes the language so powerful! 🪄 You’ve just discovered how the **Standard Template Library (STL)** can turn a 10-line loop into a single, highly optimized line of code.

To understand how this works, we need to break down two main concepts: **Iterators** and the **Partition** logic.

### 1. Iterators: The Navigation System 🧭

In your manual code, you used `i` to point at positions. In the STL, we use `begin(v)` and `end(v)`.

* `begin(v)` points to the very first element.
* `end(v)` points to the "ghost" space right *after* the last element.
These tell the algorithm exactly where to start and stop working.

### 2. The Partition Logic ↔️

The word **partition** means to divide something into two groups based on a rule.

* **`std::partition`**: Moves everything that fits a rule to the front, and everything else to the back.
* **`std::stable_partition`**: Does the same thing, but it's "stable," meaning it **preserves the original order** of the elements (exactly what your Codewars challenge required!).

### 3. The Rule (The Predicate) ⚖️

The third part of the function, `std::negate()`, is the "rule" or "filter."
In C++, numbers are treated like Booleans: `0` is `false`, and any other number is `true`.

The `std::negate<int>()` function (often shortened to `std::negate()` in modern C++) basically flips that logic.

**Let's test your intuition:**
If `std::partition` moves everything that is "True" to the front, and `std::negate` flips the values...

1. If we have a `5` (which is normally `true`), what does `negate` turn it into?
2. If we have a `0` (which is normally `false`), what does `negate` turn it into?

Please start with what is an STL

Let's dive into the **STL**! It’s basically the "utility belt" for C++ developers. 🛠️

**STL** stands for **Standard Template Library**. It is a massive collection of ready-made code that comes built-in with C++. Instead of writing everything from scratch (like sorting a list or building a custom array), you can just grab a tool from the STL.

It’s built on three main pillars:

1. **Containers:** These are objects that store data, like `std::vector` (which you used!), `std::list`, or `std::set`. 📦
2. **Algorithms:** These are functions that perform tasks on the data, like `std::sort`, `std::find`, or `std::stable_partition`. ⚙️
3. **Iterators:** These act like "glue" or pointers that help the algorithms talk to the containers. 🔗

The reason it's so powerful is that these tools are **highly optimized**. The smartest engineers in the world wrote them to be as fast as possible, so using them usually makes your code better and faster than if you wrote it by hand. 🚀

I'll be guiding you through how this works with some questions. To start, since you saw `std::stable_partition` in that "best practice" code, does the word **"partition"** remind you of how you might organize a physical collection of items into two groups?

english isnt my first language, but the only reference of partition I know is when I was partitioning disks in my pc with a certain space provided to each disk.

That is actually a perfect analogy! 💿 When you partition a disk, you’re taking one big space and dividing it into separate, defined sections (like C: drive and D: drive).

In C++, the **STL (Standard Template Library)** `partition` does something very similar with a `vector`. It takes your "disk" (the vector) and reorganizes it into two sections based on a rule:

1. **Section A:** Elements that follow the rule.
2. **Section B:** Elements that don't.

### What is the STL? 🧰

Think of the **STL** as a giant library of "pre-built functions." Instead of building a car from scratch every time, you go to the STL and grab a pre-made engine (Algorithms), a fuel tank (Containers), and a dashboard (Iterators).

* **Containers (`vector`):** The "boxes" where you store data.
* **Algorithms (`stable_partition`):** The "robots" that do work on those boxes (sorting, searching, moving).
* **Iterators (`begin`, `end`):** The "fingers" that point to exactly which box the robot should start and stop at.

### Why use `stable_partition`? ⚖️

In your Codewars challenge, you had to move zeros to the end *while keeping the other numbers in their original order*.

* **`partition`**: Moves items to the front/back, but might scramble the order of the "cool" numbers. 🌪️
* **`stable_partition`**: Moves items but keeps their relative order exactly the same. It’s "stable" just like a steady hand. 🤝

The "rule" used in the code you saw was `std::negate()`. In C++, a `0` is mathematically seen as `false`, and any other number is `true`. `negate` flips that logic to help the algorithm decide who goes to the "Front Partition" and who goes to the "Back Partition."

To see if this makes sense: If we have the list `{0, 7, 0, 3}` and we want to "partition" it so non-zeros are at the front, how many "sections" or partitions is the robot creating in that list?


That's a very fair point—honestly, in that specific CodeWars solution, using `std::negate` is actually a bit of a "hack." It works because of a specific quirk in how C++ handles numbers and logic. 🧠

Here is the "why" behind their choice:

1. **The "Robot's" Default:** `stable_partition` usually puts things that are `true` (non-zero) at the **front** and `false` (zero) at the **back**.
2. **The Goal:** Our goal is exactly that: Non-zeros at the front, Zeros at the back.
3. **The Twist:** `std::negate<int>()` is a function that usually just turns `x` into `-x`. But when the "Robot" uses it as a rule, it forces the robot to look at the numbers in a way where it treats the **zeros** as the special case it needs to move.

Actually, using `std::negate` here is widely considered **bad practice** because it’s confusing! Most professional developers would find it "unreadable." The only reason it shows up in "Best Practices" on sites like CodeWars is often because people like to show off how they can solve a problem with the shortest amount of characters possible (we call this "Code Golf"). ⛳

Since you’re learning to write clean, industry-standard code, using a **Lambda** (the `[]` thing) is 100x better because it actually explains what it's doing.

Let's look at the Lambda again: `[](int n) { return n != 0; }`

If we put this into the "Robot" (`stable_partition`), it asks: "Is this number NOT zero?"

* If **Yes** (True): Move to the front.
* If **No** (False): Move to the back.

Does that make the logic feel a bit more "human" compared to the `negate` version?

but negate thing looks so cool and clever!! please tell me how to do it that way too!! pwease..

It definitely has that "secret code" vibe! If you want to master those "clever" one-liners, we have to look at how C++ handles **logical truth**.

In C++, any number that is **not zero** is considered `true`, and `0` is considered `false`.

### The Logic Flip 🔄

The `std::stable_partition` algorithm works by putting everything that returns `true` at the front.

* **Normal behavior:** Non-zeros (true) go to the front, zeros (false) go to the back.
* **The "Clever" Trick:** By using `std::negate<int>()`, the programmer is essentially transforming the input.

In this context, `std::negate` is used as a **predicate** (a test). For the algorithm to work this way, it relies on the fact that for any non-zero integer $n$, $-n$ is also non-zero (still `true`).

### Why it works in that specific solution

In modern C++ (specifically C++20 and later), `std::negate` can be used in "Ranges." When you pass a value to `std::negate`, it returns the negative of that value.

1. If the value is `5`, it becomes `-5` (which is still "True" to the robot).
2. If the value is `0`, it becomes `-0`, which is still `0` (which is "False" to the robot).

The person who wrote that was using a very advanced (and slightly "hacky") way to tell the robot: "Evaluate the negative of this number. If that result is 'True' (not zero), put it at the front."

### Let's try to "think" like the STL

If we wanted to use a built-in tool instead of a manual loop, we need to pick the right **Algorithm**.

We have two main choices for "rearranging" data:

1. **`std::partition`**: Fast, but might scramble the order of the numbers. 🌪️
2. **`std::stable_partition`**: A bit slower, but keeps the numbers in their original order. 🤝

Since the Codewars challenge asks us to **preserve the order** of the non-zero elements, which of those two tools do you think is the "correct" one to use?