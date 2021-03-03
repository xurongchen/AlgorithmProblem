#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define INF 1000000000000LL

int N, M, S, R;
vector<int> Next[305];
vector<int> RecipeFr[305];
vector<int> StoneRecipes[305];
int RecipeTo[305];
LL cost[305][305];
struct Elem
{
    int Nid, Sid;
    Elem(int _Nid, int _Sid): Nid(_Nid), Sid(_Sid) {}
};
bool operator < (Elem x, Elem y)
{
    if(cost[x.Nid][x.Sid] != cost[y.Nid][y.Sid])
        return cost[x.Nid][x.Sid] < cost[y.Nid][y.Sid];
    else if(x.Nid != y.Nid)
        return x.Nid < y.Nid;
    else return x.Sid < y.Sid;
}
set<Elem> ESet;

LL costRecipe(int Rid, int Nid)
{
    LL Rst = 0LL;
    for(auto Sid: RecipeFr[Rid])
    {
        Rst += cost[Nid][Sid];
        if(Rst > INF) 
        {
            Rst = INF;
            break;
        }
    }
    return Rst;
}

void update(int Nid, int Sid)
{
    for(auto next: Next[Nid])
    {
        if(cost[Nid][Sid] + 1 < cost[next][Sid])
        {
            ESet.erase(Elem(next, Sid));
            cost[next][Sid] = cost[Nid][Sid] + 1;
            ESet.insert(Elem(next, Sid));
            // printf("[Debug] Update (Nid: %d, Sid: %d) => (Nid: %d, Sid: %d)\n", Nid, Sid, next, Sid);
        }
    }
    for(auto Rid: StoneRecipes[Sid])
    {
        LL rCost = costRecipe(Rid, Nid);
        if(rCost < cost[Nid][RecipeTo[Rid]])
        {
            ESet.erase(Elem(Nid, RecipeTo[Rid]));
            cost[Nid][RecipeTo[Rid]] = rCost;
            ESet.insert(Elem(Nid, RecipeTo[Rid]));
            // printf("[Debug] Update (Nid: %d, Sid: %d) => (Nid: %d, Sid: %d)\n", Nid, Sid, Nid, RecipeTo[Rid]);
        }
    }
}
void solve(int Case)
{
    cin >> N >> M >> S >> R;
    ESet.clear();
    for(int i = 1; i <= N; ++i)
        Next[i].clear();  

    for(int i = 0; i < M; ++i)
    {
        int n1, n2;
        cin >> n1 >> n2;
        Next[n1].push_back(n2);
        Next[n2].push_back(n1);
    }
    for(int i = 1; i <= N; ++i)
    {
        for(int j = 1; j <= S; ++j)
        {
            cost[i][j] = INF;
        }
        int cnt;
        cin >> cnt;
        for(int j = 0; j < cnt; ++j)
        {
            int sid;
            cin >> sid;
            cost[i][sid] = 0;
            ESet.insert(Elem(i, sid));
        }
    }
    for(int i = 0; i < R; ++i)
        RecipeFr[i].clear(); 
    for(int i = 1; i <= S; ++i)
        StoneRecipes[i].clear();
    for(int i = 0; i < R; ++i)
    {
        int cnt, reTo;
        cin >> cnt;
        for(int j = 0; j < cnt; ++j)
        {
            int reFr;
            cin >> reFr;
            RecipeFr[i].push_back(reFr);
            StoneRecipes[reFr].push_back(i);
        }
        cin >> reTo;
        RecipeTo[i] = reTo;
    }

    LL bestResult = INF;
    LL TOTest = 0;
    while(ESet.size() > 0)
    {
        if(TOTest > N * S)
            assert(0);
        TOTest += 1;
        Elem top = *ESet.begin();
        if(cost[top.Nid][top.Sid] >= bestResult)
            break;
        else if(top.Sid == 1)
            bestResult = cost[top.Nid][top.Sid];
        
        // printf("[Debug] Now TOP: (Nid:%d, Sid:%d), Cost: %d\n", top.Nid, top.Sid, cost[top.Nid][top.Sid]);
        ESet.erase(top);
        update(top.Nid, top.Sid);
    }
    
    if(bestResult == INF)
        bestResult = -1LL;
    
    printf("Case #%d: %lld\n", Case, bestResult);
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