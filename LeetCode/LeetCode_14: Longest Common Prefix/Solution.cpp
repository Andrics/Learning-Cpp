#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        string prefix = strs[0];
        for (int i = 1; i < strs.size(); i++)
        {
            while (prefix != "" && strs[i].find(prefix) != 0)
            {
                prefix.pop_back();
            }
            if (prefix == "")
            {
                break;
            }
        }
        return prefix;
    }
};
int main()
{
    vector<string> strs = {"flower", "flow", "flight"};
    vector<string> strs2 = {"racecar", "car", "dog"};
    Solution S1;

    string result = S1.longestCommonPrefix(strs);
    string result2 = S1.longestCommonPrefix(strs2);
    cout << result << endl;
    cout << result2 << endl;
}