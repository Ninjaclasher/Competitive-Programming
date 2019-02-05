#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1000005;

long long st[MAXN<<2];

int n;

void update(int i, long long val)
{
    st[i += n] = val;
    for (i >>= 1; i; i >>= 1)
        st[i] = max(st[i<<1], st[i<<1|1]);
}

long long query(int l, int r)
{
    long long ret = 0;
    for (l += n, r += n+1; l < r; l >>= 1, r >>= 1)
    {
        if (l&1)
            ret = max(ret, st[l++]);
        if (r&1)
            ret = max(ret, st[--r]);
    }
    return ret;
}

struct box
{
    int w, v, i;
    friend bool operator<(box a, box b)
    {
        return a.w > b.w || (a.w == b.w && a.i > b.i);
    }
};

int main()
{
    scanf("%i", &n);
    vector<box> arr(n);
    for (int x = 0; x < n; x++)
    {
        scanf("%i", &arr[x].w);
        arr[x].i = x+1;
    }
    for (int x = 0; x < n; x++)
        scanf("%i", &arr[x].v);
    sort(arr.begin(), arr.end());
    for (auto &x : arr)
        update(x.i, query(1, x.i) + x.v);
    printf("%lli\n", query(1, n));
}
