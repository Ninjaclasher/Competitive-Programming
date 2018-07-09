#include <bits/stdc++.h>

using namespace std;

struct node
{
    long long v, l;
};

vector<node> st(1000000);

void propagate(int l, int r, int i)
{
    if(!st[i].l)
        return;
    st[i].v += st[i].l;
    if (l ^ r)
        st[i<<1].l += st[i].l, st[i<<1|1].l += st[i].l;
    st[i].l = 0;
}

long long update(int li, int ri, int i, int l, int r, long long v)
{
    propagate(li, ri, i);
    if (li > r || ri < l)
        return st[i].v;
    if (li >= l && ri <= r)
    {
        st[i].l = v;
        propagate(li, ri, i);
        return st[i].v;
    }
    int m = li+ri>>1;
    return st[i].v = max(update(li, m, i<<1, l, r, v), update(m+1, ri, i<<1|1, l, r, v));
}

long long query(int li, int ri, int i, int l, int r)
{
    propagate(li, ri, i);
    if (li > r || ri < l)
        return -1;
    if (li >= l && ri <= r)
        return st[i].v;
    int m = li+ri>>1;
    return max(query(li, m, i<<1, l, r), query(m+1, ri, i<<1|1, l, r));
}


int main()
{
    long long n, k, q, a, b, c;
    scanf("%lli%lli%lli", &n, &k, &q);
    while (q--)
    {
        scanf("%lli%lli%lli", &a, &b, &c);
        if (!a)
            update(0, n, 1, max(0LL, b-k+1), b, c);
        else
            printf("%lli\n", query(0, n, 1, b, c));
    }
}
