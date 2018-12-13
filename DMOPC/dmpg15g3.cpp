#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> adj(200005);
vector<pair<int,int>> pos; 
vector<bool> vis(200005);
vector<int> sz(200005), ty(200005);
vector<long long> bit(200005);
int n, lk, rk, lc, rc, cur[2];

int dfs(int u, int p)
{
    sz[u] = 1;
    for (auto &x : adj[u])
        if (x ^ p && !vis[x])
            sz[u] += dfs(x, u);
    return sz[u];
}

void dfs2(int u, int p, int cc, int kk)
{
    ty[u] ? kk++ : cc++;
    pos.push_back({kk, cc});
    for (auto &x : adj[u])
        if (x ^ p && !vis[x])
            dfs2(x, u, cc, kk);
}

int centroid(int u, int p, int s)
{
    for (auto &x : adj[u])
        if (x ^ p && !vis[x] && sz[x]*2 > s)
            return centroid(x, u, s);
    return u;
}

void update(int i, long long v)
{
    for (; i < bit.size(); i += i&-i)
        bit[i] += v;
}

long long query(int i)
{
    long long s = 0;
    for (; i > 0; i -= i&-i)
        s += bit[i];
    return s;
}

long long query2(int k, int c)
{
    if (k < 0 || c < 0) return 0;
    long long ans = 0, l = 0;
    for (int r = pos.size()-1; r >= 0; r--)
    {
        for (ans -= (pos[r].first * 2 <= k && pos[r].second * 2 <= c); l < pos.size() && pos[r].first + pos[l].first <= k; l++)
            update(pos[l].second+1, 1);
        ans += query(c-pos[r].second+1);
    }
    for (int x = 0; x < l; x++)
        update(pos[x].second+1, -1);
    return ans;
}

long long solve2(int u, int p, int llk, int rrk, int llc, int rrc)
{
    long long ans = (llk <= 0 && rrk >= 0 && llc <= 0 && rrc >= 0)*2;
    vector<pair<int,int>> aa;
    aa.push_back({0, 0});
    for (auto &x : adj[u])
    {
        if (x ^ p && !vis[x])
        {
            pos.clear();
            dfs2(x, x, 0, 0);
            sort(pos.begin(), pos.end());
            ans -= query2(rrk, rrc) - query2(llk-1, rrc) - query2(rrk, llc-1) + query2(llk-1, llc-1);
            aa.insert(aa.end(), pos.begin(), pos.end());
        }
    }
    pos = aa;
    sort(pos.begin(), pos.end());
    return ans + query2(rrk, rrc) - query2(llk-1, rrc) - query2(rrk, llc-1) + query2(llk-1, llc-1);
}

long long solve(int u)
{
    long long ans = 0;
    dfs(u, u);
    u = centroid(u, u, sz[u]);
    vis[u] = true;
    ans += solve2(u, u, lk-ty[u], rk-ty[u], lc-!ty[u], rc-!ty[u]);
    for (auto &x : adj[u])
        if (!vis[x])
            ans += solve(x);
    return ans;
}

int main()
{
    int a, b;
    char c;
    scanf("%i%i%i%i%i", &n, &lk, &rk, &lc, &rc);
    for (int x = 1; x <= n; x++)
    {
        scanf(" %c", &c);
        ty[x] = (c == 'K');
    }
    for (int x = 1; x < n; x++)
    {
        scanf("%i%i", &a, &b);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    printf("%lli", solve(1)/2);
}
