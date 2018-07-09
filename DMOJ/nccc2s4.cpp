#include <bits/stdc++.h>

using namespace std;

struct ed
{
    int first, second;
    friend bool operator<(ed &a, ed &b)
    {
        return a.second < b.second;
    }
};

vector<vector<ed>> adj(50005);
deque<int> go;

bool dfs2(int u, int p, int c)
{
    for (auto &x : adj[u])
        if (x.first != p)
            if (x.second == c || !dfs2(x.first,u,x.second))
                return false;
    return true;
}

bool dfs(int u, int p, int c)
{
    go.push_back(u);
    bool good = true;
    for (int y = 0; y < adj[u].size(); y++)
    {
        auto &x = adj[u][y];
        if (x.first != p)
        {
            if (c == x.second)
            {
                while (go.front() != u)
                    go.pop_front();
                if (!dfs2(u,u,-1))
                {
                    go.pop_front();
                    return false;
                }
                good = false;
            }
            else if (y && x.second == adj[u][y-1].second && (y == 1 || x.second != adj[u][y-2].second))
            {
                while (go.back() != adj[u][y-1].first)
                    go.pop_back();
                go.pop_back();
            }
            else if (!dfs(x.first, u, x.second))
                return false;
        }
    }
    return good;
}

int main()
{
    int n, a, b, c;
    scanf("%i", &n);
    for (int x = 1; x < n; x++)
    {
        scanf("%i%i%i", &a, &b, &c);
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }
    if (n <= 50)
    {
        for (int x = 1; x <= n; x++)
            if (dfs2(x,x,-1))
                go.push_back(x);
    }
    else
    {
        int loc = -1, loc2 = -1;
        for (int x = 1; x <= n; x++)
        {
            sort(adj[x].begin(), adj[x].end());
            if (adj[x].size() == 1)
                (!~loc ? loc : loc2) = x;
        }
        dfs(loc, loc, -1);
        sort(go.begin(), go.end());
        deque<int> cur = go;
        if (~loc2)
        {
            go.clear();
            dfs(loc2, loc2, -1);
            sort(go.begin(), go.end());
        }
        vector<int> good(n);
        auto it = set_intersection(cur.begin(), cur.end(), go.begin(), go.end(), good.begin());
        good.resize(it-good.begin());
        printf("%lu\n", good.size());
        for (auto &x : good)
            printf("%i\n", x);
        return 0;
    }
    printf("%lu\n", go.size());
    for (auto &x : go)
        printf("%i\n", x);
}
