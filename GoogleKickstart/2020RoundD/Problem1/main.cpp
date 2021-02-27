#include <bits/stdc++.h>
using namespace std;
#define LL long long

int A[200005];
void solve(int Case)
{
    int N;
    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        cin >> A[i];
    }

    int Curmax = -1;
    int Cnt = 0;
    for (int i = 0; i < N; ++i)
    {
        if (A[i] > Curmax && (i == N - 1 || A[i] > A[i + 1]))
            Cnt++;
        if (A[i] > Curmax)
            Curmax = A[i];
    }
    printf("Case #%d: %d\n", Case, Cnt);
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