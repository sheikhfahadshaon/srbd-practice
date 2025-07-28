/*BISMILLAH*/
#include <bits/stdc++.h>
using namespace std;

#define int long long
int n;
int call(int i, int j, vector<int> &nums, vector<vector<int>> &dp)
{
    if (i > j)
        return 0;
    if (dp[i][j] != -1)
        return dp[i][j];

    int ret = INT_MIN;

    for (int ind = i; ind <= j; ind++)
    {
        int mul = nums[i - 1] * nums[j + 1];
        if (i == 1 and j == n)
            mul = nums[ind];
        int option = mul + call(i, ind - 1, nums, dp) + call(ind + 1, j, nums, dp);
        ret = max(ret, option);
    }

    return dp[i][j] = ret;
}

int32_t main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    vector<int> nums;
    nums.push_back(1);
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        nums.push_back(x);
    }
    nums.push_back(1);

    vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));

    cout << call(1, n, nums, dp) << endl;
}

/*
1 2 3 4
1 2 4 -> 8
1 4 -> 4
1 -> 4
 -> 1
*/