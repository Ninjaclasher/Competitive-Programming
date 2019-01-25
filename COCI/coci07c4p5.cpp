#include <bits/stdc++.h>

using namespace std;

struct node
{
    int ii, val;
};

const int MAXN = 1000005;

node st[MAXN*3];

void update(int l, int r, int v, int i, int ii, int val)
{
    if (l > i || r < i)
        return;
    if (l == r)
    {
        if (st[v].val < val)
            st[v].val = val, st[v].ii = ii;
        return;
    }
    int m = l+r>>1;
    update(l, m, v<<1, i, ii, val);
    update(m+1, r, v<<1|1, i, ii, val);
    if (st[v<<1].val >= st[v<<1|1].val)
        st[v] = st[v<<1];
    else
        st[v] = st[v<<1|1];
}

node query(int l, int r, int v, int li, int ri)
{
    if (l > ri || r < li)
        return node{0, 0};
    if (l >= li && r <= ri)
        return st[v];
    int m = l+r>>1;
    node a = query(l, m, v<<1, li, ri), b = query(m+1, r, v<<1|1, li, ri);
    if (a.val >= b.val)
        return a;
    else
        return b;
}

struct seg
{
    int a, b, i;
    friend bool operator<(seg a, seg b)
    {
        return a.a < b.a || (a.a == b.a && a.b > b.b);
    }
};

int main()
{
    int n;
    scanf("%i", &n);
    vector<seg> arr(n);
    for (int x = 0; x < n; x++)
    {
        scanf("%i%i", &arr[x].a, &arr[x].b);
        arr[x].i = x;
    }
    sort(arr.begin(), arr.end());
    vector<int> par(n+1);
    for (int x = 0; x < n; x++)
    {
        node xx = query(1, 1000000, 1, arr[x].b, 1000000);
        par[x] = xx.val > 0 ? xx.ii : x;
        update(1, 1000000, 1, arr[x].b, x, xx.val+1);
    }
    vector<int> ans;
    int ii = st[1].ii;
    while (par[ii] != ii)
        ans.push_back(ii), ii = par[ii];
    ans.push_back(ii);
    printf("%u\n", ans.size());
    reverse(ans.begin(), ans.end());
    for (auto &x : ans)
        printf("%i %i\n", arr[x].a, arr[x].b);
}
