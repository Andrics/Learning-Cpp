#include <iostream>
using namespace std;

string makeUpper(const string &str)
{
    string result = "";
    for (char letter : str)
    {
        result += toupper(letter);
    }
    return result;
};

int main()
{
    const string str = "ifneOEIF";
    string result = makeUpper(str);
    cout << result;
}