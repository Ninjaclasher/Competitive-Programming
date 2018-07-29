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
    n->st = path(n->ch[0]) + n->val + path(n->ch[1]);
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
        lst = pp;
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

int queryPath(node *n)
{
    access(n);
    return path(n);
}

int queryPath(node *u, node *v)
{
    makeRoot(u);
    access(v);
    return v->st;
}

int main()
{
    vector<node *> nd(30001);
    cin.tie(0);
    cin.sync_with_stdio(0);
    int n, a, b, q;
    cin>>n;
    for (int x = 1; x <= n; x++)
    {
        cin>>a;
        nd[x] = new node(a);
    }
    cin>>q;
    string t;
    while (q--)
    {
        cin>>t>>a>>b;
        switch(t[0])
        {
            case 'b':
                if (findRoot(nd[a]) == findRoot(nd[b]))
                    cout<<"no"<<endl;
                else
                {
                    link(nd[a], nd[b]);
                    cout<<"yes"<<endl;
                }
                break;
            case 'p':
                makeRoot(nd[a]);
                nd[a]->val = b;
                pushup(nd[a]);
                break;
            case 'e':
                if (findRoot(nd[a]) != findRoot(nd[b]))
                    cout<<"impossible"<<endl;
                else
                    cout<<queryPath(nd[a], nd[b])<<endl;
                break;
        }
    }
}

