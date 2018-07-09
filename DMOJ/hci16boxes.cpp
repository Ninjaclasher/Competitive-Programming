#include <bits/stdc++.h>

using namespace std;

vector<int> tree(500000), arr(500000);

int update(int s, int e, int v, int i, int c)
{
    if (s > i || e < i)
        return tree[v];
    if (s == e)
        return tree[v] = c;
    int m = s+e>>1;
    return tree[v] = max(update(s, m, v<<1, i, c), update(m+1, e, v<<1|1, i, c));
}

int query(int s, int e, int v, int l, int r)
{
    if (s >= l && e <= r)
        return tree[v];
    if (s > r || e < l)
        return 0;
    int m = s+e>>1;
    return max(query(s, m, v<<1, l, r), query(m+1, e, v<<1|1, l, r));
}

int main()
{
    int n, cc = 0, s = 0, ma = 0;
    scanf("%i", &n);
    vector<pair<int,int>> aa(n);
    vector<int> val(n);
    for (auto &x : aa)
        scanf("%i%i", &x.first, &x.second);
    sort(aa.begin(), aa.end());    
    for (int x = 0; x < n; x++)
    {
        if (aa[x].first ^ cc)
            for (cc = aa[x].first; s < x; s++)
                if (arr[aa[s].second] < val[s])
                    update(1, 100000, 1, aa[s].second, val[s]), arr[aa[s].second] = val[s];
        ma = max(ma, val[x] = query(1, 100000, 1, 1, aa[x].second-1) + 1);
    }
    printf("%i", ma);
}
