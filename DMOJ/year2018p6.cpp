#include <bits/stdc++.h>

using namespace std;

int root = 500;

struct qu
{
    int i, l, r, lca;
    friend bool operator<(qu &a, qu &b)
    {
        return a.l/root < b.l/root || (a.l/root == b.l/root && (a.r < b.r || (a.r == b.r && a.l < b.l)));
    }
};

vector<vector<int>> adj(51000);
vector<qu> que;
vector<int> ans(51000), occur(51000);
vector<int> h(51000), v(51000), st(51000), en(51000), euler(102000);
vector<vector<int>> spt(18, vector<int>(51000));
multiset<int> val, diff;
int n, t = 0;

void dfs(int u, int p)
{
    st[u] = ++t;
    euler[t] = u;
    h[u] = h[p]+1;
    spt[0][u] = p;
    for (auto &x : adj[u])
        if (x ^ p)
            dfs(x, u);
    en[u] = ++t;
    euler[t] = u;
}

void build()
{
    for (int x = 1; x < 17; x++)
        for (int y = 1; y <= n; y++)
            spt[x][y] = spt[x-1][spt[x-1][y]];
}

int lca(int a, int b)
{
    if (h[a] > h[b])
        swap(a, b);
    int d = h[b]-h[a];
    for (int x = 16; x >= 0; x--)
        if (d>>x&1)
            b = spt[x][b];
    if (a == b)
        return a;
    for (int x = 16; x >= 0; x--)
        if (spt[x][a] ^ spt[x][b])
            a = spt[x][a], b = spt[x][b];
    return spt[0][a];
}

void add(int u)
{
    auto it = val.insert(v[u]);
    auto prev = it, next = it;
    ++next;
    if (it != val.begin())
    {
        --prev;
        diff.insert(abs(*prev - *it));
        if (next != val.end())
            diff.erase(diff.find(abs(*prev - *next)));
    }
    if (next != val.end())
        diff.insert(abs(*next - *it));
}

void remove(int u)
{
    auto it = val.find(v[u]);
    auto prev = it, next = it;
    ++next;
    if (it != val.begin())
    {
        --prev;
        diff.erase(diff.find(abs(*prev - *it)));
        if (next != val.end())
            diff.insert(abs(*next - *prev));
    }
    if (next != val.end())
        diff.erase(diff.find(abs(*next - *it)));
    val.erase(it);
}

void check(int u)
{
    occur[u]++;
    if (occur[u]&1) add(u);
    else remove(u);
}

int main()
{
    int q, a, b;
    scanf("%i%i", &n, &q);
    for (int x = 1; x <= n; x++)
        scanf("%i", &v[x]);
    for (int x = 1; x < n; x++)
    {
        scanf("%i%i", &a, &b);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1, 1);
    build();
    for (int x = 0; x < q; x++)
    {
        scanf("%i%i", &a, &b);
        if (st[a] > st[b])
            swap(a, b);
        int c = lca(a, b);
        if (c != a && c != b)
            que.push_back({x, en[a], st[b], c});
        else
            que.push_back({x, st[a], st[b], c});
    }
    sort(que.begin(), que.end());
    int p = -1, l = que[0].l, r = que[0].l;
    for (auto &x : que)
    {
        if (p^x.l/root)
        {
            val.clear(), diff.clear();
            fill(occur.begin(), occur.end(), 0);
            l = r = x.l;
            p = x.l/root;
        }
        for (; l < x.l; l++)
            check(euler[l]);
        for (l--; l >= x.l; l--)
            check(euler[l]);
        for (l++; r <= x.r; r++)
            check(euler[r]);
        if (x.lca != euler[x.l] && x.lca != euler[x.r]) 
            check(x.lca);
        ans[x.i] = *diff.begin();
        if (x.lca != euler[x.l] && x.lca != euler[x.r]) 
            check(x.lca);
    }
    for (int x = 0; x < q; x++)
        printf("%i\n", ans[x]);
}
