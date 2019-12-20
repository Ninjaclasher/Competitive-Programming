#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100005;

struct node
{
    vector<long long> arr, psa, idx;
};

node st[MAXN<<2];
vector<long long> diff(MAXN), psa(MAXN), revmp(MAXN);
vector<int> arr(MAXN), used(MAXN);

void build(int l, int r, int v)
{
    if (l == r)
        return;
    int m = l+r>>1;
    st[v].idx.reserve(r-l+1);
    st[v].psa.reserve(r-l+1);
    st[v].idx.push_back(0);
    st[v].psa.push_back(0);
    for (auto &x : st[v].arr)
    {
        if (x <= m)
        {
            st[v<<1].arr.push_back(x);
            st[v].idx.push_back(st[v].idx.empty() ? 0 : st[v].idx.back());
            st[v].psa.push_back(st[v].psa.empty() ? 0 : st[v].psa.back());
        }
        else
        {
            st[v<<1|1].arr.push_back(x);
            st[v].idx.push_back((st[v].idx.empty() ? 0 : st[v].idx.back()) + 1);
            st[v].psa.push_back((st[v].psa.empty() ? 0 : st[v].psa.back()) + revmp[x]);
        }
    }
    build(l, m, v<<1);
    build(m+1, r, v<<1|1);
}

long long query(int l, int r, int v, int li, int ri, int k)
{
    if (l == r)
        return k * revmp[l];
    int lb = st[v].idx[li-1];
    int rb = st[v].idx[ri];
    int m = l+r>>1;
    if (rb - lb >= k)
        return query(m+1, r, v<<1|1, lb+1, rb, k);
    else
        return query(l, m, v<<1, li-lb, ri-rb, k - (rb - lb)) + st[v].psa[ri] - st[v].psa[li-1];
}

int n, k, c = 0;
long long bst = LONG_MAX;

static inline int inv(int i)
{
    return n-i+1;
}

long long solve(int l, int r)
{
    int center = n + 1 >> 1;
    long long ans = psa[r] - psa[l-1];
    if (k == 0)
        return ans;
    int query_l = 0, query_r = 0;

    // [  ][L-R][CENTER][    ]
    // [    ][CENTER][L-R][  ]
    if (r <= center || l > center)
    {
        query_l = l;
        query_r = r;
    }
    // [   ][L][BOTH][  ]
    else if (l < inv(r))
    {
        query_l = l;
        query_r = inv(r) - 1;
    }
    // [  ][BOTH][R][  ]
    else if (r > inv(l))
    {
        query_l = inv(l) + 1;
        query_r = r;
    }
    // [   ][BOTH][   ]
    else
        return ans;

    int used_cnt = min(used[query_r] - used[query_l - 1], k);
    ans += query(1, c, 1, query_l, query_r, used_cnt);

    // very nice edge case
    if (!(n & 1) && ((l == 1 && r == center) || (l == center + 1 && r == n)) && ((k - used_cnt) & 1))
        ans -= bst;
    return ans;
}

int main()
{
    int q;
    scanf("%i%i%i", &n, &k, &q);
    for (int x = 1; x <= n; x++)
        scanf("%i", &arr[x]);
    set<int> xx;
    map<int,int> mp;
    for (int x = 1; x <= n; x++)
    {
        psa[x] = psa[x-1] + arr[x];
        diff[x] = arr[inv(x)] - arr[x];
        bst = min(bst, abs(diff[x]));
        diff[x] = max(0LL, diff[x]);
        used[x] = used[x-1] + (diff[x] > 0);
        xx.insert(diff[x]);
    }
    for (auto &x : xx)
    {
        c++;
        mp[x] = c, revmp[c] = x;
    }
    for (int x = 1; x <= n; x++)
        st[1].arr.push_back(mp[diff[x]]);
    build(1, c, 1);
    while (q--)
    {
        int l, r;
        scanf("%i%i", &l, &r);
        printf("%lli\n", solve(l, r));
    }
}
