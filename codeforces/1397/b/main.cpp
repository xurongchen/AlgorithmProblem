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
LL a[100005];
int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
    {
        scanf("%lld", &a[i]);
    }
    sort(a, a+n);
    LL MAX = pow(a[n-1], 1.0/(n - 1)) + 1;

    if(n > 40) MAX = 1;
    LL minCost = -1;
    LL po = 1;
    for(LL c = 1; c <= MAX; ++c){
        LL cost = 0;
        for(int i = 0; i < n; ++i){
            LL dif = po - a[i];
            cost += dif > 0? dif: -dif;
            po *= c;
        }
        // cout<<"[Trace] c = "<< c << ";cost = "<<cost<<endl;
        if(cost < minCost || minCost == -1)
            minCost = cost;
        po = 1;
    }
    printf("%lld\n", minCost);
}