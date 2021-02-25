#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <map>
#include <vector>
#include <cmath>
#define LL long long
using namespace std;
struct Factor
{
    int f2;
    int f5;
    Factor(int _zero) : f2(-_zero), f5(-_zero) {}
    Factor(){}
};
Factor fa[200005];
bool cmp(Factor x, Factor y){
    return x.f2 > y.f2;
}
#define L2 44
#define L5 19
LL cnt[L2][L5];
LL sum[L2][L5];

#define TR(X) (X+9)

int main()
{
    int n;
    cin >> n;
    for(int i = 0; i < L2; ++i){
        for(int j = 0; j < L5; ++j){
            cnt[i][j] = 0;
        }
    }
    for (int i = 0; i < n; ++i)
    {
        char num[20];
        scanf("%s", num);
        LL val = 0;
        int zero = 0;
        bool decimalPart = false;
        for(int j=0; num[j]; ++j){
            if(num[j] == '.')
                decimalPart = true;
            else {
                val = val * 10 + (num[j] - '0');
                if(decimalPart) zero++;
            }
        }
        fa[i] = Factor(zero);
        while(val % 2 == 0){
            val /= 2;
            fa[i].f2++;
        }
        while(val % 5 == 0){
            val /= 5;
            fa[i].f5++;
        }
        // cout<<"[Trace] str:"<<num<<"f2="<<fa[i].f2<<";f5="<<fa[i].f5<<endl;;

        cnt[TR(fa[i].f2)][TR(fa[i].f5)] ++;
    }
    for(int i = L2 - 1; i >= 0; --i){
        for(int j = L5 - 1; j >= 0; --j){
            if(i == L2 - 1 && j == L5 - 1){
                sum[i][j] = cnt[i][j];
            }
            else if (i == L2 - 1){
                sum[i][j] = sum[i][j+1] + cnt[i][j];
            }
            else if (j == L5 - 1){
                sum[i][j] = sum[i+1][j] + cnt[i][j];
            }
            else {
                sum[i][j] = sum[i+1][j] + sum[i][j+1] - sum[i+1][j+1] + cnt[i][j];
            }
            // cout<<"s["<<i<<"]["<<j<<"]="<<sum[i][j]<<" ";
        }
        // cout<<endl;
    }
    LL ans = 0;
    for (int i = 0; i < n; ++i)
    {
        int x2 = TR(-fa[i].f2);
        if(x2<0) x2 = 0;
        int x5 = TR(-fa[i].f5);
        if(x5<0) x5 = 0;
        // cout<<"[Trace] x2="<< x2<<" x5="<<x5<<" s="<<sum[x2][x5]<<endl;
        ans = ans + sum[x2][x5];
        if(fa[i].f2 >= 0 && fa[i].f5 >= 0) ans -= 1;
    }

    printf("%lld\n", ans/2);
    

}