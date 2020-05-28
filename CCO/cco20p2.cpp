#include <bits/stdc++.h>

using namespace std;

const int MAXN = 200005;

vector<int> d(MAXN), a(MAXN);
vector<int> cnt(MAXN);

vector<int> bit(MAXN);

int query(int x)
{
    int ret = 0;
    for(; x > 0; x -= x&-x)
        ret += bit[x];
    return ret;
}

void update(int l, int x)
{
    assert(l > 0);
    for (; l < MAXN; l += l&-l)
        bit[l] += x;
}

void update(int l, int r, int x)
{
    update(l, x);
    update(r+1, -x);
}

vector<vector<int>> pos(MAXN);
vector<bool> killed(MAXN);

int main()
{
    int n;
    scanf("%i", &n);
    for (int x = 1; x <= n; x++)
    {
        scanf("%i", &d[x]);
        a[x] = d[x];
        pos[d[x]].push_back(x);
        cnt[d[x]]++;
    }
    sort(a.begin() + 1, a.begin() + n + 1);
    for (int x = 1; x <= n; x++)
        if (a[x] < x)
            return 0 * printf("-1\n");
    long long ans = 0;
    set<int> cur;
    for (int x = n, act_x = n; x >= 1; x--)
    {
        for (auto &v : pos[x])
            cur.insert(v);
        if (d[act_x] < x)
        {
            auto it = prev(cur.end());
            while (*it + query(*it) > x)
                it = prev(cur.erase(it));
            ans += x - *it - query(*it);
            update(*it, n, -1);
            killed[*it] = 1;
            cur.erase(it);
        }
        else
        {
            act_x--;
            while (killed[act_x])
                act_x--;
        }
    }
    printf("%lli\n", ans);
}
