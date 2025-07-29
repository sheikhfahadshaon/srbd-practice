/*BISMILLAH*/
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define mem(dp, x) memset(dp, x, sizeof dp)
#define SetBit(x, k) (x |= (1LL << k))
#define ClearBit(x, k) (x &= ~(1LL << k))
#define CheckBit(x, k) ((x >> k) & 1)

bool horizontal[2][55][55], vertical[2][55][55];
int n, m;
bool vis[22][55][55], final_vis[55][55];

/*
vertical_0 -> up
vertical_1 -> down

horizontal_0 -> right
horizontal_1 -> left

*/

void dfs(int x, int y, int remL)
{
    final_vis[x][y] = 1;
    vis[remL][x][y] = 1;
    // cout << x << ' ' << y << ' ' << remL << endl;
    if (remL == 1)
        return;

    // go up
    if (vertical[0][x][y] and x - 1 >= 0 and vertical[1][x - 1][y] and !vis[remL - 1][x - 1][y])
        dfs(x - 1, y, remL - 1);
    // go down
    if (vertical[1][x][y] and x + 1 < n and vertical[0][x + 1][y] and !vis[remL - 1][x + 1][y])
        dfs(x + 1, y, remL - 1);

    // go right
    if (horizontal[0][x][y] and y + 1 < m and horizontal[1][x][y + 1] and !vis[remL - 1][x][y + 1])
        dfs(x, y + 1, remL - 1);
    // go left
    if (horizontal[1][x][y] and y - 1 >= 0 and horizontal[0][x][y - 1] and !vis[remL - 1][x][y - 1])
        dfs(x, y - 1, remL - 1);
}

void solve()
{
    int x, y, l;
    cin >> n >> m >> x >> y >> l;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            final_vis[i][j] = vertical[0][i][j] = vertical[1][i][j] = horizontal[0][i][j] = horizontal[1][i][j] = 0;
            for (int k = 0; k <= l; k++)
                vis[k][i][j] = 0;
        }
    }

    int grid[n][m];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> grid[i][j];

            switch (grid[i][j])
            {
            case 1:
                vertical[0][i][j] = vertical[1][i][j] = horizontal[0][i][j] = horizontal[1][i][j] = 1;
                break;
            case 2:
                vertical[0][i][j] = vertical[1][i][j] = 1;
                break;
            case 3:
                horizontal[0][i][j] = horizontal[1][i][j] = 1;
                break;
            case 4:
                vertical[0][i][j] = horizontal[0][i][j] = 1;
                break;
            case 5:
                vertical[1][i][j] = horizontal[0][i][j] = 1;
                break;
            case 6:
                vertical[1][i][j] = horizontal[1][i][j] = 1;
                break;
            case 7:
                vertical[0][i][j] = horizontal[1][i][j] = 1;
                break;

            default:
                break;
            }
        }
    }

    dfs(x, y, l);

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (final_vis[i][j])
                ans++;
        }
    }
    cout << ans << endl;
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