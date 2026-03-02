#include <iostream>
#include <string>
using namespace std;

int string_to_number(const string &s)
{
    return stoi(s);
}
int main()
{
    string str = "1234";
    string str2 = "605";
    string str3 = "1405";
    string str4 = "-7";
    cout << string_to_number(str) << endl;
    cout << string_to_number(str2) << endl;
    cout << string_to_number(str3) << endl;
    cout << string_to_number(str4) << endl;
}