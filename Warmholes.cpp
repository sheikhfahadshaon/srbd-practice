/*BISMILLAH*/
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define mem(dp, x) memset(dp, x, sizeof dp)
#define SetBit(x, k) (x |= (1LL << k))
#define ClearBit(x, k) (x &= ~(1LL << k))
#define CheckBit(x, k) ((x >> k) & 1)

map<int, pair<int, int>> nodes;
map<pair<int, int>, int> wormhole, coordsToNode;

void solve()
{
    int n;
    cin >> n;
    int sx, sy, dx, dy;
    cin >> sx >> sy >> dx >> dy;

    int nodeNum = 0;

    coordsToNode[{sx, sy}] = nodeNum;
    nodes[nodeNum++] = {sx, sy};

    coordsToNode[{dx, dy}] = nodeNum;
    nodes[nodeNum++] = {dx, dy};

    for (int i = 0; i < n; i++)
    {
        int x1, y1, x2, y2, d;
        cin >> x1 >> y1 >> x2 >> y2 >> d;

        int X1, X2;

        if (coordsToNode.find({x1, y1}) != coordsToNode.end())
        {
            X1 = coordsToNode[{x1, y1}];
        }
        else
        {
            X1 = nodeNum;
            coordsToNode[{x1, y1}] = nodeNum;
            nodes[nodeNum++] = {x1, y1};
        }

        if (coordsToNode.find({x2, y2}) != coordsToNode.end())
        {
            X2 = coordsToNode[{x2, y2}];
        }
        else
        {
            X2 = nodeNum;
            coordsToNode[{x2, y2}] = nodeNum;
            nodes[nodeNum++] = {x2, y2};
        }

        wormhole[{X1, X2}] = min(d, abs(x1 - x2) + abs(y1 - y2));
        wormhole[{X2, X1}] = min(d, abs(x1 - x2) + abs(y1 - y2));
    }

    int adj[nodeNum][nodeNum]{};

    for (int i = 0; i < nodeNum; i++)
    {
        for (int j = i + 1; j < nodeNum; j++)
        {
            if (wormhole.find({i, j}) != wormhole.end())
            {
                adj[i][j] = wormhole[{i, j}];
            }
            else
            {
                adj[i][j] = abs(nodes[i].first - nodes[j].first) + abs(nodes[i].second - nodes[j].second);
            }

            adj[j][i] = adj[i][j];
        }
    }

    int src = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, src});

    vector<int> dis(nodeNum, INT_MAX);
    dis[src] = 0;

    while (!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();

        for (int v = 0; v < nodeNum; v++)
        {
            if (v == u)
                continue;

            if (dis[v] > dis[u] + adj[u][v])
            {
                dis[v] = dis[u] + adj[u][v];
                pq.push({dis[v], v});
            }
        }
    }

    cout << dis[1] << endl;
    nodes.clear();
    wormhole.clear();
    coordsToNode.clear();
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