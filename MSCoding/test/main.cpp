#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> &A)
{
    // write your code in C++14 (g++ 6.2.0)
    sort(A.begin(), A.end());
    int i = 0;
    while (i < A.size() && A[i] <= 0)
        ++i;
    int target = 1;
    while (i < A.size())
    {
        if (A[i] > target)
            break;
        else if (A[i] == target)
            target++;
        ++i;
    }
    return target;
}
