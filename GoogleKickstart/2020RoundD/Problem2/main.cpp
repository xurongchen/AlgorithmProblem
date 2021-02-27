#include <bits/stdc++.h>
using namespace std;
#define LL long long

int A[10005];
int DP[10005][4];
void solve(int Case)
{
    int K;
    cin >> K;
    for (int i = 0; i < K; ++i)
    {
        cin >> A[i];
    }
    for (int i = 0; i < 4; ++i)
        DP[0][i] = 0;

    for (int i = 1; i < K; ++i)
    {
        for (int j = 0; j < 4; ++j)
        {
            if (A[i] > A[i - 1])
            {
                DP[i][j] = DP[i - 1][3] + 1;
                for (int k = 0; k < j; ++k)
                {
                    if (DP[i - 1][k] < DP[i][j])
                        DP[i][j] = DP[i - 1][k];
                }
                for (int k = j; k < 4; ++k)
                {
                    if (DP[i - 1][k] + 1 < DP[i][j])
                        DP[i][j] = DP[i - 1][k] + 1;
                }
            }
            else if (A[i] < A[i - 1])
            {
                DP[i][j] = DP[i - 1][0] + 1;
                for (int k = 0; k <= j; ++k)
                {
                    if (DP[i - 1][k] + 1 < DP[i][j])
                        DP[i][j] = DP[i - 1][k] + 1;
                }
                for (int k = j + 1; k < 4; ++k)
                {
                    if (DP[i - 1][k] < DP[i][j])
                        DP[i][j] = DP[i - 1][k];
                }
            }
            else
            {
                DP[i][j] = DP[i - 1][j];
                for (int k = 0; k <= 4; ++k)
                {
                    if (k == j)
                        continue;
                    if (DP[i - 1][k] + 1 < DP[i][j])
                        DP[i][j] = DP[i - 1][k] + 1;
                }
            }
        }
    }
    int minVal = DP[K - 1][0];
    for (int i = 0; i < 4; ++i)
        if (DP[K - 1][i] < minVal)
            minVal = DP[K - 1][i];

    printf("Case #%d: %d\n", Case, minVal);
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