#include <iostream>
using namespace std;

string even_or_odd(int number)
{
    return (number & 1) ? "Odd" : "Even";
}

int main()
{
    int numEven = 12;
    int numOdd = 7;
    string result = even_or_odd(numEven);
    string result2 = even_or_odd(numOdd);
    cout << result << endl;
    cout << result2 << endl;
}