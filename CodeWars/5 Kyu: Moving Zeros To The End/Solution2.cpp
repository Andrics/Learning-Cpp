#include <iostream>
#include <vector>
using namespace std;

vector<int> move_zeroes(const vector<int> &nums)
{
    vector<int> result = nums;
    int insertIndex = 0;
    for (size_t i = 0; i < result.size(); i++)
    {
        if (result[i] != 0)
        {
            swap(result[insertIndex], result[i]);
            insertIndex++;
        }
    }
    return result;
}
int main()
{
    vector<int> nums = {1, 0, 1, 2, 0, 1, 3};
    vector<int> result = move_zeroes(nums);
    for (int numbers : result)
    {
        cout << numbers << " ";
    }
}