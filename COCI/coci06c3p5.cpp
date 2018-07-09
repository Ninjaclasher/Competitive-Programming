#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> adj;
vector<int> dist (10001, -1);
bool over = false;

int DFS(int v, int p)
{
    if (dist[v] != -1) return dist[v];
    dist[v] = 0;
    for (auto &x : adj[v])
    {
        if (x != p)
        {
            dist[v] += DFS(x, v);
            if (dist[v] > 1000000000)
            over = true, dist[v] %= 1000000000;
        }
    }
    return dist[v];
}

int main()
{
    int n, m, a, b;
    scanf("%i%i", &n, &m);
    adj.resize(n);
    while (m--)
    {
        scanf("%i%i", &a, &b);
        a--, b--;
        adj[a].push_back(b);
    }
    dist[1] = 1;
    string aa = to_string(DFS(0,0));
    if (over)
    {
        reverse(aa.begin(), aa.end());
        while (aa.length() < 9) aa += '0';
        reverse(aa.begin(), aa.end());
    }
    printf("%s", aa.c_str());
    return 0;
}
