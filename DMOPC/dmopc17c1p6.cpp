#include <bits/stdc++.h>

using namespace std;

const int DEFAULT = 0;

struct node
{
    int st, val, rev;
    node *par;
    node *ch[2];
    node(int v) : st(v), val(v) {}
};

inline int path(node *n) { return (n == NULL ? DEFAULT : n->st); }

inline void pushup(node *n)
{
    n->st = path(n->ch[0]) ^ n->val ^ path(n->ch[1]); 
}

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
    pushup(n);
}

node *findRoot(node *n)
{
    for (access(n); n->ch[0]; n = n->ch[0]);
    access(n);
    return n;
}

void cut(node *n)
{
    if (!n)
        return;
    access(n);
    if (n->ch[0])
    {
        n->ch[0]->par = NULL;
        n->ch[0] = NULL;
    }
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
    pushup(v);
}

node *lca(node *u, node *v)
{
    access(u);
    return access(v);
}

int queryPath(node *u, node *v)
{
    makeRoot(u);
    access(v);
    return v->st;
}

vector<node*> nd(500000);
map<pair<int,int>,int> mp;

int main()
{
    int n, q, a, b, c;
    scanf("%i%i", &n, &q);
    int cur = n+1;
    for (int x = 1; x <= n; x++)
        nd[x] = new node(0);
    for (int x = 1; x < n; x++)
    {
        scanf("%i%i%i", &a, &b, &c);
        if (a > b)
            swap(a, b);
        int ne = cur++;
        nd[ne] = new node(c);
        link(nd[ne], nd[a]);
        link(nd[ne], nd[b]);
        mp[{a, b}] = ne;
    }
    char t;
    while (q--)
    {
        scanf(" %c%i%i", &t, &a, &b);
        if (a > b)
            swap(a, b);
        if (t == 'A')
        {
            scanf("%i", &c);
            int ne = cur++;
            nd[ne] = new node(c);
            link(nd[ne], nd[a]);
            link(nd[ne], nd[b]);
            mp[{a, b}] = ne;
        }
        else if (t == 'R')
        {
            int c = mp[{a, b}];
            cut(nd[c]);
            cut(nd[c]->ch[0]);
            cut(nd[c]->ch[1]);
        }
        else if (t == 'Q')
        {
            if (findRoot(nd[a]) != findRoot(nd[b]))
                printf("-1\n");
            else
                printf("%i\n", queryPath(nd[a], nd[b]));
        }
    }
}

