/*BISMILLAH*/
#include <bits/stdc++.h>
using namespace std;

#define int long long

int n, n_people;
bool available[10];
int p[10];
int assigned[10];
int ans;

void backTrack(int people)
{
    if (people == n_people)
    {
        int sum = 0;
        for (int i = 0; i < n_people; i++)
        {
            sum += 1 + abs(assigned[i] - p[i]);
        }
        ans = min(ans, sum);

        return;
    }

    for (int i = 0; i < n; i++)
    {
        if (available[i])
        {
            assigned[people] = i;
            available[i] = 0;

            backTrack(people + 1);

            assigned[people] = -1;
            available[i] = 1;
        }
    }
}

int32_t main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    int g[3];
    for (int i = 0; i < 3; i++)
        cin >> g[i];
    int cnt = 0;
    for (int i = 0; i < 3; i++)
    {
        int x;
        cin >> x;
        while (x--)
        {
            p[cnt++] = g[i] - 1;
        }
    }
    n_people = cnt;

    for (int i = 0; i < 10; i++)
        available[i] = 1, assigned[i] = -1;

    ans = INT_MAX;

    backTrack(0);

    cout << ans << endl;
}