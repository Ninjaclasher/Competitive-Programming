#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> adj(501);
vector<bool> root(501, true), done(501);

vector<bitset<501>> know(501);

void dfs(int u, int p)
{
    if (done[u])
        return;
    for (auto &x : adj[u])
    {
        dfs(x, u);
        know[u] |= know[x];
    }
    done[u] = true;
}

int main()
{
    int n;
    char c;
    scanf("%i", &n);
    for (int x = 1; x <= n; x++)
    {
        know[x][x] = 1;
        for (int y = 1; y <= n; y++)
        {
            scanf(" %c", &c);
            if (c == '1')
            {
                adj[x].push_back(y);
                root[y] = false;
            }
        }
    }
    for (int x = 1; x <= n; x++)
        if (root[x])
            dfs(x, x);
    int cnt = 0;
    for (int x = 1; x <= n; x++)
        for (int y = x+1; y <= n; y++)
            if (!know[x][y] && !know[y][x])
                cnt++;
    printf("%i\n", cnt);
}

