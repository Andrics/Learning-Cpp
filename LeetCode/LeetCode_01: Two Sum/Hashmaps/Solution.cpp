#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        unordered_map<int, int> myMap;
        for (int i = 0; i < nums.size(); i++)
        {
            int currentNum = nums[i];
            int findNum = target - currentNum;
            if (myMap.find(findNum) != myMap.end())
            {
                return {myMap[findNum], i};
            }
            myMap[currentNum] = i;
        }
        return {};
    }
};

int main()
{
    vector<int> nums = {2, 4, 8, 7};
    int target = 9;
    Solution s1;
    vector<int> result = s1.twoSum(nums, target);
    if (result.size() == 2)
    {
        cout << "[" << result[0] << "," << result[1] << "]" << endl;
    }
    else
    {
        cout << "Not Found" << endl;
    }
}
