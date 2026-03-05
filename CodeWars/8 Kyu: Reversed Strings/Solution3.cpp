#include <iostream>
#include <string>
using namespace std;

string reverseString(const string &str)
{
    int right = str.size() - 1;
    int i = 0;
    string toReverse = str;
    while (i < right)
    {
        swap(toReverse[i], toReverse[right]);
        i++;
        right--;
    }
    return toReverse;
}
int main()
{
    string str = "Hello Meow";
    string result = reverseString(str);
    cout << result << endl;
}