#include <vector>
#include <iostream>
using namespace std;

class Solution2
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
    vector<int> nums = {12, 4, 16, 9};
    const int target = 20;

    Solution2 s1;

    vector<int> result = s1.twoSum(nums, target);
    if (result.size() == 2)
    {
        cout << "[" << result[0] << "," << result[1] << "]" << endl;
    }
    else
    {
        cout << "Not Found" << endl;
    }
    return 0;
}
