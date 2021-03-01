#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define INF 10000005

int A[100005];
int Block[400];
int BSize;
int BSizeLast;
int N;
int BCnt;
#define getBize(i) ((i) != BCnt - 1? BSize: BSizeLast)
#define isBound(i) ((i) % BSize == 0) 
#define getLB(i) ((i) / BSize - 1)
#define getRB(i) ((i) / BSize)

int check(int pos, int k)
{
    int l = pos, r = pos;
    int lM = l == 0 ? INF:(isBound(l) ? Block[getLB(l)]: A[l - 1]);
    int rM = r == N ? INF:(isBound(r) ? Block[getRB(r)]: A[r]);
    int lHM = 0, rHM = 0;
    int lS = isBound(l) ? BSize: 1;
    int rS = isBound(r) ? getBize(getRB(r)): 1;
    while(k >= BSize * 2)
    {
        // cout << "LR1 " << l << " " << r << " " << k << " " << lM <<" "<< rM << " " << lHM<< " " <<rHM<<endl;
        if(max(lHM, lM) < max(rHM, rM))
        {
            l -= lS; k -= lS;
            if(lHM < lM) lHM = lM;
            lM = l == 0 ? INF:(isBound(l) ? Block[getLB(l)]: A[l - 1]);
            lS = isBound(l) ? BSize: 1;
        }
        else
        {
            r += rS; k -= rS;
            if(rHM < rM) rHM = rM;
            rM = r == N ? INF:(isBound(r) ? Block[getRB(r)]: A[r]);
            rS = isBound(r) ? getBize(getRB(r)): 1;
        }
    }
    int Ans = pos;
    lM = l == 0 ? INF: A[l - 1];
    rM = r == N ? INF: A[r];
    lS = 1;
    rS = 1;
    while(k > 0)
    {
        // cout << "LR2 " << l << " " << r << " " << k << " " << lM <<" "<< rM << " " << lHM<< " " <<rHM<<endl;
        if(max(lHM, lM) < max(rHM, rM))
        {
            l -= lS; k -= lS;
            if(lHM < lM) lHM = lM;
            lM = l == 0 ? INF: A[l - 1];
            lS = 1;
            Ans = l;
        }
        else
        {
            r += rS; k -= rS;
            if(rHM < rM) rHM = rM;
            rM = r == N ? INF: A[r];
            rS = 1;
            Ans = r;
        }
    }
    return Ans;
}
void solve(int Case)
{
    int Q;
    cin >> N >> Q;
    N--;
    for (int i = 0; i < N; ++i)
    {
        cin >> A[i];
    }
    BSize = sqrt(N);
    BCnt = N / BSize + (N % BSize == 0? 0: 1);
    BSizeLast = N - (BCnt - 1) * BSize;
    int Current = 0;
    for(int i = 0; i < BCnt; ++i)
    {
        Block[i] = A[Current];
        int bs = getBize(i);
        for(int j = 0; j < bs; ++j)
        {
            if(Block[i] < A[Current]) 
                Block[i] = A[Current];
            Current += 1;
        }
        // cout<< "Block[" << i << "]:" << Block[i] << endl;
    }
    printf("Case #%d:", Case);
    for(int i = 0; i < Q; ++i)
    {
        int x, k;
        cin >> x >> k;
        x--;
        int ans = check(x, k - 1) + 1;
        printf(" %d", ans);
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