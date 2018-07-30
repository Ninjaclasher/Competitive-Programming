#include <bits/stdc++.h>

using namespace std;

struct node
{
    int i, val, rev, stmin, stmax, stsum, lazyinc, lazymod, sz;
    bool lazy = false;
    node *par;
    node *ch[2];
    node(int i, int v) : i(i), stmin(v), stmax(v), stsum(v), val(v), sz(1) {}
};

inline int stmin(node *n) { return (n == NULL ? INT_MAX : n->stmin); }
inline int stmax(node *n) { return (n == NULL ? INT_MIN : n->stmax); }
inline int stsum(node *n) { return (n == NULL ? 0 : n->stsum); }
inline int sz(node *n) { return (n == NULL ? 0 : n->sz); }

inline void pushsz(node *n)
{
    n->sz = sz(n->ch[0]) + 1 + sz(n->ch[1]);
}

inline void pushup(node *n)
{
    n->stmin = min(min(stmin(n->ch[0]), stmin(n->ch[1])), n->val);
    n->stmax = max(max(stmax(n->ch[0]), stmax(n->ch[1])), n->val);
    n->stsum = stsum(n->ch[0]) + stsum(n->ch[1]) + n->val;
}

inline void pushdown(node *n)
{
    if (!n)
        return;
    if (n->rev)
    {
        swap(n->ch[0], n->ch[1]);
        for (int x = 0; x < 2; x++)
            if (n->ch[x])
                n->ch[x]->rev ^= 1;
        n->rev = 0;
    }
    pushsz(n);
    if (n->lazy)
    {
        for (int x = 0; x < 2; x++)
            if (n->ch[x])
                n->ch[x]->lazyinc = 0, n->ch[x]->lazymod = n->lazymod, n->ch[x]->lazy = true;
        n->val = n->lazymod;
        n->stmin = n->stmax = n->lazymod;
        n->stsum = n->sz * n->lazymod;
        n->lazy = false;
    }
    if (n->lazyinc)
    {
        for (int x = 0; x < 2; x++)
            if (n->ch[x])
                n->ch[x]->lazyinc += n->lazyinc;
        n->val += n->lazyinc;
        n->stmin += n->lazyinc;
        n->stmax += n->lazyinc;
        n->stsum += n->sz * n->lazyinc;
    }
    n->lazymod = 0;
    n->lazyinc = 0;
}

inline bool hasPar(node *n) { return n->par && (n->par->ch[0] == n || n->par->ch[1] == n); }

//0 = right, 1 = left
void rotate(node *n, bool b)
{
    node *p = n->par;
    p->ch[!b] = n->ch[b];
    if (n->ch[b])
        n->ch[b]->par = p;
    n->par = p->par;
    if (n->par && hasPar(p))
        n->par->ch[p->par->ch[1] == p] = n;
    p->par = n;
    n->ch[b] = p;
    pushsz(p);
    pushdown(p->ch[0]);
    pushdown(p->ch[1]);
    pushup(p);
}

void splay(node* n)
{
    while (hasPar(n))
    {
        if (hasPar(n->par))
            pushdown(n->par->par);
        pushdown(n->par);
        pushdown(n);
        if (hasPar(n->par))
        {
            bool b = n->par->par->ch[0]==n->par;
            if (n->par->ch[b] == n)
                rotate(n, !b);
            else
                rotate(n->par, b);
            rotate(n, b);
        }
        else
            rotate(n, n->par->ch[0] == n);
    }
    pushsz(n);
    pushdown(n);
    pushdown(n->ch[0]);
    pushdown(n->ch[1]);
    pushup(n);
}

node *access(node *n)
{
    node *lst = NULL;
    for (node *pp = n; pp; lst = pp, pp = pp->par)
    {
        splay(pp);
        pp->ch[1] = lst;
    }
    splay(n);
    return lst;
}

void makeRoot(node *n)
{
    access(n);
    if (n->ch[0])
    {
        n->ch[0]->rev ^= 1;
        n->ch[0] = NULL;
    }
}

node *findRoot(node *n)
{
    for (access(n); n->ch[0]; n = n->ch[0]);
    access(n);
    return n;
}

void cut(node *n)
{
    access(n);
    node *par = n->ch[0];
    if (n->ch[0])
    {
        n->ch[0]->par = NULL;
        n->ch[0] = NULL;
    }
    pushdown(n->ch[1]);
    pushsz(n);
    pushup(n);
}

//in represented tree
//add v as a child of w
//v's depth > w's depth
//v must be root of its tree using the findRoot function
void link(node *v, node *w)
{
    makeRoot(v);
    access(v);
    access(w);
    v->ch[0] = w;
    w->par = v;
    pushsz(v);
    pushdown(v->ch[0]);
    pushdown(v->ch[1]);
    pushup(v);
}

node *lca(node *u, node *v)
{
    access(u);
    return access(v);
}

static inline __attribute__((always_inline)) void preMod(node *u, node *v)
{
    makeRoot(u);
    access(v);
}

int queryMax(node *u, node *v)
{
    preMod(u, v);
    return v->stmax;
}

int queryMin(node *u, node *v)
{
    preMod(u, v);
    return v->stmin;
}

int querySum(node *u, node *v)
{
    preMod(u, v);
    return v->stsum;
}

int main()
{
    int n, m, a, b, c, k, curRoot;
    scanf("%i%i", &n, &m);
    vector<pair<int,int>> ed(n-1);
    vector<node *> nd(100005);
    for (int x = 1; x <= n; x++)
    {
        scanf("%i", &a);
        nd[x] = new node(x, a);
    }
    for (int x = 1; x < n; x++)
    {
        scanf("%i%i", &a, &b);
        link(nd[a], nd[b]);
    }
    scanf("%i", &curRoot);
    while (m--)
    {
        scanf("%i%i", &k, &a);
        if (k)
            scanf("%i", &b);
        switch(k)
        {
            case 0:
                curRoot = a;
            break;
            case 1:
                scanf("%i", &c);
                preMod(nd[a], nd[b]);
                nd[b]->lazymod = c;
                nd[b]->lazy = true;
            break;
            case 2:
                scanf("%i", &c);
                preMod(nd[a], nd[b]);
                nd[b]->lazyinc = c;
            break;
            case 3:
                makeRoot(nd[curRoot]);
                printf("%i\n", queryMin(nd[a], nd[b]));
            break;
            case 4:
                makeRoot(nd[curRoot]);
                printf("%i\n", queryMax(nd[a], nd[b]));
            break;
            case 5:
                makeRoot(nd[curRoot]);
                printf("%i\n", querySum(nd[a], nd[b]));
            break;
            case 6:
            {
                makeRoot(nd[curRoot]);
                int l = lca(nd[a], nd[b])->i;
                if (l == a)
                    continue;
                cut(nd[a]);
                link(nd[a], nd[b]);
            }
            break;
            case 7:
                makeRoot(nd[curRoot]);
                printf("%i\n", lca(nd[a], nd[b])->i);
            break;
        }
    }
}
