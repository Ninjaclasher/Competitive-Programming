#include <bits/stdc++.h>

using namespace std;

const int MAXN = 20;

vector<int> dp(1<<MAXN, INT_MAX);
vector<bool> vis(1<<MAXN);

queue<int> buf;

void push(int ne, int v)
{
    if (dp[ne] > v)
    {
        dp[ne] = v;
        if (!vis[ne])
            vis[ne] = true, buf.push(ne);
    }
}

int main()
{
    int n, m, s, l, r, i;
    scanf("%i%i", &n, &m);
    scanf("%i%i%i%i", &s, &l, &r, &i);
    int msk = 0;
    char c;
    for (int x = 0; x < n; x++)
    {
        scanf(" %c", &c);
        msk = (msk<<1) | (c == 'B');
    }
    dp[msk] = 0;
    buf.push(msk);
    while (!buf.empty())
    {
        int mk = buf.front();
        buf.pop();
        vis[mk] = false;
        int v = dp[mk]+s;
        if (v <= m)
        {
            for (int x = 0; x < n; x++)
            {
                int ne = mk ^ (1<<x);
                push(ne, v);
            }
        }
        v = dp[mk]+r;
        if (v <= m)
        {
            int ne = (mk>>1) | ((mk&1)<<(n-1));
            push(ne, v);
        }
        v = dp[mk]+l;
        if (v <= m)
        {
            int b = mk>>(n-1)&1;
            int ne = ((mk<<1) ^ (b<<n)) | b;
            push(ne, v);
        }
        v = dp[mk]+i;
        if (v <= m)
        {
            int ne = mk ^ ((1<<n)-1);
            if (dp[ne] > v)
            {
                dp[ne] = v;
                if (!vis[ne])
                    vis[ne] = true, buf.push(ne);
            }
        }
    }
    int ans = 0;
    for (auto &x : dp)
        if (x <= m)
            ans++;
    printf("%i\n", ans);
}
