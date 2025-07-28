/*BISMILLAH*/
#include <bits/stdc++.h>
using namespace std;

#define int long long

bool vis[10][10];
int graph[10][10];
int n, m;

bool dfs(int x, int y, int jumpLevel)
{
    vis[x][y] = 1;
    if (graph[x][y] == 3)
        return 1;

    bool ok = 0;
    // horizontal jump
    if (y - 1 >= 0 and !vis[x][y - 1] and graph[x][y - 1])
        ok |= dfs(x, y - 1, jumpLevel);
    if (y + 1 < m and !vis[x][y + 1] and graph[x][y + 1])
        ok |= dfs(x, y + 1, jumpLevel);

    // vertical jump
    for (int i = -jumpLevel; i <= jumpLevel; i++)
    {
        if (i == 0)
            continue;
        if (x + i >= 0 and x + i < n and !vis[x + i][y] and graph[x + i][y])
            ok |= dfs(x + i, y, jumpLevel);
    }

    return ok;
}

int32_t main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cin >> graph[i][j];
    }
    // cout << dfs(0, 0, 1) << endl;
    int l = 0, r = n - 1, ans = -1;
    while (l <= r)
    {
        int mid = (l + r) >> 1;
        memset(vis, 0, sizeof vis);
        if (dfs(n - 1, 0, mid))
            ans = mid, r = mid - 1;
        else
            l = mid + 1;
    }

    cout << ans << endl;
}