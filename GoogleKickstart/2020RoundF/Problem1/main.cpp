#include <bits/stdc++.h>
using namespace std;
#define LL long long

struct People
{
    int rounds, numid;
} A[100005];
bool operator < (People x, People y)
{
    if (x.rounds == y.rounds)
        return x.numid < y.numid;
    return x.rounds < y.rounds;
}
void solve(int Case)
{
    int N, X;
    cin >> N >> X;
    for (int i = 0; i < N; ++i)
    {
        cin >> A[i].rounds;
        A[i].rounds = (A[i].rounds - 1) / X;
        A[i].numid = i;
    }
    sort(A, A + N);
    printf("Case #%d:", Case);
    for(int i = 0; i < N; ++i)
    {
        printf(" %d", A[i].numid + 1);
    }
    printf("\n");
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