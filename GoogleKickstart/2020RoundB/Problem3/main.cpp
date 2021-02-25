#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define LD long double

char P[2005];
LL MAX = 1000000000LL;

struct MV
{
    LL C, R;
    MV(LL _C, LL _R) : C(_C), R(_R) {}
    MV() : C(0), R(0) {}
};

int findRight(int l)
{
    int cnt = 1;
    while (cnt != 0)
    {
        l += 1;
        if (P[l] == ')')
            cnt -= 1;
        else if (P[l] == '(')
            cnt += 1;
    }
    return l;
}
MV DFS(int l, int r)
{
    MV mv;
    if(l > r) return mv;
    LL repeat = 1;
    if (P[l] >= '0' && P[l] <= '9')
    {
        repeat = P[l] - '0';
        int rp = findRight(l + 1);
        MV mv0 = DFS(l + 1, rp - 1);
        mv.C = mv0.C * repeat % MAX;
        mv.R = mv0.R * repeat % MAX;
        l = rp;
    }
    else 
    {
        switch (P[l])
        {
        case 'N':
            mv.R = -1;
            break;
        case 'S':
            mv.R = 1;
            break;
        case 'E':
            mv.C = 1;
            break;
        case 'W':
            mv.C = -1;
            break;
        default:
            break;
        }
    }
    MV mv1 = DFS(l + 1, r);
    mv.C = (mv.C + mv1.C) % MAX;
    mv.R = (mv.R + mv1.R) % MAX;
    return mv;
}

void solve(int Case)
{
    cin >> P;
    MV mv = DFS(0, strlen(P));
    printf("Case #%d: %lld %lld\n", Case, (mv.C % MAX + MAX) % MAX + 1, (mv.R % MAX + MAX) % MAX + 1);
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