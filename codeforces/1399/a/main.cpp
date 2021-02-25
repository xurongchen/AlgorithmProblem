#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <map>
#include <vector>
using namespace std;
int a[55];
int main()
{
    int t;
    int n;
    cin >> t;
    while (t--)
    {
        cin >> n;
        for (int i = 0; i < n; ++i)
            cin >> a[i];
        sort(a, a + n);
        bool flag = false;
        for (int i = 1; i < n; ++i)
        {
            if (a[i] - a[i - 1] >= 2)
            {
                flag = true;
                break;
            }
        }
        if (flag)
            cout << "NO" << endl;
        else
            cout << "YES" << endl;
    }
}