#include <bits/stdc++.h>
#include "cave.h"

using namespace std;

int COMBINATION(int S[])
{
    int ret = tryCombination(S);
    if (ret == -1)
        ret = 5001;
    return ret;
}

void exploreCave(int n)
{
    int ans[n], vis[n], adj[n];
    memset(vis, 0, sizeof vis);
    for (int x = 0; x < n; x++)
    {
        for (int y = 0; y < n; y++)
            if (!vis[y])
                ans[y] = 1;
        int correctColour = COMBINATION(ans) > x;
        int l = 0, r = n-1;
        while (l <= r)
        {
            int m = l+r>>1;
            for (int i = 0; i < n; i++)
                if (!vis[i])
                    ans[i] = !correctColour;
            for (int i = l; i <= m; i++)
                if (!vis[i])
                    ans[i] = correctColour;
            if (COMBINATION(ans) > x)
                r = m-1;
            else
                l = m+1;
        }
        adj[l] = x;
        vis[l] = 1;
        ans[l] = correctColour;
    }
    answer(ans, adj);
}
