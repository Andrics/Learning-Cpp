#include <iostream>
#include <math.h>
using namespace std;

class Solution2
{
public:
    bool isPalindrome(int x)
    {
        int remainder = 0;
        long long reversedNum = 0;
        int originalNum = x;

        if (x == 0)
        {
            return true;
        }
        if (x < 0)
        {
            return false;
        }
        if (x % 10 == 0)
        {
            return false;
        }
        while (x > 0)
        {
            remainder = x % 10;
            x /= 10;
            reversedNum = (reversedNum * 10) + remainder;
        }
        return reversedNum == originalNum;
    }
};

int main()
{
    Solution2 s1;
    int x = 0;
    int j = -1;
    int k = 10;
    int l = 123;
    int m = 12321;

    bool result = s1.isPalindrome(x);
    bool result1 = s1.isPalindrome(j);
    bool result2 = s1.isPalindrome(k);
    bool result3 = s1.isPalindrome(l);
    bool result4 = s1.isPalindrome(m);

    cout << result << endl;
    cout << result1 << endl;
    cout << result2 << endl;
    cout << result3 << endl;
    cout << result4 << endl;
}