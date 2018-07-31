#include <bits/stdc++.h>

using namespace std;

const int DEFAULT = 0;

struct node
{
    int st, u, val;
    node *par;
    node *ch[2];
    node(int u, int v) : st(1), u(u), val(v) {}
};

inline int path(node *n) { return (n == NULL ? DEFAULT : n->st); }

inline void pushup(node *n) { n->st = path(n->ch[0]) + n->val + path(n->ch[1]); }

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

node *findRoot(node *n)
{
    for (access(n); n->ch[0]; n = n->ch[0]);
    access(n);
    return n;
}

void cut(node *n)
{
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
    access(v);
    access(w);
    v->ch[0] = w;
    w->par = v;
    pushup(v);
}

int queryPath(node *n)
{
    access(n);
    return path(n);
}

node *lca(node *u, node *v)
{
    access(u);
    return access(v);
}

int main()
{
    vector<node*> nd(100005);
    for (int x = 0; x < nd.size(); x++)
        nd[x] = new node(x,1);
    cin.sync_with_stdio(0);
    cin.tie(0);
    string op;
    int a, b, n, q;
    cin>>n>>q;
    while (q--)
    {
        cin>>op>>a;
        if (op.back() != 't')
            cin>>b;
        if (op.back() == 'k')
            link(nd[a], nd[b]);
        else if (op.back() == 't')
            cut(nd[a]);
        else if (op.back() == 'a')
            printf("%i\n", lca(nd[a], nd[b])->u);
        else
            abort();
    }

}

