#include <bits/stdc++.h>

using namespace std;

const int DEFAULT = 0;

struct node
{
    int st, u, val, rev;
    node *par;
    node *ch[2];
    node(int u, int v) : st(v), u(u), val(v) {}
};

inline int path(node *n) { return (n == NULL ? DEFAULT : n->st); }

inline void pushup(node *n) { n->st = max(max(path(n->ch[0]),n->val),path(n->ch[1])); }

inline void pushdown(node *n)
{
    if (!n->rev)
        return;
    n->rev = 0;
    swap(n->ch[0], n->ch[1]);
    for (int x = 0; x < 2; x++)
        if (n->ch[x])
            n->ch[x]->rev ^= 1;
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
    pushdown(n);
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

node *cut(node *n)
{
    access(n);
    node *par = n->ch[0];
    if (n->ch[0])
    {
        n->ch[0]->par = NULL;
        n->ch[0] = NULL;
    }
    pushup(n);
    return par;
}

//in represented tree
//add v as a child of w
//v's depth > w's depth
//v must be root of its tree using the findRoot function
void link(node *v, node *w)
{
    access(v);
    access(w);
    v->ch[0] = w;
    w->par = v;
    pushup(v);
}

node *lca(node *u, node *v)
{
    access(u);
    return access(v);
}

int queryPath(node *n)
{
    access(n);
    return path(n);
}

int queryPath(node *u, node *v)
{
    node *l = lca(u, v);
    node *par = cut(l);
    int tmp = l->val;
    l->val = 0;
    pushup(l);
    int ret = max(queryPath(u), queryPath(v));
    if (par != NULL)
        link(l, par);
    splay(l);
    l->val = tmp;
    pushup(l);
    return ret;
}

vector<node*> nd(100005);
/*
vector<vector<pair<int,int>>> adj(60000);
void dfs(int u, int p, int w)
{
    nd[u] = new node(u, w);
    if (u ^ p)
        link(nd[u], nd[p]);
    for (auto &x : adj[u])
        if (x.first ^ p)
            dfs(x.first, u, x.second);
}
*/

int main()
{
    for (int x = 0; x < nd.size(); x++)
        nd[x] = new node(x, 0);
    int n, a, b, c, q;
    string op;
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin>>n>>q;
    while (q--)
    {
        cin>>op>>a>>b;
        if (op[0] == 'a')
        {
            makeRoot(nd[a]);
            link(nd[a], nd[b]);
        }
        else if (op[0] == 'r')
        {
            makeRoot(nd[a]);
            cut(nd[b]);
        }
        else if (op[0] == 'c')
        {
            printf("%s\n", findRoot(nd[a]) == findRoot(nd[b]) ? "YES" : "NO");
        }
        else
            abort();
    }
}

