#include <bits/stdc++.h>

using namespace std;

#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

int n, k;

struct node
{
    int maxl = INT_MAX;
    int pref[50], suf[50];
    long long here;
};

const int MAXN = 100010;

long long full;

node st[4*MAXN];
int arr[MAXN];

static inline __attribute__((always_inline)) void pull(int l, int r, int v)
{
    st[v].here = st[v<<1].here | st[v<<1|1].here;
    st[v].maxl = INT_MAX;
    for (int x = 0; x < k; x++)
    {
        st[v].pref[x] = INT_MAX;
        st[v].suf[x] = 0;
        st[v].pref[x] = min(st[v<<1].pref[x], st[v<<1|1].pref[x]);
        st[v].suf[x] = max(st[v<<1].suf[x], st[v<<1|1].suf[x]);
    }
    if (st[v].here == full)
    {
        vector<pair<int,int>> cur(50);
        for (int x = 0; x < k; x++)
        {
            cur[x].first = st[v<<1].suf[x];
            cur[x].second = st[v<<1|1].pref[x];
        }
        sort(cur.rbegin(), cur.rend());
        for (int x = k-2; x >= 0; x--)
            cur[x].second = max(cur[x].second, cur[x+1].second);
        for (int x = 0; x < k-1; x++)
            if (cur[x+1].second != INT_MAX && cur[x].first)
                st[v].maxl = min(st[v].maxl, cur[x+1].second-cur[x].first+1);
        int m = l+r>>1;
        st[v].maxl = min(st[v].maxl, cur[0].second-m);
    }
    st[v].maxl = min(st[v].maxl, min(st[v<<1].maxl, st[v<<1|1].maxl));
}

static inline __attribute__((always_inline)) void reset(int v)
{
    for (int x = 0; x < k; x++)
    {
        st[v].pref[x] = INT_MAX;
        st[v].suf[x] = 0;
    }
}

void build(int l, int r, int v)
{
    if (l == r)
    {
        st[v].here = 1LL<<arr[l];
        reset(v);
        st[v].pref[arr[l]] = st[v].suf[arr[l]] = l;
        return;
    }
    int m = l+r>>1;
    build(l, m, v<<1), build(m+1, r, v<<1|1);
    pull(l, r, v);
}

void update(int l, int r, int v, int i, int val)
{
    if (l > i || r < i)
        return;
    if (l == r)
    {
        st[v].here = 1LL<<val;
        reset(v);
        st[v].pref[val] = st[v].suf[val] = l;
        return;
    }
    int m = l+r>>1;
    update(l, m, v<<1, i, val);
    update(m+1, r, v<<1|1, i, val);
    pull(l, r, v);
}

int main()
{
    int m;
    scan(n); scan(k); scan(m);
    full = (1LL<<k)-1;
    for (int x = 1; x <= n; x++)
    {
        scan(arr[x]);
        --arr[x];
    }
    build(1, n, 1);
    while (m--)
    {
        int t, a, b;
        scan(t);
        if (t == 1)
        {
            scan(a); scan(b);
            update(1, n, 1, a, --b);
        }
        else
            printf("%i\n", st[1].maxl == INT_MAX ? -1 : st[1].maxl);
    }
}
