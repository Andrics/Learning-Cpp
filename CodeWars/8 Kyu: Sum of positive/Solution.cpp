#include <vector>
#include <iostream>
using namespace std;
int positive_sum(const vector<int> &vec)
{
  int sum = 0;
  for (int item : vec)
  {
    if (item > 0)
    {
      sum += item;
    }
  }
  return sum;
}
int main()
{
  vector<int> vec = {1, -4, 7, 12};
  int result = positive_sum(vec);
  cout << result;
}