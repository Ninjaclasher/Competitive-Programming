#include <bits/stdc++.h>

using namespace std;

struct node
{
    long double val, sum;
    int sz;
    node *ch[2];
    node *par;
};

long double rati;

static node *root;

static inline __attribute__((always_inline)) int sz(node *n)
{
    return n ? n->sz : 0;
}

static inline long double val(node *n)
{
    return n ? n->val : 0.0;
}

static inline long double sum(node *n)
{
    return n ? n->sum : 0.0;
}

static inline void attach(node *n, node *p, bool b)
{
    if (n && p)
        n->par = p, p->ch[b] = n;
}

static inline void upd_sz(node *n)
{
    assert(n);
    n->sz = sz(n->ch[0]) + 1 + sz(n->ch[1]);
}

vector<long double> ratios(100005);

static inline void pushup(node *n)
{
    if (!n)
        return;
    upd_sz(n);
    n->sum = sum(n->ch[0]) + ratios[sz(n->ch[0])] * (n->val + rati * sum(n->ch[1]));
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
    pushup(p);
}

static node *splay(node *n)
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

static inline void attachNew(long double vv)
{
    node *tmp = new node();
    tmp->val = vv;
    if (root->ch[1])
        attach(root->ch[1], tmp, 1);
    pushup(tmp);
    attach(tmp, root, 1);
    pushup(root);
}

static node *get(node *n, bool b)
{
    if (!n)
        return n;
    for (; n->ch[b]; n = n->ch[b]);
    return splay(n);
}

static void split(node *n, long double vv)
{
    while (1)
    {
        if (vv > n->val)
        {
            if (!n->ch[0])
            {
                root = splay(n);
                if (root->ch[0])
                {
                    root = get(root->ch[0], 1);
                    attachNew(vv);
                }
                else
                {
                    node *tmp = new node();
                    tmp->val = vv;
                    pushup(tmp);
                    attach(root, tmp, 1);
                    root = tmp;
                    pushup(root);
                }
                return;
            }
            n = n->ch[0];
        }
        else if (vv < n->val)
        {
            if (!n->ch[1])
            {
                root = splay(n);
                attachNew(vv);
                return;
            }
            n = n->ch[1];
        }
        else
        {
            root = splay(n);
            attachNew(vv);
            return;
        }
    }
}

void traverse(node *n)
{
    if (!n)
        return;
    traverse(n->ch[0]);
    cout<<n<<" "<<n->val<<" "<<endl;
    traverse(n->ch[1]);
}

int main()
{
    vector<long double> maxScore(100005);
    scanf("%Lf", &rati);
    ratios[0] = 1;
    for (int x = 1; x < ratios.size(); x++)
        ratios[x] = ratios[x-1]*rati;
    int n, p;
    long double v;
    scanf("%i", &n);
    while (n--)
    {
        scanf("%i%Lf", &p, &v);
        if (maxScore[p] > 0)
        {
            if (v <= maxScore[p])
                goto nxt;
            while (true)
            {
                if (maxScore[p] > root->val)
                    root = root->ch[0];
                else if (maxScore[p] < root->val)
                    root = root->ch[1];
                else
                    break;
            }
            root = splay(root);
            node *ch0 = root->ch[0];
            node *ch1 = root->ch[1];
            delete root;
            if (!ch0)
            {
                root = ch1;
                if (root)
                    root->par = NULL;
            }
            else
            {
                root = ch0;
                root->par = NULL;
                if (ch1)
                {
                    root = get(root, 1);
                    attach(ch1, root, 1);
                }
            }
            pushup(root);
        }
        maxScore[p] = v;
        if (!root)
        {
            root = new node();
            root->val = v;
            pushup(root);
        }
        else
            split(root, v);
        nxt:;
        printf("%.15Lf\n", root->sum);
//        traverse(root);
//        cout<<"------"<<endl;
    }
}
