#include <bits/stdc++.h>

using namespace std;

const int MIN_VAL = -600000000;

struct node
{
    int sz, val, sum, bst;
    int rev, lazymod = INT_MAX;
    int pres;
    int sufs;

    node *ch[2];
    node *par;
};

node *root;

static inline int sz  (node *n){return n ? n->sz  : 0;}
static inline int sum (node *n){return n ? n->sum : 0;}
static inline int bst (node *n){return n ? n->bst : MIN_VAL;}
static inline int pres(node *n){return n ? n->pres: MIN_VAL;}
static inline int sufs(node *n){return n ? n->sufs: MIN_VAL;}

void pushdown(node *n)
{
    assert(n);
    if (n->rev)
    {
        swap(n->pres, n->sufs);
        swap(n->ch[0], n->ch[1]);
        for (int x = 0; x < 2; x++)
            if (n->ch[x])
                n->ch[x]->rev ^= 1;
        n->rev = 0;
    }
    if (n->lazymod != INT_MAX)
    {
        if (n->lazymod < 0)
            n->pres = n->sufs = n->bst = n->lazymod;
        else
            n->pres = n->sufs = n->bst = n->lazymod * n->sz;
        n->val = n->lazymod;
        n->sum = n->lazymod * n->sz;
        for (int x = 0; x < 2; x++)
            if (n->ch[x])
                n->ch[x]->lazymod = n->lazymod;
        n->lazymod = INT_MAX;
    }
}

void pushup(node *n)
{
    assert(n);
    pushdown(n);
    for (int x = 0; x < 2; x++)
        if (n->ch[x])
            pushdown(n->ch[x]);
    n->sz = sz(n->ch[0]) + 1 + sz(n->ch[1]);
    n->sum = sum(n->ch[0]) + n->val + sum(n->ch[1]);
    n->pres = max(pres(n->ch[0]),
                  sum(n->ch[0]) + n->val + max(0, pres(n->ch[1]))
              );
    n->sufs = max(sufs(n->ch[1]),
                  sum(n->ch[1]) + n->val + max(0, sufs(n->ch[0]))
              );
    n->bst = max(
                max(
                    max(bst(n->ch[0]), bst(n->ch[1])),
                        max(0, sufs(n->ch[0]))
                      + n->val
                      + max(0, pres(n->ch[1]))
                ),
                max(
                    n->sum,
                    max(n->pres, n->sufs)
                )
             );
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


node *get2(node *n, bool b)
{
    assert(n);
    for (pushdown(n); n->ch[b]; n = n->ch[b], pushdown(n));
    return n;
}

void get(node *n, bool b)
{
    splay(get2(n, b));
}

void split(node *n, int len)
{
    if (!n)
    {
        assert(len == 0);
        return;
    }
    pushdown(n);
    int sz0 = sz(n->ch[0]);
    if (sz0 >= len)
        split(n->ch[0], len);
    else if (sz0+1 == len)
        splay(n);
    else
        split(n->ch[1], len-sz0-1);
}

void run(node *&n, int k, node *p=NULL)
{
    if (!k)
        return;
    assert(!n);
    n = new node();
    n->par = p;
    scanf("%i", &n->val);
    run(n->ch[1], k-1, n);
    pushup(n);
}

void traverse(node *n)
{
    if (!n)
        return;
//    pushdown(n);
    traverse(n->ch[0]);
    cout<<n->sz<<"\t"<<n->sum<<"\t"<<n->pres<<"\t"<<n->sufs<<"\t"<<n->bst<<"\t"<<n->val<<"\t"<<n->rev<<endl;
    traverse(n->ch[1]);
}

char op[13];

int main()
{
    int n, m, i, l;
    char t;
    scanf("%i%i", &n, &m);
    run(root, n);
    while(m--)
    {
        scanf(" %s", op);
        t = op[2];
        if (t != 'X')
        {
            scanf("%i%i", &i, &l);
            if (!l)
            {
                if (t == 'T')
                    printf("0\n");
                continue;
            }
            //INSERT
            if (t == 'S')
            {
                if (i == sz(root))
                    get(root, 1);
                else if (!i)
                    get(root, 0);
                else
                    split(root, i);
                if (!i)
                    run(root->ch[0], l, root);
                else if (!root->ch[1])
                    run(root->ch[1], l, root);
                else
                {
                    node *tmp = get2(root->ch[1], 0);
                    run(tmp->ch[0], l, tmp);
                    splay(tmp);
                }
                continue;
            }
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

            switch(t)
            {
                //DELETE
                case 'L':
                    //MEMORY LEAK - IDFC
                    if (!ch1)
                        root = ch0;
                    else
                    {
                        root = ch1;
                        if (ch0)
                        {
                            get(root, 0);
                            assert(!root->ch[0]);
                            root->ch[0] = ch0;
                            ch0->par = root;
                        }         
                    }
                    pushup(root);
                    goto nxt;
                break;
                //MAKE-SAME
                case 'K':
                    scanf("%i", &root->lazymod);
                    pushdown(root);
                break;
                //REVERSE
                case 'V':
                    root->rev ^= 1;
                    pushdown(root);
                break;
                //GET-SUM
                case 'T':
                    printf("%i\n", sum(root));
                break;
                default:
                    abort();
            }
            get(root, 1);
            if (ch1)
                root->ch[1] = ch1, ch1->par = root;
            pushup(root);

            get(root, 0);
            if (ch0)
                root->ch[0] = ch0, ch0->par = root;
            pushup(root);
            nxt:; 
        }
        else
            printf("%i\n", root->bst);
    }
}
