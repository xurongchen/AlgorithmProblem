#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define LD long double

int T[500005];
vector<int> child[500005];
int EA[500005];
int EB[500005];
int MA[500005];
int MB[500005];

void DFS(int node, int level, int *E, int *M, int MOD)
{
    int MPos = level % MOD;
    int MBefore = M[MPos];
    for(auto it = child[node].begin(); it != child[node].end(); ++it)
    {
        DFS(*it, level + 1, E, M, MOD);
    }
    M[MPos] += 1;
    int MAfter = M[MPos];
    E[node] = MAfter - MBefore;
}

void solve(int Case)
{
    int N, A, B;
    cin >> N >> A >> B;
    for (int i = 0; i <= N; ++i)
        child[i].clear();
    for (int i = 0; i < A; ++i)
        MA[i] = 0;
    for (int i = 0; i < B; ++i)
        MB[i] = 0;
    for (int i = 2; i <= N; ++i)
    {
        cin >> T[i];
        child[T[i]].push_back(i);
    }
    DFS(1, 1, EA, MA, A);
    DFS(1, 1, EB, MB, B);
    LL sumA = 0LL, sumB = 0LL;
    for(int i = 1; i <= N; ++i)
    {
        sumA += EA[i];
        sumB += EB[i];
    }
    LD expA = 1.0L * sumA / N, expB = 1.0L * sumB / N;
    LD expAB = 0.0L;
    for(int i = 1; i <= N; ++i)
        expAB += 1.0L * EA[i] * EB[i] / N / N;
    printf("Case #%d: %.12Lf\n", Case, expA + expB - expAB);
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