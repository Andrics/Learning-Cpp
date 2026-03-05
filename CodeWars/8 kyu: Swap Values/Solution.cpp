#include <utility>
using namespace std;
pair<int, int> swap_values(pair<int, int> values)
{
    swap(values.first, values.second);
    return values;
}