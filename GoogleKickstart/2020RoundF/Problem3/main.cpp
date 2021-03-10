#include <bits/stdc++.h>
using namespace std;
#define LL long long

struct I
{
    int s, e;
} A[100005];
bool operator < (I x, I y)
{
    return x.s < y.s;
}
void solve(int Case)
{
    int N, K;
    cin >> N >> K;
    for (int i = 0; i < N; ++i)
    {
        cin >> A[i].s >> A[i].e;
    }
    sort(A, A + N);
    int Cnt = 0;
    int last = 0;
    for(int i = 0; i < N; ++i)
    {
        int ts = last > A[i].s? last: A[i].s;
        if(ts >= A[i].e) continue;
        int deploy = (A[i].e - ts) / K;
        // printf("deploy = %d\n", deploy);
        if((A[i].e - ts) % K > 0) deploy++;
        // printf("ts = %d; A[i].e = %d;deploy = %d\n", ts, A[i].e, deploy);
        last = ts + deploy * K;
        Cnt += deploy;
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