#include <bits/stdc++.h>

using namespace std;

vector<vector<pair<int,int>>> adj(100001), adj2(1001);
vector<vector<int>> fromTo(1001, vector<int> (1001, INT_MAX)), spt(13, vector<int>(1001));
vector<vector<vector<int>>> wt(2, vector<vector<int>>(13, vector<int>(1001)));
vector<int> dfn(100001, -1), low(100001, -1), mp(100001), smp(100001), height(1001);
vector<bool> vis(100001);
int dist[1001][201][201];
stack<int> ss;
int tt = 0, nn = 1;

void SCC(int u)
{
    dfn[u] = low[u] = ++tt;
    ss.push(u);
    vis[u] = true;
    for (auto &x : adj[u])
    {
        if (dfn[x.first] == -1)
        {
            SCC(x.first);
            low[u] = min(low[u], low[x.first]);
        }
        else if (vis[x.first])
            low[u] = min(low[u], dfn[x.first]);
    }
    if (low[u] == dfn[u])
    {
        int t = 1;
        while (ss.top() != u)
        {
            int v = ss.top();
            ss.pop();
            vis[v] = false, mp[v] = nn;
            t++;
        }
        assert(t <= 200);
        ss.pop();
        vis[u] = false, mp[u] = nn;
        nn++;
    }
}

void bfs(int src)
{
    int cursz = 0;
    if (!smp[src]) smp[src] = ++cursz;
    int *dis = dist[mp[src]][smp[src]];
    if (dis[smp[src]] != INT_MAX) 
        return;
    dis[smp[src]] = 0;
    queue<int> buf;
    buf.push(src);
    while (!buf.empty())
    {
        int u = buf.front();
        buf.pop();
        vis[u] = false;
        for (auto &x : adj[u])
        {
            if (mp[x.first] != mp[src]) 
                continue;
            if (!smp[x.first]) 
                smp[x.first] = ++cursz;
            if (dis[smp[u]]+x.second < dis[smp[x.first]])
            {
                dis[smp[x.first]] = dis[smp[u]] + x.second;
                if (!vis[x.first])
                    vis[x.first] = true, buf.push(x.first);
            }
        }
    }
}

void dfs(int u, int p, int w)
{
    spt[0][u] = p, wt[0][0][u] = wt[1][0][u] = w, height[u] = height[p]+1;
    for (auto &x : adj2[u])
        if (x.first != p)
            dfs(x.first, u, x.second);
}

inline int jump(int k, int d)
{
    if (k < 0) return d;
    for (int x = 0; k; x++, k>>=1)
        if (k&1)
            d = spt[x][d];
    return d;
}

inline int lca(int a, int b)
{
    if (height[b] < height[a]) 
        swap(a, b);
    int h = height[b]-height[a];
    b = jump(h, b);
    if (a == b) 
        return a;
    for (int x = spt.size()-1; x >= 0; x--)
        if (spt[x][a] != spt[x][b])
            a = spt[x][a], b = spt[x][b];
    return spt[0][a];
}

inline int edgeSum(int a, int b, int d)
{
    int h = height[b]-height[a], sum = 0;
    for (int x = spt.size()-1; x >= 0 && h; x--)
    {
        int y = 1<<x;
        if (h&y)
        {
            sum += wt[d][x][b];
            int bb = b;
            b = spt[x][b];
            int tmp[] = {jump(y-1, bb), spt[0][b]};
            if (h&(h-1))
                sum += dist[b][smp[fromTo[b][tmp[!d]]]][smp[fromTo[b][tmp[d]]]];
            h ^= y;
        }
    }
    return sum;
}

int main()
{
    fill((int *)dist, (int *)dist+40441401, INT_MAX);
    int n, m, q, a, b, c, aa, bb;
    scanf("%i%i%i", &n, &m, &q);
    while (m--)
    {
        scanf("%i%i%i", &a, &b, &c);
        adj[a].push_back(make_pair(b, c));
    }
    for (int x = 1; x <= n; x++)
        if (dfn[x] == -1)
            SCC(x);
    assert(nn <= 1000);
    for (int x = 1; x <= n; x++)
    {
        for (auto &y : adj[x])
        {
            if (mp[x] != mp[y.first])
            {
                adj2[mp[x]].push_back({mp[y.first], y.second});
                adj2[mp[y.first]].push_back({mp[x], y.second});
                fromTo[mp[x]][mp[y.first]] = x, fromTo[mp[y.first]][mp[x]] = y.first;
            }
        }
    }
    dfs(1, 1, 0);
    for (int x = 1; x <= n; x++)
        bfs(x);
    for (int x = 1; x < spt.size(); x++)
    {
        for (int y = 1; y < nn; y++)
        {
            if (height[y]-height[1] < (1<<x)) continue;
            int cc = spt[x-1][y];
            spt[x][y] = spt[x-1][cc];
            int jmp = jump((1<<(x-1))-1, y);
            wt[0][x][y] = wt[0][x-1][y] + wt[0][x-1][cc] + dist[cc][smp[fromTo[cc][spt[0][cc]]]][smp[fromTo[cc][jmp]]];
            wt[1][x][y] = wt[1][x-1][y] + wt[1][x-1][cc] + dist[cc][smp[fromTo[cc][jmp]]][smp[fromTo[cc][spt[0][cc]]]];
        }
    }
    while (q--)
    {
        scanf("%i%i", &aa, &bb);
        a = mp[aa], b = mp[bb];
        c = lca(a, b);
        long long lcadis = 0;
        if (a != c && b != c)
            lcadis = dist[c][smp[fromTo[c][jump(height[a]-height[c]-1, a)]]][smp[fromTo[c][jump(height[b]-height[c]-1, b)]]];
        if (a == c && b == c)
            lcadis = dist[c][smp[aa]][smp[bb]];
        else
        {
            lcadis += edgeSum(c,a,1) + edgeSum(c,b,0);
            if (a != c)
                lcadis += dist[a][smp[aa]][smp[fromTo[a][spt[0][a]]]];
            else if (b != c)
                lcadis += dist[a][smp[aa]][smp[fromTo[a][jump(height[b]-height[a]-1, b)]]];
            if (b != c)
                lcadis += dist[b][smp[fromTo[b][spt[0][b]]]][smp[bb]];
            else if (a != c)
                lcadis += dist[b][smp[fromTo[b][jump(height[a]-height[b]-1, a)]]][smp[bb]];
        }
        printf("%lli\n", lcadis);
    }
}
