#include <bits/stdc++.h>
using namespace std;
#define LL long long

#define INF 999999
int pos2id(int R, int P)
{
    return (R - 1) * (R - 1) + P - 1;
}
int visited[40];

int dR[2][3] = {-1, 0, 0,  0, 0, 1};
int dP[2][3] = {-1,-1, 1, -1, 1, 1};
bool valid(int R, int P, int S)
{
    return R >= 1 && R <= S && P >= 1 && P <= 2 * R - 1;
}

int dfs(int RA, int PA, int RB, int PB, int term, int CntA, int CntB, int S)
{
    // cout << term << "@HIT " << RA << " " <<PA<< " "<< RB << " " <<PB<<endl;

    if(term == 1 || term == -1) // A
    {
        bool novalid = true;
        int maxValue = -INF;
        for(int i = 0; i < 3; ++i)
        {
            int RA_n = RA + dR[PA % 2][i];
            int PA_n = PA + dP[PA % 2][i];
            bool isValid = valid(RA_n, PA_n, S) && visited[pos2id(RA_n, PA_n)] == 0;
            if(isValid)
            {
                visited[pos2id(RA_n, PA_n)] = 1;
                int rst;
                if(term == 1)
                    rst = dfs(RA_n, PA_n, RB, PB, 2, CntA + 1, CntB, S);
                else
                    rst = dfs(RA_n, PA_n, RB, PB, -1, CntA + 1, CntB, S);
                if(rst > maxValue) maxValue = rst;
                visited[pos2id(RA_n, PA_n)] = 0;
            }
            novalid = novalid && !isValid;
        }
        // cout << maxValue << " MAX"<<endl;
        if(!novalid) return maxValue;
        if(novalid && term == -1)
            return CntA - CntB;
        // cout << "HIT" << RA << " "<< RB << " " <<PA<< " " <<PB<<endl;
        if(novalid) 
            return dfs(RA, PA, RB, PB, -2, CntA, CntB, S);
    }
    else // B 2 || -2
    {
        bool novalid = true;
        int minValue = INF;
        for(int i = 0; i < 3; ++i)
        {
            int RB_n = RB + dR[PB % 2][i];
            int PB_n = PB + dP[PB % 2][i];
            // cout << RB_n <<" "<< PB_n <<" "<< RB <<" "<< PB << endl;
            bool isValid = valid(RB_n, PB_n, S) && visited[pos2id(RB_n, PB_n)] == 0;
            // cout << "i:" << i << " "<< valid(RB_n, PB_n, S) << " " <<visited[pos2id(RB_n, PB_n)] <<endl;
            if(isValid)
            {
                visited[pos2id(RB_n, PB_n)] = 1;
                int rst;
                if(term == 2)
                    rst = dfs(RA, PA, RB_n, PB_n, 1, CntA, CntB + 1, S);
                else
                    rst = dfs(RA, PA, RB_n, PB_n, -2, CntA, CntB + 1, S);
                if(rst < minValue) minValue = rst;
                visited[pos2id(RB_n, PB_n)] = 0;
            }
            novalid = novalid && !isValid;
        }
        // cout << minValue << " MIN" << endl;
        if(!novalid) return minValue;
        if(novalid && term == -2)
            return CntA - CntB;
        if(novalid) 
            return dfs(RA, PA, RB, PB, -1, CntA, CntB, S);
    }
}

void solve(int Case)
{
    int S, RA, PA, RB, PB, C;
    cin >> S >> RA >> PA >> RB >> PB >> C;
    for (int i = 0; i < S * S; ++i)
        visited[i] = 0;
    for (int i = 0; i < C; ++i)
    {
        int R, P;
        cin >> R >> P;
        visited[pos2id(R, P)] = 1;
    }
    visited[pos2id(RA, PA)] = 1;
    visited[pos2id(RB, PB)] = 1;

    printf("Case #%d: %d\n", Case, dfs(RA,PA,RB,PB,1,1,1,S));
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