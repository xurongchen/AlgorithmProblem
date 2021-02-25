#include <bits/stdc++.h>
using namespace std;
#define LL long long

int A[100005];
void solve(int Case)
{
    int N, B;
    cin >> N >> B;
    for (int i = 0; i < N; ++i)
    {
        cin >> A[i];
    }
    sort(A, A + N);
    int Sum = 0, i = 0;
    for (; i < N && Sum + A[i] <= B; ++i)
    {
        Sum += A[i];
    }
    printf("Case #%d: %d\n", Case, i);
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