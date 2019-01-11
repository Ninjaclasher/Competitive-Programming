#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1<<20;

vector<int> adj(MAXN);
vector<bool> vis(MAXN), done(MAXN);

int ans = 0;
int n, m;

void dfs(int u)
{
    if (done[u])
        return;
    if (vis[u])
    {
        ans++;
        return;
    }
    vis[u] = true;
    dfs(adj[u]);
    done[u] = true;
    vis[u] = false;
}

int gt(int x, int y)
{
    return x*m + y;
}

int main()
{
    scanf("%i%i", &n, &m);
    vector<vector<char>> arr(n, vector<char>(m));
    for (auto &x : arr)
        for (auto &y : x)
            scanf(" %c", &y);
    for (int x = 0; x < n; x++)
    {
        for (int y = 0; y < m; y++)
        {
            switch (arr[x][y])
            {
                case 'N':
                    adj[gt(x, y)] = gt(x-1, y);
                    break;
                case 'E':
                    adj[gt(x, y)] = gt(x, y+1);
                    break;
                case 'S':
                    adj[gt(x, y)] = gt(x+1, y);
                    break;
                case 'W':
                    adj[gt(x, y)] = gt(x, y-1);
                    break;
            }
        }
    }
    for (int x = 0; x < n*m; x++)
        if (!done[x])
            dfs(x);
    printf("%i\n", ans);
}
