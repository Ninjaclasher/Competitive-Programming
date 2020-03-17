#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100005;

template <typename T = int>
struct Splay
{
    struct node
    {
        T val;
        int sz, cnt;
        node *par;
        node *ch[2];
    } *root;

    Splay() : root(NULL){}

    inline int sz(node *n) { return n ? n->sz : 0; }
    inline node *par(node *n) { return n ? n->par : 0; }
    node *get(node *n, bool b) { for (; n->ch[b]; n = n->ch[b]); return n; }
    void get_splay(node *&n, bool b) { n = splay(get(n, b)); }
    void mkrt(node *n) { if (n) root = splay(n); }

    inline void attach(node *n, node *p, bool b)
    {
        if (n) n->par = p;
        if (p) p->ch[b] = n;
    }

    inline node *detach(node *n, bool b)
    {
        node *ch = n->ch[b];
        if (n && ch)
            ch->par = n->ch[b] = NULL;
        return ch;
    }

    void traverse(node *n, ostream &os)
    {
        if (!n)
            return;
        traverse(n->ch[0], os);
        for (int x = 0; x < n->cnt; x++)
            os<<n->val<<" ";
        traverse(n->ch[1], os);
    }

    inline void pushup(node *n)
    {
        n->sz = sz(n->ch[0]) + n->cnt + sz(n->ch[1]);
    }

    inline void rotate(node *n, bool b)
    {
        node *p = n->par;
        p->ch[!b] = n->ch[b];
        if (n->ch[b])
            n->ch[b]->par = p;
        n->par = p->par;
        if (n->par && p->par)
            n->par->ch[p->par->ch[1] == p] = n;
        p->par = n;
        n->ch[b] = p;
        pushup(p);
    }

    inline node *splay(node *n)
    {
        while (n->par)
        {
            if (n->par->par)
            {
                bool b = n->par->par->ch[0] == n->par;
                if (n->par->ch[b] == n)
                    rotate(n, !b);
                else
                    rotate(n->par, b);
                rotate(n, b);
            }
            else
                rotate(n, n->par->ch[0] == n);
        }
        pushup(n);
        return n;
    }

    void ins(T v)
    {
        node *n = root, *p = NULL;
        for (;; n = n->ch[v > n->val])
        {
            if (!n)
            {
                n = new node();
                n->val = v;
                if (p)
                    attach(n, p, v > p->val);
            }
            if (n->val == v)
            {
                n->cnt++;
                break;
            }
            p = n;
        }
        mkrt(n);
    }

    void del(T v)
    {
        node *n = root, *p = NULL;
        for (; n; n = n->ch[v > n->val])
        {
            p = n;
            if (v == n->val)
            {
                if (n->cnt > 1)
                {
                    n->cnt--;
                    mkrt(n);
                }
                else
                {
                    mkrt(n);
                    node *ch0 = detach(root, 0), *ch1 = detach(root, 1);
                    delete root;
                    if (!ch0)
                        root = ch1;
                    else
                    {
                        root = ch0;
                        get_splay(root, 1);
                        attach(ch1, root, 1);
                        pushup(root);
                    }
                }
                return;
            }
        }
        mkrt(p);
    }

    T find_by_order(int k)
    {
        node *n = root, *p = NULL;
        while (n)
        {
            p = n;
            if (k <= sz(n->ch[0]))
                n = n->ch[0];
            else if (k <= sz(n->ch[0]) + n->cnt)
            {
                mkrt(n);
                return n->val;
            }
            else
            {
                k -= sz(n->ch[0]) + n->cnt;
                n = n->ch[1];
            }
        }
        mkrt(p);
        return -1;
    }

    int order_by_key(T v)
    {
        node *n = root, *p = NULL;
        while (n)
        {
            p = n;
            if (v < n->val)
                n = n->ch[0];
            else if (v == n->val)
            {
                mkrt(n);
                return sz(root->ch[0]) + 1;
            }
            else
                n = n->ch[1];
        }
        mkrt(p);
        return -1;
    }

    friend ostream& operator<<(ostream &os, Splay &st)
    {
        st.traverse(st.root, os);
        return os;
    }
};

vector<vector<int>> adj(MAXN);
vector<vector<long long>> suf(MAXN);
vector<vector<long long>> pref(MAXN);
long long weights[MAXN], max_sz[MAXN], sum_sz[MAXN], ans[MAXN];
Splay<long long> max_bbst, sum_bbst;

vector<pair<int,int>> queries[2][MAXN];

long long dfs_for_sum(int u, int p)
{
    sum_sz[u] = weights[u];
    for (auto &x : adj[u])
        if (x != p)
            sum_sz[u] += dfs_for_sum(x, u);
    return sum_sz[u];
}

long long dfs_for_max(int u, int p)
{
    suf[u].resize(adj[u].size(), INT_MIN);
    pref[u].resize(adj[u].size(), INT_MIN);
    int _i = 0;
    for (auto &x : adj[u])
    {
        if (x != p)
            pref[u][_i] = suf[u][_i] = dfs_for_max(x, u);
        _i++;
    }
    for (int x = 1; x < _i; x++)
        pref[u][x] = max(pref[u][x], pref[u][x-1]);
    for (int x = _i-2; x >= 0; x--)
        suf[u][x] = max(suf[u][x], suf[u][x+1]);
    return max_sz[u] = max(weights[u], !suf[u].empty() ? suf[u][0] : INT_MIN);
}

void dfs_for_sum_queries(int u, int p)
{
    for (auto &x : queries[0][u])
        ans[x.second] = sum_bbst.find_by_order(x.first);
    sum_bbst.del(sum_sz[u]);
    for (auto &x : adj[u])
    {
        if (x != p)
        {
            sum_bbst.del(sum_sz[x]);
            sum_sz[u] -= sum_sz[x];
            sum_sz[x] += sum_sz[u];
            sum_bbst.ins(sum_sz[u]);
            sum_bbst.ins(sum_sz[x]);
            dfs_for_sum_queries(x, u);
            sum_bbst.del(sum_sz[u]);
            sum_bbst.del(sum_sz[x]);
            sum_sz[x] -= sum_sz[u];
            sum_sz[u] += sum_sz[x];
            sum_bbst.ins(sum_sz[x]);
        }
    }
    sum_bbst.ins(sum_sz[u]);
}

void dfs_for_max_queries(int u, int p)
{
    for (auto &x : queries[1][u])
        ans[x.second] = max_bbst.find_by_order(x.first);
    for (int _i = 0; _i < adj[u].size(); _i++)
    {
        auto &x = adj[u][_i];
        if (x != p)
        {
            long long sz_u = max_sz[u], sz_x = max_sz[x];
            max_bbst.del(max_sz[u]);
            max_bbst.del(max_sz[x]);
            max_sz[x] = max_sz[u];
            max_sz[u] = max(max(u != p ? max_sz[p] : INT_MIN, weights[u]), max(_i ? pref[u][_i-1] : INT_MIN, _i+1 < adj[u].size() ? suf[u][_i+1] : INT_MIN));
            max_bbst.ins(max_sz[u]);
            max_bbst.ins(max_sz[x]);
            dfs_for_max_queries(x, u);
            max_bbst.del(max_sz[u]);
            max_bbst.del(max_sz[x]);
            max_sz[u] = sz_u;
            max_sz[x] = sz_x;
            max_bbst.ins(max_sz[u]);
            max_bbst.ins(max_sz[x]);
        }
    }
}

int main()
{
    int n, q, a, b;
    scanf("%i%i", &n, &q);
    for (int x = 1; x <= n; x++)
        scanf("%lli", &weights[x]);
    for (int x = 1; x < n; x++)
    {
        scanf("%i%i", &a, &b);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for (int x = 0; x < q; x++)
    {
        int t, r, k;
        scanf("%i%i%i", &t, &r, &k);
        queries[t-1][r].push_back({n-k+1, x});
    }
    dfs_for_sum(1, 1);
    dfs_for_max(1, 1);
    for (int x = 1; x <= n; x++)
        sum_bbst.ins(sum_sz[x]), max_bbst.ins(max_sz[x]);
    dfs_for_sum_queries(1, 1);
    dfs_for_max_queries(1, 1);
    for (int x = 0; x < q; x++)
        printf("%lli\n", ans[x]);
}
