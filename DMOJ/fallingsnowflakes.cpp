#include <bits/stdc++.h>

using namespace std;

const int MAXN = 5000;

int bit[MAXN+5][MAXN+5];

void update(int i, int j, int v)
{
    for (int x = i; x < MAXN; x += x&-x)
        for (int y = j; y < MAXN; y += y&-y)
            bit[x][y] += v;
}

int query(int i, int j)
{
    int sum = 0;
    for (int x = i; x > 0; x -= x&-x)
        for (int y = j; y > 0; y -= y&-y)
            sum += bit[x][y];
    return sum;
}

int query(int a, int b, int c, int d)
{
    return query(c, d) - query(a-1, d) - query(c, b-1) + query(a-1, b-1);
}

struct flake
{
    int x, y, t;
};

struct que
{
    char tt;
    int a, b, c, d, t, i;
    friend bool operator<(que &a, que &b)
    {
        return a.t < b.t;
    }
};

int main()
{
    int n, m, q, r, c, l, d;
    scanf("%i%i%i", &n, &m, &q);
    map<int,vector<flake>> mp;
    while (m--)
    {
        scanf("%i%i%i%i", &r, &c, &l, &d);
        mp[l].push_back({r, c, 1});
        mp[d].push_back({r, c, -1});
    }
    vector<int> ans(q);
    vector<que> qu(q);
    for (int x = 0; x < q; x++)
    {
        auto &a = qu[x];
        scanf(" %c%i%i", &a.tt, &a.a, &a.b);
        if (a.tt == 'V')
            scanf("%i%i", &a.c, &a.d);
        scanf("%i", &a.t);
        a.i = x;
    }
    auto it = mp.begin();
    sort(qu.begin(), qu.end());
    for (auto &x : qu)
    {
        while (it != mp.end() && it->first <= x.t)
        {
            for (auto &y : it->second)
                update(y.x, y.y, y.t);
            ++it;
        }
        if (x.tt == 'R')
            ans[x.i] = query(x.a, 0, x.b, MAXN);
        else if (x.tt == 'C')
            ans[x.i] = query(0, x.a, MAXN, x.b);
        else
            ans[x.i] = query(x.a, 0, x.b, MAXN) + query(0, x.c, MAXN, x.d) - query(x.a, x.c, x.b, x.d);
    }
    for (auto &x : ans)
        printf("%i\n", x);
}
