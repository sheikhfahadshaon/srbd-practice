/*BISMILLAH*/
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define mem(dp, x) memset(dp, x, sizeof dp)
#define SetBit(x, k) (x |= (1LL << k))
#define ClearBit(x, k) (x &= ~(1LL << k))
#define CheckBit(x, k) ((x >> k) & 1)

int n, m, k;
int grid[20][20];
int ans;

void backTrack(int remK, vector<int> &distribution)
{
    if (remK == 0)
    {
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            bool rowGood = 1;
            for (int j = 0; j < m; j++)
            {
                bool val = grid[i][j];
                if (distribution[j] % 2)
                    val = !val;
                rowGood &= val;
            }
            if (rowGood)
                cnt++;
        }
        ans = max(ans, cnt);

        return;
    }

    for (int i = 0; i < m; i++)
    {
        distribution[i]++;
        backTrack(remK - 1, distribution);
        distribution[i]--;
    }
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> k;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cin >> grid[i][j];
    }

    vector<int> distribution(m, 0);
    backTrack(k, distribution);

    cout << ans << endl;
}