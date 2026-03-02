#include <stdlib.h>
#include <iostream>
using namespace std;

class Solution
{
public:
    int makeNegative(int num)
    {
        return -abs(num);
    }
};

int main()
{
    Solution s1;
    int num = 15;
    int num1 = -25;
    int num2 = 0;
    int result = s1.makeNegative(num);
    int result2 = s1.makeNegative(num1);
    int result3 = s1.makeNegative(num2);
    cout << result << endl;
    cout << result2 << endl;
    cout << result3 << endl;
}