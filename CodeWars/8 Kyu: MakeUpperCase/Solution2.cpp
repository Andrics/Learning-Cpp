#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    string makeUpper2(const string &str)
    {
        string result = str;
        transform(result.begin(), result.end(), result.begin(), ::toupper);
        return result;
    }
};

int main()
{
    string str = "eXaMple";
    Solution s1;
    string result = s1.makeUpper2(str);
    cout << result;
    return 0;
}