#include <bits/stdc++.h>

using namespace std;

struct node
{
    int val, sz;
    long long sum;
    node *par;
    node *ch[2];
};

node *root;

static inline int sz(node *n) { return n ? n->sz : 0; };
static inline long long sum(node *n) { return n ? n->sum : 0; };

static inline void pushup(node *n)
{
    n->sz = sz(n->ch[0]) + 1 + sz(n->ch[1]);
    n->sum = sum(n->ch[0]) + n->val + sum(n->ch[1]);
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
    for (node *p = n ? n->par : NULL;; p = n, n = n->ch[v < n->val])
    {
        if (!n)
        {
            n = new node();
            n->sz = 1;
            n->val = v;
            n->par = p;
            if (p)
                p->ch[v < p->val] = n;
            n = splay(n);
            break;
        }
    }
}

node *get(node *n, bool b)
{
    for(; n->ch[b]; n = n->ch[b]);
    return n;
}

static inline void del(node *n, int v)
{
    if (n->val == v)
    {
        root = splay(n);
        node *ch0 = root->ch[0], *ch1 = root->ch[1];
        delete root;
        if (!ch0)
            root = ch1;
        else if (!ch1)
            root = ch0;
        else
        {
            ch0 = splay(get(ch0, 1));
            ch0->ch[1] = ch1;
            ch1->par = ch0;
            root = ch0;
        }
        root->par = NULL;
        pushup(root);
        return;
    }
    del(n->ch[v < n->val], v);
}

int query(node *n, long long v)
{
    if (!v)
        return 0;
    if (!n)
        abort();
    if (v <= sum(n->ch[0]))
        return query(n->ch[0], v);
    else if (sum(n->ch[0]) < v && v <= sum(n->ch[0]) + n->val)
        return sz(n->ch[0]) + 1;
    else
        return sz(n->ch[0]) + 1 + query(n->ch[1], v - sum(n->ch[0]) - n->val);
}

void traverse(node *n)
{
    if (!n)
        return;
    traverse(n->ch[0]);
    cout<<n->val<<" ";
    traverse(n->ch[1]);
}

int main()
{
    int n, d;
    scanf("%i%i", &n, &d);
    vector<int> arr(n);
    for (auto &x : arr)
    {
        scanf("%i", &x);
        insert(root, x);
    }
    printf("%i\n", query(root, sum(root)/2+1));
    while (d--)
    {
        int a, b;
        scanf("%i%i", &a, &b);
        --a;
        del(root, arr[a]);
        arr[a] = b;
        insert(root, arr[a]);
        printf("%i\n", query(root, sum(root)/2+1));
    }
}
