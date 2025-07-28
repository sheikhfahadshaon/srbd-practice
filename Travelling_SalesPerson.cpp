// bitmask

/*BISMILLAH*/
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define mem(dp, x) memset(dp, x, sizeof dp)
#define SetBit(x, k) (x |= (1LL << k))
#define ClearBit(x, k) (x &= ~(1LL << k))
#define CheckBit(x, k) ((x >> k) & 1)

int n, graph[15][15];
int dp[15][(1 << 13)];
int call(int city, int mask)
{
    SetBit(mask, city);
    if (mask == (1LL << n) - 1LL)
    {
        return graph[city][0];
    }
    if (dp[city][mask] != -1)
        return dp[city][mask];

    int ret = INT_MAX;

    for (int i = 0; i < n; i++)
    {
        if (CheckBit(mask, i) == 0)
        {
            ret = min(ret, graph[city][i] + call(i, mask));
        }
    }

    return dp[city][mask] = ret;
}

void solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
            cin >> graph[i - 1][j - 1];
    }

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j < (1 << n); j++)
            dp[i][j] = -1;
    }

    cout << call(0, 0) << endl;
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--)
        solve();
}