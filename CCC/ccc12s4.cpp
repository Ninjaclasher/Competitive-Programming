#include <bits/stdc++.h>

using namespace std;

unordered_map<long long, char> dist, vis;

long long hhash(vector<char> &cur)
{
    long long hsh = 0;
    for (int x = 0; x < 7; x++)
        hsh = hsh<<7|cur[x];
    return hsh;
}

int n, a;

int lowest(char stk)
{
    if (!stk)
        return n;
    return __builtin_clz((int)stk)-(32-n);
}

int main()
{
    while (1)
    {
        scanf("%i", &n);
        if (!n)
            return 0;
        dist.clear();
        vis.clear();
        vector<char> cur(7), tp(7);
        for (int x = 0; x < n; x++)
        {
            scanf("%i", &a);
            --a;
            cur[x] |= (1<<(n-1-a));
        }
        long long og = hhash(cur);
        dist[og] = 0;
        queue<vector<char>> buf;
        buf.push(cur);
        fill(cur.begin(), cur.end(), 0);
        for (int x = 0; x < n; x++)
            cur[x] |= (1<<(n-1-x));
        long long fhsh = hhash(cur);
        while (!buf.empty())
        {
            cur = buf.front();
            long long chsh = hhash(cur);
            if (chsh == fhsh)
            {
                printf("%i\n", dist[fhsh]);
                goto nxt;
            }
            buf.pop();
            for (int x = 0; x < n; x++)
                tp[x] = lowest(cur[x]);
            for (int x = 0; x < n; x++)
            {
                for (auto z : {-1, 1})
                {
                    int y = x+z;
                    if (y < 0 || y >= n)
                        continue;
                    if (tp[x] < tp[y])
                    {
                        cur[x] ^= (1<<(n-1-tp[x]));
                        cur[y] ^= (1<<(n-1-tp[x]));
                        long long nhsh = hhash(cur);
                        if ((nhsh ^ og) && !vis[nhsh] && (!dist[nhsh] || dist[nhsh] > dist[chsh]+1))
                        {
                            vis[nhsh] = 1;
                            dist[nhsh] = dist[chsh]+1;
                            buf.push(cur);
                        }
                        cur[x] ^= (1<<(n-1-tp[x]));
                        cur[y] ^= (1<<(n-1-tp[x]));
                    }
                }
            }
        }
        printf("IMPOSSIBLE\n");
nxt:;
    }
}
