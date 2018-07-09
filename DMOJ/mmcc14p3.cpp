#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> adj(5001);
vector<int> buf, pre (5001);
vector<bool> vis (5001), in(5001);
int n, s;

void bfs(int q)
{
    int c = 0;
    pre[q] = q;
    vis[q] = true;
    buf.push_back(q);
    while (c < buf.size())
    {
        int u = buf[c++];
        for (auto &x : adj[u])
            if (!vis[x])
                pre[x] = u, vis[x] = true, buf.push_back(x);
    }
}

bool minD (int d)
{
    int ss = 0;
    fill(vis.begin(), vis.end(), false);
    for (int c = buf.size()-1; c >= 0; c--)
    {
        if (!vis[buf[c]])
        {
            ss++;
            int cur = buf[c];
            for (int dd = 0; dd < d; cur = pre[cur], dd++);
            vis[cur] = true;
            queue<pair<int,int>> bbuf;
            bbuf.push(make_pair(cur, 0));
            while (!bbuf.empty())
            {
                int u = bbuf.front().first, v = bbuf.front().second;
                in[u] = false;
                bbuf.pop();
                if (v < d)
                    for (auto &x : adj[u])
                        if (!in[x]) 
                            in[x] = vis[x] = true, bbuf.push(make_pair(x, v+1));
            }
        }
    }
    return ss <= s;
}

int main()
{
    scanf("%i%i", &n, &s);
    for (int x = 1, a, b; x < n; x++)
    {
        scanf("%i%i", &a, &b);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    bfs(1);
    for (int l = 0; l <= n; l++)
    {
        if (minD(l))
        {
            printf("%i", l);
            return 0;
        }
    }
}
