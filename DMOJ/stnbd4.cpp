#include <bits/stdc++.h>

using namespace std;

int root = 0;

struct qu
{
    int i, l, r;
    friend bool operator<(qu &a, qu &b)
    {
        return a.l/root < b.l/root || (a.l/root == b.l/root && (a.r < b.r || (a.r == b.r && a.l < b.l)));
    }
};

int bit[2][100005];
vector<int> aa(100005);
unordered_map<int, int> mp;

inline void update(int x, int v)
{
    for (int i = x; i < 100005; i += i&-i)
        bit[0][i] += v;
    for (int i = 100004-x; i < 100005; i += i&-i)
        bit[1][i] += v;
}

inline long long query(int i, int d)
{
    long long sum = 0;
    for (; i > 0; i -= i&-i)
        sum += bit[d][i];
    return sum;
}


int main()
{
    int n, q, l, r, p = -1;
    scanf("%i", &n);
    vector<int> vv(n);
    for (int x = 0; x < n; x++)
        scanf("%i", &aa[x]), vv[x] = aa[x];
    sort(vv.begin(), vv.end());
    vv.erase((unique(vv.begin(), vv.end())), vv.end());
    for (int x = 0; x < vv.size(); x++)
        mp[vv[x]] = x+1;
    for (int x = 0; x < n; x++)
        aa[x] = mp[aa[x]];
    scanf("%i", &q);
    vector<qu> qq(q);
    vector<long long> ans(q);
    long long cur = 0;
    for (int x = 0; x < q; x++)
    {
        scanf("%i%i", &qq[x].l, &qq[x].r);
        qq[x].l--, qq[x].r--, qq[x].i = x;
    }
    root = floor(sqrt(n));
    sort(qq.begin(), qq.end());
    l = qq[0].l, r = qq[0].l;
    for (auto &x : qq)
    {
        if (p^x.l/root)
        {
            memset(bit, 0, 800040);
            l = r = x.l;
            p = x.l/root;
            cur = 0;
        }
        for (; l < x.l; l++)
        {
            update(aa[l], -1);
            cur -= query(aa[l]-1, 0);
        }
        for (l--; l >= x.l; l--)
        {
            update(aa[l], 1);
            cur += query(aa[l]-1, 0);
        }
        for (l++; r <= x.r; r++)
        {
            cur += query(100003-aa[r], 1);
            update(aa[r], 1);
        }
        ans[x.i] = cur;
    }
    for (auto &x : ans)
        printf("%lli\n", x);
}
