#include <bits/stdc++.h>

using namespace std;

struct node
{
    int sum, val, rev;
    node *par;
    node *ch[2];
};

static inline int sum(node *n) {return n ? n->sum : 0;}

static inline void pushup(node *n)
{
    n->sum = sum(n->ch[0]) + n->val + sum(n->ch[1]);
}

static inline void pushdown(node *n)
{
    if (n->rev)
    {
        n->rev = 0;
        swap(n->ch[0], n->ch[1]);
        for (int x = 0; x < 2; x++)
            if (n->ch[x])
                n->ch[x]->rev ^= 1;
    }
}

static inline bool hasPar(node *n) {return n->par && (n->par->ch[0] == n || n->par->ch[1] ==n);};

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

void splay(node *n)
{
    while (hasPar(n))
    {
        if (hasPar(n->par))
            pushdown(n->par->par);
        pushdown(n->par);
        pushdown(n);
        if (hasPar(n->par))
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
    pushdown(n);
    pushup(n);
}

node *access(node *n)
{
    node *lst = NULL;
    for (node *p = n; p; lst = p, p = p->par)
    {
        splay(p);
        p->ch[1] = lst;
    }
    splay(n);
    return lst;
}

void mkrt(node *n)
{
    access(n);
    if (n->ch[0])
        n->ch[0]->rev ^= 1, n->ch[0] = NULL;
    pushup(n);
}

node *fdrt(node *n)
{
    for (access(n); n->ch[0]; n = n->ch[0]);
    access(n);
    return n;
}

void cut(node *n)
{
    access(n);
    if (n->ch[0])
        n->ch[0]->par = NULL, n->ch[0] = NULL;
    pushup(n);
}

void link(node *u, node *v)
{
    mkrt(u);
    access(u);
    access(v);
    u->ch[0] = v;
    v->par = u;
    pushup(u);
}

int path(node *u, node *v)
{
    mkrt(u);
    access(v);
    return sum(v);
}

vector<node *> nn(30001);

int main()
{
    int n, q, a, b;
    scanf("%i", &n);
    for (int x = 1; x <= n; x++)
    {
        scanf("%i", &a);
        nn[x] = new node({a, a});
    }
    scanf("%i", &q);
    string t;
    while (q--)
    {
        cin>>t;
        scanf("%i%i", &a, &b);
        if (t[0] == 'b')
        {
            if (fdrt(nn[a]) == fdrt(nn[b]))
                printf("no\n");
            else
            {
                link(nn[a], nn[b]);
                printf("yes\n");
            }
        }
        else if (t[0] == 'p')
        {
            mkrt(nn[a]);
            access(nn[a]);
            nn[a]->val = b;
            pushup(nn[a]);
        }
        else
        {
            if (fdrt(nn[a]) != fdrt(nn[b]))
                printf("impossible\n");
            else
                printf("%i\n", path(nn[a], nn[b]));
        }
    }
}
