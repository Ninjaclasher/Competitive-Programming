#include <bits/stdc++.h>

using namespace std;

const int MAXL = 1000000000;

struct node
{
    node(int l, int r) : l(l), r(r){}
    int l = 0, r = MAXL;
    node *ch[2] = {NULL, NULL};
    long long v = 0;
};

struct node2
{
    node2() : nr(0, MAXL){}
    node2 *ch[2] = {NULL, NULL};
    node nr;
};

node2 *root = new node2();

long long query2(node *n, int li, int ri)
{
    if (!n || ri < n->l || li > n->r)
        return 0;
    else if (n->l >= li && n->r <= ri)
        return n->v;
    return __gcd(query2(n->ch[0], li, ri), query2(n->ch[1], li, ri));
}

long long query1(node2 *n, int l, int r, int lx, int rx, int ly, int ry)
{
    if (!n || rx < l || lx > r)
        return 0;
    else if (l >= lx && r <= rx)
        return query2(&n->nr, ly, ry);
    int m = l+r>>1;
    return __gcd(query1(n->ch[0], l, m, lx, rx, ly, ry), query1(n->ch[1], m+1, r, lx, rx, ly, ry));
}

void update2(node *n, int i, long long v)
{
    int l = n->l, r = n->r;
    int m = l+r>>1;
    if (l == r)
    {
        n->v = v;
        return;
    }
    node *&tmp = n->ch[i > m];
    if (!tmp)
    {
        tmp = new node(i, i);
        tmp->v = v;
    }
    else if (i >= tmp->l && i <= tmp->r)
        update2(tmp, i, v);
    else
    {
        do
        {
            if (i <= m)
                r = m;
            else
                l = m+1;
            m = l+r>>1;
        }
        while ((i <= m) == (tmp->l <= m));
        node *nn = new node(l, r);
        nn->ch[tmp->l > m] = tmp;
        tmp = nn;
        update2(nn, i, v);
    }
    long long vl = 0, vr = 0;
    if (n->ch[0])
        vl = n->ch[0]->v;
    if (n->ch[1])
        vr = n->ch[1]->v;
    n->v = __gcd(vl, vr);
}

void update1(node2 *n, int l, int r, int xx, int yy, long long v)
{
    if (l == r)
        update2(&n->nr, yy, v);
    else
    {
        int m = l+r>>1;
        if (xx <= m)
            r = m;
        else
            l = m+1;
        if (!n->ch[xx > m])
            n->ch[xx > m] = new node2();
        update1(n->ch[xx > m], l, r, xx, yy, v);
        long long vl = 0, vr = 0;
        if (n->ch[0])
            vl = query2(&n->ch[0]->nr, yy, yy);
        if (n->ch[1])
            vr = query2(&n->ch[1]->nr, yy, yy);
        update2(&n->nr, yy, __gcd(vl, vr));
    }
}

void init(int r, int c){}

void update(int xx, int yy, long long v)
{
    update1(root, 0, MAXL, xx, yy, v);
}

long long calculate(int x1, int y1, int x2, int y2)
{
    return query1(root, 0, MAXL, x1, x2, y1, y2);
}

int main()
{
    int R, C, n, t, a, b, c, d;
    long long v;
    scanf("%i%i%i", &R, &C, &n);
    init(R, C);
    while (n--)
    {
        scanf("%i%i%i", &t, &a, &b);
        if (t == 1)
        {
            scanf("%lli", &v);
            update(a, b, v);
        }
        else
        {
            scanf("%i%i", &c, &d);
            printf("%lli\n", calculate(a, b, c, d));
        }
    }
}
