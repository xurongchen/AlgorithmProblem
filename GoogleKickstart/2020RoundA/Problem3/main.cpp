#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define LD long double

LD ESP = 1e-12L;
int A[100005];
bool check(int d, int N, int K)
{
    for (int i = 1; i < N; ++i)
    {
        if(A[i] - A[i - 1] <= d) continue;
        LD cnt = 1.0L * (A[i] - A[i - 1]) / d;
        int delta = (int) ceil(cnt - ESP) - 1;
        // if(delta < 0) delta = 0;
        K -= delta;
        if (K < 0)
            return false;
    }
    return true;
}
void solve(int Case)
{
    int N, K;
    cin >> N >> K;
    int maxDiff = 0;
    for (int i = 0; i < N; ++i)
    {
        cin >> A[i];
        if (i > 0)
            maxDiff = maxDiff > A[i] - A[i - 1] ? maxDiff : A[i] - A[i - 1];
    }
    int L = maxDiff / (K + 1);
    int R = maxDiff;
    while (L < R)
    {
        // cout << "L" << L << "R" << R << endl;
        int M = (L + R) / 2;
        if (!check(M, N, K))
        {
            L = M + 1;
        }
        else
        {
            R = M;
        }
    }

    printf("Case #%d: %d\n", Case, L);
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