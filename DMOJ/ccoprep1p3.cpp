#include <bits/stdc++.h>

using namespace std;

struct node 
{
    int val, sz;
    node *ch[2];
    node *par;
    node(int i): val(i)
    {
        ch[0] = ch[1] = par = 0;
        sz = 1;
    }
};

vector<int> par(100005), rnk(100005, 1), mp(100005);
vector<node *> root(100005);

inline int size(node *n){ return n ? n->sz : 0; }

void pushup(node *n)
{
    if (!n)
        return;
    for (int x = 0; x < 2; x++)
        if (n->ch[x])
            n->ch[x]->par = n;
    n->sz = size(n->ch[0]) + 1 + size(n->ch[1]);
}

//0 = right, 1 = left
void rotate(node *n, bool b) 
{
    node *p = n->par;
    p->ch[!b] = n->ch[b];
    if (n->ch[b])
        n->ch[b]->par = p;
    n->par = p->par;
    if (n->par)
        n->par->ch[p->par->ch[1] == p] = n;
    p->par = n;
    n->ch[b] = p;
    pushup(p);
}

node* splay(node* n)
{
    while (n->par)
    {
        if (n->par->par)
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
    return n;
}

void insert(int x, node* n, int i, node *p = 0)
{
    if (!n)
    {
        n = new node(i);
        if (p)
            p->ch[i > p->val] = n;
        pushup(p);
        root[x] = splay(n);
    }
    else if (n->val != i)
        insert(x, n->ch[i > n->val], i, n);
}

int nth(int x, node *n, int i)
{
    if (i <= size(n->ch[0]))
        return nth(x, n->ch[0], i);
    else if (i == size(n->ch[0]) + 1)
    {
        root[x] = splay(n);
        return n->val;
    }
    else if (size(n) >= i)
        return nth(x, n->ch[1], i-size(n->ch[0]) - 1);
    return 0;
}

int find(int n)
{
    if (n ^ par[n]) par[n] = find(par[n]);
    return par[n];
}

void traverse(node *n, int x)
{
    if (!n)
        return;
    traverse(n->ch[0], x);
    traverse(n->ch[1], x);
    insert(x, root[x], n->val);   
    delete(n);
}

void merge(int a, int b)
{
    a = find(a), b = find(b);
    if (a == b)
        abort();
    if (rnk[a] > rnk[b])
        swap(a, b);
    par[a] = b;
    rnk[b] += rnk[a];
    traverse(root[a], b);
}

int main()
{
    iota(par.begin(), par.end(), 0);
    mp[0] = -1;
    int n, m, q, a, b;
    char t;
    scanf("%i%i", &n, &m);
    for (int x = 1; x <= n; x++)
    {
        scanf("%i", &a);
        mp[a] = x;
        insert(x, root[x], a);
    }
    while (m--)
    {
        scanf("%i%i", &a, &b);
        merge(a, b);
    }
    scanf("%i", &q);
    while (q--)
    {
        scanf(" %c%i%i", &t, &a, &b);
        if (t == 'B')
            merge(a, b);
        else
        {
            a = find(a);
            printf("%i\n", mp[nth(a, root[a], b)]); 
        }
    }
}

