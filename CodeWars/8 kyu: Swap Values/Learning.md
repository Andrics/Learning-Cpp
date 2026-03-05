I would like to be able to pass an array with two elements to my swapValues function to swap the values. However it appears that the values aren't changing.

Can you figure out what's wrong here?

#include <utility>

std::pair<int, int> swap_values(std::pair<int, int> values) {
  values.first = values.second;
  values.second = values.first;
}

What is & used for? Saving memory?

You're actually spot on! It *does* save memory, but it also completely changes how the function interacts with your data.

Here is the difference between the two:

* **Without `&` (Pass by Value):** This is like printing a physical copy of an essay and giving it to a friend. If they scribble all over their copy, your original file stays exactly the same. The computer also has to spend extra memory creating that brand-new copy.
* **With `&` (Pass by Reference):** Adding the `&` is like sharing an edit link to a Google Doc 📝. You aren't making a new copy (which saves memory!). Instead, you're giving the function direct access to the *original* data. If the function swaps the values, the original values are actually swapped.

So, if we change the parameter to `pair<int, int>& values`, we are directly editing the original pair that got passed in.

Because we are editing the original directly, we don't need to `return` anything at all at the end of the function. If a function doesn't return any data, what keyword do we put a void at the very start. But because of the testcases you don't need to do all that! Your code already works.