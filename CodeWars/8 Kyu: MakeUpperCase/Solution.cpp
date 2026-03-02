#include <string>
#include <iostream>
using namespace std;

string makeUpperCase(const string &str)
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
    string str = "exAmplE";
    string result = makeUpperCase(str);
    cout << result;
    return 0;
}