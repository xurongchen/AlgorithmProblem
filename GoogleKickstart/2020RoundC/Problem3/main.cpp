#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define LD long double

int A[100005];
int S[100005];
int P[3300];
int PN = 0;
int NPS[20000008];
#define ID(X) (X + 10000002)

int solveSet1(int N)
{
    int Cnt = 0;
    for (int i = 0; i < N; ++i)
    {
        // cout << i << " " << i << endl;
        int sqr = (int)sqrt(S[i]);
        if (sqr * sqr == S[i])
        {
            Cnt += 1;
            // cout << "Hit";
        }
    }

    for (int i = 1; i < N; ++i)
        for (int j = i; j < N; ++j)
        {
            // cout << i << " " << j << endl;
            int SU = S[j] - S[i - 1];
            int sqr = (int)sqrt(SU);
            if (sqr * sqr == SU)
            {
                Cnt += 1;
                // cout << "Hit";
            }
        }
    return Cnt;
}
void solve(int Case)
{
    int N;
    int SMax = 0;
    int SMin = 0;
    cin >> N;
    for (int i = 0; i < N; ++i)
        cin >> A[i];
    S[0] = A[0];
    for (int i = 1; i < N; ++i)
    {
        S[i] = S[i - 1] + A[i];
        if(SMax < S[i]) SMax = S[i];
        if(SMin > S[i]) SMin = S[i];
    }
    // if (N <= 1000)
    // {
    //     printf("Case #%d: %d\n", Case, solveSet1(N));
    //     return;
    // }
    // unordered_map<int, int> PS;
    // PS[0] += 1;
    // for (int i = 0; i < N; ++i)
    //     PS[S[i]] += 1;
    for(int i = 0; i < 20000008; ++i)
        NPS[i] = 0;
    NPS[ID(0)] = 1;
    for (int i = 0; i < N; ++i)
        NPS[ID(S[i])] += 1;

    LL Rst = 0L;
    int RPN = PN;
    while(SMax - SMin < P[RPN - 1]) RPN -= 1;
    for (int r = N - 1; r >= 0; --r)
    {
        // PS[S[r]] -= 1;
        NPS[ID(S[r])] -= 1;

        for (int i = 0; i < RPN; ++i)
            // Rst += PS[S[r] - P[i]];
            Rst += NPS[ID(S[r] - P[i])];
    }
    printf("Case #%d: %lld\n", Case, Rst);
}
void init()
{
    for (int i = 0; i * i <= 10000000; ++i)
    {
        P[PN++] = i * i;
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    init();
    for (int i = 0; i < T; ++i)
    {
        solve(i + 1);
    }
}