#include <bits/stdc++.h>
using namespace std;
#define LL long long

void solve(int Case)
{
    int N, A, B, C;
    cin >> N >> A >> B >> C;
    printf("Case #%d:", Case);
    vector<int> result;
    if(N - (A - C) - C - (B - C) < 0 || A < C || B < C)
    {
        printf(" IMPOSSIBLE\n");
        return;
    }
    for(int i = 0; i < A - C; ++i)
        result.push_back(N - 1);
    for(int i = 0; i < C; ++i)
        result.push_back(N);
    for(int i = 0; i < B - C; ++i)
        result.push_back(N - 1);
    if(result.size() == 1 && N - (A - C) - C - (B - C) > 0)
    {
        printf(" IMPOSSIBLE\n");
        return;
    }
    for(int i = 0; i < N - (A - C) - C - (B - C); ++i)
        result.insert(result.end() - 1, 1);
    
    for(int i = 0; i < N; ++i)
    {
        printf(" %d", result[i]);
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