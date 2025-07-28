/*BISMILLAH*/
#include <bits/stdc++.h>
using namespace std;

#define int long long

int final_ans = 0;
int ans = 0;
void call(int grid[][5], int row, int col, int ans, bool bombUsed, int effect)
{
    if (row == -1)
    {
        final_ans = max(ans, final_ans);
        return;
    }

    for (int i = -1; i <= 1; i++)
    {
        if (col + i > 4 or col + i < 0)
            continue;

        if (grid[row][col] == 1 or grid[row][col] == 0)
        {
            call(grid, row - 1, col + i, ans + grid[row][col], bombUsed, effect - bombUsed);
        }
        else
        {
            if (bombUsed and effect > 0)
                call(grid, row - 1, col + i, ans, 1, effect - 1);
            else if (!bombUsed)
            {
                call(grid, row - 1, col + i, ans, 1, 4);
            }
            else
            {
                final_ans = max(ans, final_ans);
                return;
            }
        }
    }
}

int32_t main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    for (int cs = 1; cs <= t; cs++)
    {
        int n;
        cin >> n;
        int grid[n + 1][5];
        for (int i = 0; i < n; i++)
            for (int j = 0; j < 5; j++)
                cin >> grid[i][j];

        for (int j = 0; j < 5; j++)
            grid[n][j] = 0;

        final_ans = 0;
        call(grid, n, 2, 0, 0, 0);

        cout << "#" << cs << ' ' << final_ans << endl;
    }
}