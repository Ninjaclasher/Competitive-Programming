#include <bits/stdc++.h>

using namespace std;

const int MAXN = 5010;

long long bit[MAXN][MAXN];

void update(int i, int j, long long v)
{
    for (int x = i; x < MAXN; x += x&-x)
        for (int y = j; y < MAXN; y += y&-y)
            bit[x][y] = max(bit[x][y], v);
}

long long query(int i, int j)
{
    long long ans = 0;
    for (int x = i; x; x -= x&-x)
        for (int y = j; y; y -= y&-y)
            ans = max(ans, bit[x][y]);
    return ans;
}

struct block
{
    int l, w, h, p, i;
    friend bool operator<(block a, block b)
    {
        if (a.l < b.l)
            return true;
        else if (a.l == b.l)
        {
            if (a.w < b.w)
                return true;
            else if (a.w == b.w)
            {
                if (a.h < b.h)
                    return true;
                else if (a.h == b.h)
                    return a.i < b.i;
            }
        }
        return false;
    }
};

int main()
{
    int n;
    scanf("%i", &n);
    vector<block> b(n);
    vector<int> par(n);
    map<long long,int> mp;
    for (int x = 0; x < n; x++)
    {
        scanf("%i%i%i%i", &b[x].l, &b[x].w, &b[x].h, &b[x].p);
        if (b[x].l > b[x].w)
            swap(b[x].l, b[x].w);
        b[x].i = x;
    }
    sort(b.begin(), b.end());
    mp[0] = -1;
    for (int x = 0; x < n; x++)
    {
        long long ret = query(b[x].w, b[x].h);
        par[x] = mp[ret];
        long long v = ret + b[x].p;
        mp[v] = x;
        update(b[x].w, b[x].h, v);
    }
    long long ret = query(MAXN-1, MAXN-1);
    printf("%lli\n", ret);
    vector<int> ans;
    for (int x = mp[ret]; ~x; x = par[x])
        ans.push_back(b[x].i);
    printf("%lu\n", ans.size());
    for (auto &x : ans)
        printf("%i ", x+1);
    printf("\n");
}
