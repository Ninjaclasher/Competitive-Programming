#include <bits/stdc++.h>

using namespace std;

bool editDist(string a, string b)
{
    int c = 0, x = 0, y = 0;
    if (abs((int)(a.length()-b.length())) > 1)
        return false;
    while (x < a.length() && y < b.length())
    {
        if (a[x] != b[y])
        {
            if (c >= 1) return false;
            if (a.length() > b.length()) x++;
            else if (b.length() > a.length()) y++;
            else x++, y++;
            c++;
        }
        else x++, y++;
    }
    if (x < a.length() || y < b.length())
        c++;
    return c == 1;
}

vector<vector<int>> adj(600);
vector<vector<int>> dist(600, vector<int>(600, INT_MAX));

void bfs(int s)
{
    dist[s][s] = 0;
    queue<int> buf;
    buf.push(s);
    while (!buf.empty())
    {
        int u = buf.front();
        buf.pop();
        for (auto &x : adj[u])
            if (dist[s][x] > dist[s][u]+1)
                dist[s][x] = dist[s][u]+1, buf.push(x);
    }
}

int main()
{
    int n, q, a, b;
    scanf("%i", &n);
    vector<string> aa(n+1);
    for (int x = 1; x <= n; x++)
        cin>>aa[x];
    for (int x = 1; x <= n; x++)
        for (int y = x+1; y <= n; y++)
            if (editDist(aa[x], aa[y]))
                adj[x].push_back(y), adj[y].push_back(x);
    for (int x = 1; x <= n; x++)
        bfs(x);
    scanf("%i", &q);
    while (q--)
    {
        scanf("%i%i", &a, &b);
        printf("%i\n", dist[a][b] == INT_MAX ? -1 : dist[a][b]);
    }
}
