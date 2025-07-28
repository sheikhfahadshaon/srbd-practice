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
        return graph[city][n];
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

int manhattanDistance(int x1, int y1, int x2, int y2)
{
    return abs(x1 - x2) + abs(y1 - y2);
}

void solve(int cs)
{
    cin >> n;

    vector<int> X(n + 1), Y(n + 1);
    int ox, oy;
    cin >> ox >> oy;
    cin >> X[n] >> Y[n];

    for (int i = 0; i < n; i++)
        cin >> X[i] >> Y[i];

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j < (1 << n); j++)
            dp[i][j] = -1;
    }

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            graph[i][j] = manhattanDistance(X[i], Y[i], X[j], Y[j]);
        }
    }

    int ans = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        ans = min(ans, manhattanDistance(ox, oy, X[i], Y[i]) + call(i, 0));
    }

    cout << "# " << cs << ' ' << ans << endl;
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    t = 10;
    for (int i = 1; i <= 10; i++)
        solve(i);
}