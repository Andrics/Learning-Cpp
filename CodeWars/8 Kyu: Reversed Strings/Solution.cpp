#include <iostream>
#include <string>
using namespace std;

string reverseString(const string &str)
{
    int stringSize = str.size() - 1;
    string reversedString = "";
    char letter;

    while (stringSize >= 0)
    {
        letter = str[stringSize];
        reversedString += letter;
        stringSize--;
    }
    return reversedString;
}

int main()
{
    string str = "Hello Meow";
    string result = reverseString(str);
    cout << result << endl;
}