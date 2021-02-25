#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define LD long double

LD JDG = 1e-200L;
LD LJC[200005];
LD LP2[200005];

LD calc(int X, int Y)
{
    return exp(LJC[X + Y] - LJC[X] - LJC[Y] - LP2[X + Y]);
}

void solve(int Case)
{
    int W, H, L, U, R, D;
    cin >> W >> H >> L >> U >> R >> D;
    W--; H--; L--; U--; R--; D--;
    LD Sum1 = 0.0L;
    LD R1 = calc(L, D);
    // cout << "D" << R1 << endl;
    if (L != 0 && D != H)
        while (true)
        {
            if (L == 0)
                break;
            // R1 = R1 * L / (D + 1);
            R1 = calc(L - 1, D + 1);
            // cout << "E" << R1 << endl;

            Sum1 += R1;
            L -= 1;
            D += 1;
        }
    // cout << "F" << Sum1 << endl;

    LD Sum2 = 0.0L;
    LD R2 = calc(R, U);
    // cout << "D" << R2 << endl;
    if (R != W && U != 0)
        while (true)
        {
            if (U == 0)
                break;
            // R2 = R2 * U / (R + 1);
            R2 = calc(R + 1, U - 1);
            // cout << "E" << R2 << endl;
            Sum2 += R2;
            R += 1;
            U -= 1;
        }
    // cout << "F" << Sum2 << endl;

    cout << "Case #" << Case << ": " << Sum1 + Sum2 << endl;
}

void init()
{
    LJC[0] = 0;
    LP2[0] = 0;
    for (int i = 1; i < 200002; ++i)
    {
        LJC[i] = LJC[i - 1] + log(1.0L * i);
        LP2[i] = LP2[i - 1] + log(2.0L);
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    init();
    int T;
    cin >> T;
    for (int i = 0; i < T; ++i)
    {
        solve(i + 1);
    }
}