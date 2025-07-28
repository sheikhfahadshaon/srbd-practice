/*BISMILLAH*/
#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int k;
    cin >> k;
    string tree;
    cin >> tree;

    int level = -1;
    int sum = 0;

    for (int i = 0; tree[i]; i++)
    {
        if (tree[i] == '(')
            level++;
        else if (tree[i] == ')')
            level--;
        else if (level == k)
        {
            int val = 0;
            while (tree[i] != '(' and tree[i] != ')')
            {
                val = val * 10 + (tree[i] - '0');
                i++;
            }
            i--;
            // cout << val << " added\n";
            sum += val;
        }
    }

    cout << sum << endl;
}