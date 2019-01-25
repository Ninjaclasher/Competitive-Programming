#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1000;

map<string,int> mp;
vector<int> dist(MAXN, INT_MAX);
vector<vector<int>> adj(MAXN);

void bfs(int src)
{
    queue<int> buf;
    buf.push(src);
    dist[src] = 0;
    while (!buf.empty())
    {
        int u = buf.front();
        buf.pop();
        for (auto &x : adj[u])
            if (dist[x] > dist[u]+1)
                dist[x] = dist[u]+1, buf.push(x);
    }
}

vector<string> ss(string &a, char c)
{
    vector<string> ret;
    string tmp;
    for (auto &x : a)
    {
        if (x == c)
        {
            ret.push_back(tmp);
            tmp = "";
        }
        else
            tmp.push_back(x);
    }
    if (!tmp.empty())
        ret.push_back(tmp);
    return ret;
}

int main()
{
    int cc = 3;
    mp["home"] = 1;
    mp["Waterloo GO"] = 2;
    int n, t;
    scanf("%i%i", &n, &t);
    string a;
    for (int x = 1; x <= n; x++)
    {
        do getline(cin, a); while (a.empty());
        mp[a] = cc++;
    }
    while (t--)
    {
        do getline(cin, a); while (a.empty());
        auto ret = ss(a, '-');
        adj[mp[ret[0]]].push_back(mp[ret[1]]);
        adj[mp[ret[1]]].push_back(mp[ret[0]]);
    }
    bfs(1);
    if (dist[2] == INT_MAX)
        return 0 * printf("RIP ACE\n");
    printf("%i\n", dist[2]);
}

