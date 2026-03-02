#include <iostream>
#include <math.h>
using namespace std;

class Solution
{
public:
    bool isPalindrome(int x)
    {
        int remainder = 0;
        long long reversedNum = 0;
        int originalNum = x;
        if (x < 0)
        {
            return false;
        }
        if (x == 0)
        {
            return true;
        }
        if (x % 10 == 0)
        {
            return false;
        }
        while (x > 0)
        {
            remainder = x % 10;
            x = x / 10;
            reversedNum = (reversedNum * 10) + remainder;
        }
        return reversedNum == originalNum;
    }
};

int main()
{
    int x = 12321;
    Solution s1;
    bool result = s1.isPalindrome(x);
    if (result == true)
    {
        cout << "It is a Palindrome" << endl;
    }
    else
    {
        cout << "Not a Palindrome" << endl;
    }
}