#include <iostream>
#include <sstream>
#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
    vector<string> string_to_array(const string &s)
    {
        if (s == "")
        {
            return {""};
        }
        string word = "";
        vector<string> result = {};
        stringstream chopper(s);
        while (chopper >> word)
        {
            result.push_back(word);
        }
        return result;
    }
};

int main()
{
    string str = "This is an example sentence";
    Solution s1;
    vector<string> result = s1.string_to_array(str);
    for (string items : result)
    {
        cout << items + " ";
    }
}