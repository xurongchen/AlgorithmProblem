#include <bits/stdc++.h>
using namespace std;
#define LL long long

int A[52][32];
int R[1502];
int LR[1502];
void solve(int Case)
{
    int N, K, P;
    cin >> N >> K >> P;
    for (int i = 0; i < N; ++i)
    {
        A[i][0] = 0;
        for (int j = 1; j <= K; ++j)
        {
            cin >> A[i][j];
            A[i][j] += A[i][j - 1];
        }
    }
    for (int i = 0; i <= P; ++i)
        R[i] = 0;
    for (int i = 0; i < N; ++i)
    {
        for(int k = 0; k <= P; ++k)
            LR[k] = R[k];
        for (int j = K; j >= 0; --j)
            for (int k = 0; k <= P - j; ++k)
            {
                R[k + j] = max(R[k + j], LR[k] + A[i][j]);
            }
    }
    printf("Case #%d: %d\n", Case, R[P]);
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