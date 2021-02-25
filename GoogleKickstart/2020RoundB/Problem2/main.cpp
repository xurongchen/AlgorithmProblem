#include <bits/stdc++.h>
using namespace std;
#define LL long long

LL X[1005];
void solve(int Case)
{
    int N;
    LL D;
    cin >> N >> D;
    for (int i = 0; i < N; ++i)
    {
        cin >> X[i];
    }

    for (int i = N - 1; i >= 0; --i)
    {
        D = D / X[i] * X[i];
    }
    printf("Case #%d: %lld\n", Case, D);
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