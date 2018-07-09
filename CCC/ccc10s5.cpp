#include <bits/stdc++.h>
using namespace std;
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
int dp[105][2505], mp[105], aa[2][105], lr[2][105][2505], mi[2][105], c = 0;
int dfs(int u, int k)
{
    if (dp[u][k] != -1)
        return dp[u][k];
    if (aa[0][u] == -1)
        return dp[u][k] = mp[u]+k;
    for (int c = 0; c < 2; mi[c][u] = max(mi[c][u], k+1), c++)
    {
        for (int y = mi[c][u]; y <= k; y++)
        {
            for (int x = 0; x <= y; x++)
            {
                int v = min(dfs(aa[c][u], y-x), (1+x)*(1+x));
                if (v > lr[c][u][y]) 
                    lr[c][u][y] = v;
                else 
                    break;
            }
        }
    }
    for (int x = 0; x <= k; x++)
        dp[u][k] = max(dp[u][k], lr[0][u][k-x]+lr[1][u][x]);
    return dp[u][k];
}
int read()
{
    int tm = ++c;
    do _ = getchar(); while (_ == ')' || _ == ' ');
    if (_ >= '0' && _ <= '9')
        for(mp[tm] = _-'0'; '0'<=(_=getchar()); mp[tm]=(mp[tm]<<3)+(mp[tm]<<1)+_-'0');
    else
        aa[1][tm] = read(), aa[0][tm] = read();
    return tm;
}

int main()
{
    memset(dp, -1, sizeof(dp)), memset(lr, -1, sizeof(lr)), memset(aa, -1, sizeof(aa));
    int u = read(), k;
    scan(k);
    printf("%i", dfs(u, k));
    return 0;
}
