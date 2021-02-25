#include <bits/stdc++.h>
using namespace std;
#define LL long long

int A[200005];
void solve(int Case)
{
    int N, K;
    cin >> N >> K;
    for (int i = 0; i < N; ++i)
    {
        cin >> A[i];
    }
    int Cnt = 0;
    int Cur = K;
    for (int i = 0; i < N; ++i)
    {
        if (A[i] == Cur)
            Cur -= 1;
        else if (A[i] != K)
            Cur = K;
        else Cur = K - 1;
        if(Cur == 0)
        {
            Cur = K;
            Cnt += 1;
        }
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