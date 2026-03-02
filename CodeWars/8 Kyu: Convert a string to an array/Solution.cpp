#include <vector>
#include <string>
#include <iostream>
using namespace std;

vector<string> string_to_array(const string &s)
{
    vector<string> strArray = {};
    string word = "";
    for (char letter : s)
    {
        if (letter == ' ')
        {
            strArray.push_back(word);
            word = "";
        }
        else
        {
            word += letter;
        }
    }
    strArray.push_back(word);
    return strArray;
};
int main()
{
    string str = "I am andr1cs";
    vector<string> result = string_to_array(str);
    for (string items : result)
    {
        cout << items << endl;
    }
    return 0;
}