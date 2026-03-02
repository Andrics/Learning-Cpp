#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = i + 1; j < nums.size(); j++)
            {
                if (nums[i] + nums[j] == target)
                {
                    return {i, j};
                }
            }
        }
        return {};
    }
};

int main()
{
    vector<int> nums = {2, 5, 8, 7};
    int target = 9;
    Solution s1;
    vector<int> result = s1.twoSum(nums, target);
    if (result.size() == 2)
        cout << "[" << result[0] << "," << result[1] << "]" << endl;
    else
        cout << "Not Found" << endl;
}