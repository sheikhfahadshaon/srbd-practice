/*BISMILLAH*/
#include <bits/stdc++.h>
using namespace std;

#define int long long

vector<int> graph[12];
vector<int> clr(12);
vector<int> par(12);
vector<int> bestCycle;
map<pair<int, int>, bool> usedEdge;
int bestSum;

void dfs(int u)
{
    clr[u] = 1;
    for (int v : graph[u])
    {
        par[v] = u;
        if (clr[v] == 1 and !usedEdge[{u, v}])
        {
            // there is a cycle
            // cout << "found a cycle " << u << ' ' << v << endl;
            int cur = u;
            vector<int> cycle;
            int sum = v;
            cycle.push_back(v);
            while (cur != v)
            {
                sum += cur;
                cycle.push_back(cur);
                cur = par[cur];
            }
            if (sum < bestSum)
            {
                bestSum = sum;
                bestCycle = cycle;
            }
            usedEdge[{u, v}] = 1;
            dfs(v);
        }
        else if (clr[v] == 0 and !usedEdge[{u, v}])
        {
            usedEdge[{u, v}] = 1;
            dfs(v);
        }
    }
    clr[u] = 2;
}

int32_t main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
    }

    bestSum = INT_MAX;
    for (int i = 1; i <= n; i++)
    {
        if (clr[i] == 0)
            dfs(i);
    }

    sort(bestCycle.begin(), bestCycle.end());

    for (int i : bestCycle)
        cout << i << ' ';
    cout << endl;
}