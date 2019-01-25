#include <bits/stdc++.h>

using namespace std;

struct node
{
    int sz, pref, suf, sum, val, rev;
    node *par;
    node *ch[2];
};

node *root;

static inline int sz(node *n)  {return n ? n->sz   : 0;}
static inline int pref(node *n){return n ? n->pref : 0;}
static inline int suf(node *n) {return n ? n->suf  : 0;}
static inline int sum(node *n) {return n ? n->sum  : 0;}

void pushdown(node *n)
{
    assert(n);
    if (n->rev)
    {
        n->rev = 0;
        swap(n->pref, n->suf);
        swap(n->ch[0], n->ch[1]);
        for (int x = 0; x < 2; x++)
            if (n->ch[x])
                n->ch[x]->rev ^= 1;
    }
}

void pushup(node *n)
{
    assert(n);
    n->sz = sz(n->ch[0]) + 1 + sz(n->ch[1]);
    n->pref = pref(n->ch[0]);
    if (n->pref == sz(n->ch[0]) && n->val)
        n->pref += 1 + pref(n->ch[1]);
    n->suf = suf(n->ch[1]);
    if (n->suf == sz(n->ch[1]) && n->val)
        n->suf += 1 + suf(n->ch[0]);
    n->sum = max(max(sum(n->ch[0]), sum(n->ch[1])), max(n->pref, n->suf));
    if (n->val)
        n->sum = max(n->sum, suf(n->ch[0]) + 1 + pref(n->ch[1]));
}

void rotate(node *n, bool b)
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

void splay(node *n)
{
    while (n->par)
    {
        if (n->par->par)
            pushdown(n->par->par);
        pushdown(n->par);
        pushdown(n);
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
    pushdown(n);
    pushup(n);
    root = n;
}

void get(node *n, bool b)
{
    for (pushdown(n); n->ch[b]; n = n->ch[b], pushdown(n));
    splay(n);
}

void split(node *n, int len)
{
    if (sz(n) < len)
        abort();
    if (!n)
    {
        assert(len == 0);
        return;
    }
    pushdown(n);
    for (int x = 0; x < 2; x++)
        if (n->ch[x])
            pushdown(n->ch[x]);
    if (sz(n->ch[0]) >= len)
        split(n->ch[0], len);
    else if (sz(n->ch[0])+1 == len)
        splay(n);
    else
        split(n->ch[1], len-sz(n->ch[0])-1);
}

void run(node *&n, int k, node *p=NULL)
{
    if (!k)
        return;
    n = new node();
    n->par = p;
    char a;
    scanf(" %c", &a);
    n->sum = n->pref = n->suf = n->val = (a - '0');
    run(n->ch[1], k-1, n);
    pushup(n);
}

int main()
{
    int n, q, t, i, l;
    scanf("%i%i", &n, &q);
    run(root, n);
    while(q--)
    {
        scanf("%i%i%i", &t, &i, &l);
        ++i;

        split(root, i);
        node *ch0 = root->ch[0];
        if (ch0)
            root->ch[0] = NULL, ch0->par = NULL;
        pushup(root);

        split(root, l);
        node *ch1 = root->ch[1];
        if (ch1)
            root->ch[1] = NULL, ch1->par = NULL;
        pushup(root);

        if (t == 1)
        {
            root->rev ^= 1;
            pushdown(root);
        }
        else
            printf("%i\n", sum(root));

        get(root, 1);
        if (ch1)
            root->ch[1] = ch1, ch1->par = root;
        pushup(root);

        get(root, 0);
        if (ch0)
            root->ch[0] = ch0, ch0->par = root;
        pushup(root);
    }
}
