#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string reverseString(const string &str)
{
    return string(str.rbegin(), str.rend());
}

int main()
{
    string str = "Hello Meow";
    string result = reverseString(str);
    cout << result << endl;
}