#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

class Solution
{
public:
    int romanToInt(string s)
    {
        unordered_map<char, int> romanMap = {
            {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};
        int result = 0;
        for (int i = 0; i < s.length(); i++)
        {

            if ((i + 1) != s.length() && romanMap[s[i + 1]] > romanMap[s[i]])
            {
                result -= romanMap[s[i]];
            }
            else
            {
                result += romanMap[s[i]];
            }
        }
        return result;
    }
};
int main()
{
    Solution S1;
    string s1 = "III";
    string s2 = "LVIII";
    string s3 = "MCMXCIV";

    int result = S1.romanToInt(s1);
    int result2 = S1.romanToInt(s2);
    int result3 = S1.romanToInt(s3);
    cout << "Results: " << result << endl;
    cout << result2 << endl;
    cout << result3 << endl;
}