#include <bits/stdc++.h>

using namespace std;

map<int,int> cnt;
map<int, int> mpp;
queue<int> fre;
vector<bitset<1001>> tree(300005);
vector<int> aa(100010);
int n;

bitset<1001> update(int l, int r, int v, int i)
{
    if (l > r || r < i || l > i)
        return tree[v];
    if (l == r)
    {
        tree[v].reset();
        tree[v].set(mpp[aa[i]]);
        return tree[v];
    }
    int mid = (l+r)/2;
    return tree[v] = update(l, mid, v*2, i) | update(mid+1, r, v*2+1, i);
}

bitset<1001> query(int l, int r, int v, int li, int ri)
{
    if (l > r || r < li || l > ri)
        return bitset<1001>();
    if (l >= li && r <= ri)
        return tree[v];
    int mid = (l+r)/2;
    return query(l, mid, v*2, li, ri) | query(mid+1, r, v*2+1, li, ri);
}

bitset<1001> construct(int l, int r, int v)
{
    if (l == r)
    {
        if (l <= n)
            tree[v].set(mpp[aa[l]]);
        return tree[v];
    }
    int mid = (l+r)/2;
    return tree[v] = construct(l, mid, v*2) | construct(mid+1, r, v*2+1);
}

int main()
{
    int q, t, a = 1, b;
    assert(scanf("%i%i", &n, &q)==2);
    for (int x = 1; x <= n; x++)
    {
        scanf("%i", &aa[x]);
        if (!mpp[aa[x]])
            mpp[aa[x]] = a++;
        if (!cnt[aa[x]])
            cnt[aa[x]] = 0;
        cnt[aa[x]]++;
    }
    construct(1, n, 1);
    for (int x = a; x <= 1000; x++)
        fre.push(x);
    while (q--)
    {
        scanf("%i%i%i", &t, &a, &b);
        if (t == 1)
        {
            cnt[aa[a]]--;
            if (!cnt[aa[a]])
                fre.push(mpp[aa[a]]), mpp.erase(aa[a]), cnt.erase(aa[a]);
            if (!mpp[b])
                mpp[b] = fre.front(), fre.pop();
            if (!cnt[b])
                cnt[b] = 0;
            cnt[b]++;
            aa[a] = b;
            update(1, n, 1, a);
        }
        else
            printf("%i\n", query(1, n, 1, a, b).count());
    }
}
