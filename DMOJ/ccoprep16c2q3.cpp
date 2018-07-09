#include <bits/stdc++.h>

using namespace std;

struct node
{
    int sz;
    node *par;
    node *ch[2];
    node() : sz(1) {}
};

inline int size(node *n) { return (n == NULL ? 0 : n->sz); }

inline void pushup(node *n) { n->sz = size(n->ch[0]) + 1 + size(n->ch[1]); }

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

void access(node *n)
{
    for (node *lst = NULL, *pp = n; pp; lst = pp, pp = pp->par)
    {
        splay(pp);
        pp->ch[1] = lst;
    }
    splay(n);
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
//add v to w
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
    return size(n);
}

int main()
{
    vector<node*> nd(200005);
    vector<int> v(200005);
    for (auto &x : nd)
        x = new node();
    
    int n, t, a, b, q;
    scanf("%i", &n);
    for (int x = 0; x < n; x++)
        scanf("%i", &v[x]);
    for (int x = n-1; x >= 0; x--)
    {
        int ne = min(n, x+v[x]);
        link(findRoot(nd[x]), nd[ne]);
    }
    scanf("%i", &q);
    while (q--)
    {
        scanf("%i%i", &t, &a);
        if (t == 1)
            printf("%i\n", queryPath(nd[a])-1);
        else
        {
            scanf("%i", &b);
            cut(nd[a]);
            link(findRoot(nd[a]), nd[min(n, a+b)]);
        } 
    }
}
