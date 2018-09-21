#include <bits/stdc++.h>

using namespace std;

struct node
{
    long long val, sum;
    int sz, lazyupd;
    bool lmod = false;
    node *ch[2];
    node *par;
};

static node *root;

static inline __attribute__((always_inline)) int sz(node *n) {return n ? n->sz : 0;};

static inline __attribute__((always_inline)) long long val(node *n) {return n ? n->val : 0;};

static inline __attribute__((always_inline)) long long sum(node *n) {return n ? n->sum : 0;};

static void attach(node *n, node *p, bool b)
{
    if (n && p)
        n->par = p, p->ch[b] = n;
}

static node *get(node *n, bool b)
{
    for (; n->ch[b]; n = n->ch[b]);
    return n;
}

static inline __attribute__((always_inline)) void upd_sz(node *n)
{
    n->sz = sz(n->ch[0]) + 1 + sz(n->ch[1]);
}

static void pushup(node *n)
{
    upd_sz(n);
    n->sum = sum(n->ch[0]) + n->val + sum(n->ch[1]);
}

static void pushdown(node *n)
{
    if (!n)
        return;
    upd_sz(n);
    if (n->lmod)
    {
        for (int x = 0; x < 2; x++)
            if (n->ch[x])
                n->ch[x]->lmod = true, n->ch[x]->lazyupd = 0;
        n->val = n->sum = 0;
        n->lmod = false;
    }
    if (n->lazyupd)
    {
        n->val += n->lazyupd;
        for (int x = 0; x < 2; x++)
            if (n->ch[x])
                n->ch[x]->lazyupd += n->lazyupd;
        n->sum += (long long)n->lazyupd * n->sz;
        n->lazyupd = 0;
    }    
}

static void rotate(node *n, bool b)
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
    pushdown(p->ch[0]);
    pushdown(p->ch[1]);
    pushup(p);
}

static node *splay(node *n)
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
    pushdown(n->ch[0]);
    pushdown(n->ch[1]);
    pushup(n);
    return n;
}

static void insert(node *n, node *p, long long v)
{
    if (!n)
    {
        n = new node({v, v, 1, 0, false});
        attach(n, p, v > val(p));
        root = splay(n);
        return;
    }
    pushdown(n);
    insert(n->ch[v > val(n)], n, v);
}

static node *kth(node *n, int kk)
{
    assert(n);
    assert(n->sz >= kk);
    if (kk <= sz(n->ch[0]))
        return kth(n->ch[0], kk);
    else if (kk == sz(n->ch[0])+1)
        return n;
    else
        return kth(n->ch[1], kk-sz(n->ch[0])-1);
}

int main()
{
    int n, v;
    long long k;
    scanf("%i%lli", &n, &k);
    for (int x = 1; x <= n; x++)
    {
        scanf("%i", &v);
        if(v-1)
        {
            root = splay(kth(root, v-1));
            long long bribe = sum(root->ch[0]) + val(root) + sz(root->ch[0]) + 1;
            if (bribe > k)
            {
                insert(root, root, -1); 
                printf("-1\n");
            }
            else
            {
                node *ch1 = root->ch[1];
                if (ch1)
                {
                    root->ch[1] = NULL;
                    ch1->par = NULL;
                    ch1->lazyupd = 0;
                    ch1->lmod = true;
                    pushdown(ch1);
                }
                root->lazyupd = 1;
                insert(root, root, k-bribe); 
    
                root = splay(get(root, 0));

                assert(!root->ch[0]);
                attach(ch1, root, 0);
                
                pushdown(root->ch[1]);
                pushup(root);
                printf("%lli\n", k-bribe);
            }
        }
        else if (root)
        {
            root = splay(get(root, 1));

            root->lazyupd = 0;
            root->lmod = true;
            pushdown(root);

            assert (!root->ch[1]);
            attach(new node({k, k, 1, 0, false}), root, 1);

            pushdown(root->ch[0]);
            pushup(root);
            printf("%lli\n", k);
        }
        else
        {
            root = new node({k, k, 1, 0, false});
            printf("%lli\n", k);
        }
    }
}
