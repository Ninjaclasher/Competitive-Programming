#include <bits/stdc++.h>

using namespace std;

int mmax(vector<queue<int>> &buf, int m)
{
    vector<pair<int,int>> cnt(m);
    for (auto &x : buf)
        cnt[x.front()].first++;
    for (int x = 0; x < m; x++)
        cnt[x].second = -x;
    sort(cnt.rbegin(), cnt.rend());
    return -cnt[0].second;
}

int main()
{
    int n, m, k, a;
    scanf("%i%i%i", &n, &m, &k);
    vector<queue<int>> buf(n);
    --k;
    for (int x = 0; x < n; x++)
    {
        for (int y = 0; y < m; y++)
        {
            scanf("%i", &a);
            --a;
            buf[x].push(a);
        }
    }
    printf("%i\n", 1+mmax(buf, m));
    int mi = INT_MAX;
    for (int x = 0; x < (1<<m); x++)
    {
        if (x>>k&1)
            continue;
        auto cc = buf;
        for (int y = 0; y < n; y++)
        {
            while (x>>cc[y].front()&1)
                cc[y].pop();
        }
        int ret = mmax(cc, m);
        if (ret == k)
            mi = min(mi, __builtin_popcount(x));
    }
    printf("%i\n", mi);
}

