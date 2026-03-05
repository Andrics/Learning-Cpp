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