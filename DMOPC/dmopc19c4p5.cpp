#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;

const int MAXN = 300005;

int arr[MAXN], mp[MAXN];
long long spt[22][MAXN];
int n, m, q;

template <typename T = int>
struct RMQ
{
    RMQ(const vector<T> &arr)
    {
        int LEN = arr.size();
        int LOGN = highest_bit(LEN) + 1;
        for (int x = 0; x < LEN; x++)
            spt[0][x] = arr[x];
        for (int x = 1; x < LOGN; x++)
        {
            int k = 1 << (x - 1);
            for (int y = 0; y < LEN - k; y++)
                spt[x][y] = min(spt[x-1][y], spt[x-1][y+k]);
            for (int y = LEN - k; y < LEN; y++)
                spt[x][y] = spt[x-1][y];
        }
    }
    static int highest_bit(int k)
    {
        return 31 - __builtin_clz(k);
    }
    T query(const int l, const int r) const
    {
        int k = highest_bit(r - l + 1);
        return min(spt[k][l], spt[k][r - (1 << k) + 1]);
    }
};

int nxt[22][MAXN];

int main()
{
    memset(mp, -1, sizeof mp);
    memset(nxt, -1, sizeof nxt);
    scanf("%i%i%i", &n, &m, &q);
    for (int x = 1; x <= n; x++)
        scanf("%i", &arr[x]);
    vector<long long> psa(n);
    psa[0] = arr[1];
    for (int x = 1; x < n; x++)
        psa[x] = psa[x-1] + arr[x+1];
    RMQ<long long> mi(psa);
    int sz1 = 0;
    for (int x = 1; x <= n; x++)
    {
        int l = x+1, r = n;
        while (l <= r)
        {
            int m = l+r>>1;
            if (mi.query(x, m-1) < psa[x-1])
                r = m-1;
            else
                l = m+1;
        }
        nxt[0][x] = l;
    }
    
    nxt[0][n+1] = n+1;
    for (int x = 1; x < 22; x++)
        for (int y = 1; y <= n+1; y++)
            nxt[x][y] = nxt[x-1][nxt[x-1][y]];

    pair<int,int> x;
    while (q--)
    {
        scanf("%i%i", &x.first, &x.second);
        long long DIFF = -(x.first > 1 ? psa[x.first-2] : 0) + m;
        long long ans = psa[x.second-1] + DIFF;
        long long mod = mi.query(x.first-1, x.second-1) + DIFF;
        ans -= min(0LL, mod);
        assert(ans >= 0);
        int l = x.first, r = x.second;
        while (l <= r)
        {
            int m = l+r>>1;
            if (mi.query(x.first-1, m-1) < -DIFF)
                r = m-1;
            else
                l = m+1;
        }
        int y = l;
        int ans2 = (y <= x.second);
        for (int z = 21; z >= 0; z--)
        {
            if (nxt[z][y] <= x.second)
                ans2 += (1 << z), y = nxt[z][y];
        }
        printf("%lli %i\n", ans, ans2);
    }
}
