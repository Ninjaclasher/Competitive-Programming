#include <bits/stdc++.h>

using namespace std;

const int MAXN = 600005;

struct node
{
    long long v;
    int i;
};

vector<node> st(MAXN);
vector<long long> arr(MAXN);

void build(int l, int r, int v)
{
    if (l == r)
    {
        st[v].v = arr[l];
        st[v].i = l;
        return;
    }
    int m = l+r>>1;
    build(l, m, v<<1);
    build(m+1, r, v<<1|1);
    st[v].v = min(st[v<<1].v, st[v<<1|1].v);
    if (st[v<<1].v <= st[v<<1|1].v)
        st[v].i = st[v<<1].i;
    else
        st[v].i = st[v<<1|1].i;
}

int query(int l, int r, int v, int li, int ri, long long val)
{
    if (l > ri || r < li || st[v].v > val)
        return -1;
    if (l == r)
        return st[v].i;
    int m = l+r>>1;
    int a = query(l, m, v<<1, li, ri, val);
    if (!~a)
        return query(m+1, r, v<<1|1, li, ri, val);
    return a;
}

int main()
{
    int n, q;
    scanf("%i%i", &n, &q);
    for (int x = 1; x <= n; x++)
        scanf("%lli", &arr[x]);
    build(1, n, 1);
    while (q--)
    {
        long long v;
        int a, b;
        scanf("%lli%i%i", &v, &a, &b);
        int i = a;
        while(1)
        {
            i = query(1, n, 1, i, b, v);
            if (!~i)
                break;
            v %= arr[i];
            i++;
        }
        printf("%lli\n", v);
    }
}
