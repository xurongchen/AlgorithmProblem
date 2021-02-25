#include <bits/stdc++.h>
using namespace std;
#define LL long long

char M[35][35];
void solve(int Case)
{
    int R, C;
    cin >> R >> C;

    for (int i = 0; i < R; ++i)
        cin >> M[i];

    set<char> P;
    map<char, set<char>> B;
    for (int i = 0; i < R; ++i)
        for (int j = 0; j < C; ++j)
            P.insert(M[i][j]);

    for (int i = 1; i < R; ++i)
        for (int j = 0; j < C; ++j)
        {
            if (M[i - 1][j] != M[i][j])
            {
                B[M[i - 1][j]].insert(M[i][j]);
            }
        }
    char Rst[30];
    int PSize = P.size();
    for (int i = 0; i < PSize; ++i)
    {
        bool find = false;
        for (auto PI = P.begin(); PI != P.end(); ++PI)
        {
            if (B[*PI].size() == 0)
            {
                Rst[i] = *PI;
                for (auto PJ = P.begin(); PJ != P.end(); ++PJ)
                {
                    if (B[*PJ].count(*PI) == 1)
                    {
                        B[*PJ].erase(*PI);
                    }
                }
                find = true;
                B.erase(*PI);
                P.erase(*PI);
                // cout<<"@"<<*PI;
                break;
            }
        }
        if (!find)
        {
            printf("Case #%d: -1\n", Case);
            return;
        }
    }
    printf("Case #%d: ", Case);
    for (int i = 0; i < PSize; ++i)
        printf("%c", Rst[i]);
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