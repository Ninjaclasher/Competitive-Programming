#include <bits/stdc++.h>

using namespace std;

const int MIN_VAL = -600000000;

struct node
{
    int sz, val, sum, bst;
    int rev, lazymod = MIN_VAL;
    int pres, sufs;

    node *ch[2];
    node *par;
};

node *root;

static inline __attribute__((always_inline)) int sz  (node *n){return n ? n->sz  : 0;}
static inline __attribute__((always_inline)) int sum (node *n){return n ? n->sum : 0;}
static inline __attribute__((always_inline)) int bst (node *n){return n ? n->bst : MIN_VAL;}
static inline __attribute__((always_inline)) int pres(node *n){return n ? n->pres: MIN_VAL;}
static inline __attribute__((always_inline)) int sufs(node *n){return n ? n->sufs: MIN_VAL;}


static inline __attribute__((always_inline)) void pushdown(node *n)
{
    if (n->rev)
    {
        swap(n->pres, n->sufs);
        swap(n->ch[0], n->ch[1]);
        for (int x = 0; x < 2; x++)
            if (n->ch[x])
                n->ch[x]->rev ^= 1;
        n->rev = 0;
    }
    if (n->lazymod != MIN_VAL)
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
        n->lazymod = MIN_VAL;
    }
}

static inline __attribute__((always_inline)) int maxx(int a, int b)
{
    return a>b?a:b;
}

static inline __attribute__((always_inline)) void pushup(node *n)
{
    pushdown(n);
    for (int x = 0; x < 2; x++)
        if (n->ch[x])
            pushdown(n->ch[x]);
    n->sz = 1;
    n->sum = n->val;
    if (!n->ch[0])
    {
        n->pres = n->val;
        if (n->ch[1])
        {
            n->sz += n->ch[1]->sz;
            n->sum += n->ch[1]->sum;
            if (n->ch[1]->pres > 0)
                n->pres += n->ch[1]->pres;
            n->sufs = maxx(n->ch[1]->sufs, n->ch[1]->sum + n->val);
        }
        else
            n->sufs = n->bst = n->val;
    }
    else if (!n->ch[1])
    {
        n->sz += n->ch[0]->sz;
        n->sum += n->ch[0]->sum;
        n->pres = maxx(n->ch[0]->pres, n->ch[0]->sum + n->val);
        n->sufs = n->val + maxx(0, n->ch[0]->sufs);
    }
    else
    {
        n->sz += n->ch[0]->sz + n->ch[1]->sz;
        n->sum += n->ch[0]->sum + n->ch[1]->sum;
        n->pres = maxx(n->ch[0]->pres, n->ch[0]->sum + n->val + maxx(0, n->ch[1]->pres));
        n->sufs = maxx(n->ch[1]->sufs, n->ch[1]->sum + n->val + maxx(0, n->ch[0]->sufs));
    }
    n->bst = maxx(
                maxx(
                    maxx(bst(n->ch[0]), bst(n->ch[1])),
                        maxx(0, sufs(n->ch[0]))
                      + n->val
                      + maxx(0, pres(n->ch[1]))
                ),
                maxx(
                    n->sum,
                    maxx(n->pres, n->sufs)
                )
             );
}

static void rotate(node *n, bool b)
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

static inline __attribute__((always_inline)) void splay(node *n)
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
    pushup(n);
    root = n;
}


static inline __attribute__((always_inline)) node *get2(node *n, bool b)
{
    for (pushdown(n); n->ch[b]; n = n->ch[b], pushdown(n));
    return n;
}

static inline __attribute__((always_inline)) void get(node *n, bool b)
{
    splay(get2(n, b));
}

static void split(node *n, int len)
{
    if (!n)
        return;
    pushdown(n);
    int sz0 = sz(n->ch[0]);
    if (sz0 >= len)
        split(n->ch[0], len);
    else if (sz0+1 == len)
        splay(n);
    else
        split(n->ch[1], len-sz0-1);
}

static void run(node *&n, int k, node *p=NULL)
{
    if (!k)
    {
        splay(p);
        return;
    }
    n = new node();
    n->par = p;
    scanf("%i", &n->val);
    run(n->ch[1], k-1, n);
}

char op[13];
int cnt=0;
void FUCKUXIAOWUC1(node *n)
{
    if (!n||cnt>1850000)
        return;
    FUCKUXIAOWUC1(n->ch[0]);
    FUCKUXIAOWUC1(n->ch[1]);
    delete n;
    cnt++;
}

#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;


int main()
{
    int tt;
    scanf("%i", &tt);
    while (tt--)
    {
        int n, m, i, l;
        char t;
        scan(n); scan(m);
        run(root, n);
        while(m--)
        {
            scanf(" %s", op);
            t = op[2];
            if (t != 'X')
            {
                scan(i); scan(l);
                if (!l)
                {
                    if (t == 'T')
                        printf("0\n");
                    continue;
                }
                //INSERT
                if (t == 'S')
                {
                    if (i == root->sz)
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
                {
                    root->ch[0] = NULL, ch0->par = NULL;
                    pushup(root);
                }
        
                split(root, l);
                node *ch1 = root->ch[1];
                if (ch1)
                {
                    root->ch[1] = NULL, ch1->par = NULL;
                    pushup(root);
                }

                switch(t)
                {
                    //DELETE
                    case 'L':
                        FUCKUXIAOWUC1(root);
                        if (!ch1)
                            root = ch0;
                        else
                        {
                            root = ch1;
                            if (ch0)
                            {
                                get(root, 0);
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
                        printf("%i\n", root->sum);
                    break;
                }
                if (ch1)
                {
                    get(root, 1);
                    root->ch[1] = ch1, ch1->par = root;
                    pushup(root);
                }
                if (ch0)
                {
                    get(root, 0);
                    root->ch[0] = ch0, ch0->par = root;
                    pushup(root);
                }
                nxt:; 
            }
            else
                printf("%i\n", root->bst);
        }
    }
}
