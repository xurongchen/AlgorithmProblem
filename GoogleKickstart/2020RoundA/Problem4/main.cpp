#include <bits/stdc++.h>
using namespace std;
#define LL long long

string A[100005];
struct SL
{
    string ctx;
    SL(string _ctx) : ctx(_ctx) {}
};
bool operator<(SL x, SL y)
{
    return x.ctx.length() < y.ctx.length();
}
void solve(int Case)
{
    int N, K;
    cin >> N >> K;
    for (int i = 0; i < N; ++i)
        cin >> A[i];
    map<string, int> M;
    priority_queue<SL> Q;
    for (int i = 0; i < N; ++i)
    {
        if (M[A[i]] == 0)
            Q.push(SL(A[i]));
        M[A[i]] += 1;
    }
    int Result = 0;
    while (!Q.empty())
    {
        string s = Q.top().ctx;
        // cout<<"=>"<<s<<endl;
        Q.pop();
        if (M[s] >= K)
        {
            Result += M[s] / K * s.length();
            M[s] = M[s] % K;
        }
        if(M[s] > 0)
        {
            string subs = s.substr(0, s.length() - 1);
            if(M[subs] == 0)
                Q.push(SL(subs));
            M[subs] += M[s];
            M.erase(s);
        }
    }
    printf("Case #%d: %d\n", Case, Result);
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