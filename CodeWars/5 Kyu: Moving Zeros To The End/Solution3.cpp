#include <iostream>
#include <algorithm>
using namespace std;

auto move_zeroes(const vector<int> &nums)
{
    vector<int> result = nums;
    stable_partition(begin(result), end(result), negate());
    return result;
}
int main()
{
    vector<int> nums = {1, 2, 0, 4, 5, 0, 3};
    vector<int> result = move_zeroes(nums);
    for (int numbers : result)
    {
        cout << numbers << " ";
    }
}