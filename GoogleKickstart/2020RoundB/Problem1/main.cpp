#include <bits/stdc++.h>
using namespace std;
#define LL long long

int A[105];
void solve(int Case)
{
    int N;
    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        cin >> A[i];
    }
    int Sum = 0;
    for (int i = 1; i < N - 1; ++i)
    {
        if (A[i] > A[i - 1] && A[i] > A[i + 1])
            Sum += 1;
    }
    printf("Case #%d: %d\n", Case, Sum);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    for (int i = 0; i < T; ++i)
    {
        solve(i + 1);
    }
}