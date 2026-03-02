#include <iostream>
using namespace std;

class Solution
{
public:
    int romanValue(char c)
    {
        switch (c)
        {
        case 'I':
            return 1;
        case 'V':
            return 5;
        case 'X':
            return 10;
        case 'L':
            return 50;
        case 'C':
            return 100;
        case 'D':
            return 500;
        case 'M':
            return 1000;
        default:
            return 0;
        }
    }
    int romanToInt(string s)
    {
        int result = 0;
        for (int i = 0; i < s.length(); i++)
        {
            if ((i + 1) != s.length() && romanValue(s[i + 1]) > romanValue(s[i]))
            {
                result -= romanValue(s[i]);
            }
            else
            {
                result += romanValue(s[i]);
            }
        }
        return result;
    }
};

/*int main()
{
    Solution S1;
    string s1 = "III";
    string s2 = "LVIII";
    string s3 = "MCMXCIV";

    int result = S1.romanToInt(s1);
    int result2 = S1.romanToInt(s2);
    int result3 = S1.romanToInt(s3);
    cout << result << endl;
    cout << result2 << endl;
    cout << result3 << endl;
    return 0;
}*/