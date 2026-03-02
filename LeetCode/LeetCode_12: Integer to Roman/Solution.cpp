#include <iostream>
using namespace std;

class Solution
{
public:
    string intToRoman(int num)
    {
        string result = "";
        int values[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        string symbols[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        for (int i = 0; i < 13; i++)
        {
            while (num >= values[i])
            {
                result += symbols[i];
                num -= values[i];
            }
        }
        return result;
    }
};

/*int main()
{
    Solution S1;
    int num = 3749;
    int num2 = 58;
    int num3 = 1994;
    string result = S1.intToRoman(num);
    string result2 = S1.intToRoman(num2);
    string result3 = S1.intToRoman(num3);
    cout << result << endl;
    cout << result2 << endl;
    cout << result3 << endl;
}*/