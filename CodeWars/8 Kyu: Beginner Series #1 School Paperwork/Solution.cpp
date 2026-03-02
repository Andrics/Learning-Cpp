#include <iostream>
using namespace std;

int paperwork(int n, int m)
{
    return (n > 0 && m > 0) ? n * m : 0;
};

int main()
{
    int n = 5, m = 5;
    cout << paperwork(n, m);
}