#include <bits/stdc++.h>

using namespace std;

struct node
{
    int val, sz, cnt;
    node *par;
    node *ch[2];
};

static inline int sz(node *n) { return n ? n->sz : 0; };

static inline void pushup(node *n)
{
    n->sz = sz(n->ch[0]) + n->cnt + sz(n->ch[1]);
}

static inline void rotate(node *n, bool b)
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

static inline node *splay(node *n)
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

static inline void insert(node *&n, int v)
{
    for (node *p = n ? n->par : NULL;; p = n, n = n->ch[v > n->val])
    {
        if (!n)
        {
            n = new node();
            n->sz = n->cnt = 1;
            n->val = v;
            n->par = p;
            if (p)
                p->ch[v > p->val] = n;
            n = splay(n);
            break;
        }
        else if (n->val == v)
        {
            n->cnt++;
            n = splay(n);
            break;
        }
    }
}

static inline int query(node *&n, int v)
{
    int ans = 0;
    node *p = NULL;
    while (n)
    {
        p = n;
        if (v > n->val)
            n = n->ch[1];
        else 
        {
            ans += sz(n->ch[1]) + n->cnt;
            if (n->val == v)
                break;
            else
                n = n->ch[0];
        }
    }
    if (n)
        n = splay(n);
    else if (p)
        n = splay(p);
    return ans;
}

const int MAXN = 1005;

node *bit[MAXN][MAXN];

int n;

static inline void update(int i, int j, int v)
{
    for (int x = i; x <= n; x += x&-x)
        for (int y = j; y <= n; y += y&-y)
            insert(bit[x][y], v);
}

static inline int query(int i, int j, int v)
{
    int ans = 0;
    for (int x = i; x; x -= x&-x)
        for (int y = j; y; y -= y&-y)
            ans += query(bit[x][y], v);
    return ans;
}

int main()
{
    int a;
    scanf("%i", &n);
    long long cnt = 0;
    for (int x = 1; x <= n; x++)
    {
        for (int y = 1; y <= n; y++)
        {
            scanf("%i", &a);
            int ret = query(x-1, y-1, a);
            cnt += ret;
            update(x, y, a+ret);
        }
    }
    printf("%lli\n", cnt);
}
