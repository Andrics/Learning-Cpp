#include <iostream>
#include <string>
using namespace std;

class Solution
{
public:
    string reversed_string(const string &str)
    {
        string reversedString = "";
        for (int i = str.size() - 1; i >= 0; i--)
        {
            reversedString += str[i];
        }
        return reversedString;
    }
};
int main()
{
    Solution S1;
    string str = "Example";
    string result = S1.reversed_string(str);
    cout << result;
    return 0;
}