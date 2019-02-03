#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> adj(1001);
vector<pair<int,int>> group(1001);
vector<vector<int>> connected;

bool BFS(int src)
{
    int p = connected.size();
    vector<int> sz(3);
    sz[1]++;
    group[src] = make_pair(1, p);
    queue<int> buf;
    buf.push(src);
    while (!buf.empty())
    {
        int v = buf.front();
        buf.pop();
        for (auto &x : adj[v])
        {
            if (group[x] == group[v])
                return false;
            if (!group[x].first)
            {
                group[x] = make_pair((group[v].first == 1 ? 2 : 1), p);
                sz[group[x].first]++;
                buf.push(x);
            }
        }
    }
    connected.push_back(sz);
    return true;
}

string toBin (int n, int sz)
{
    string a;
    while (n)
    {
        a += n&1;
        n >>= 1;
    }
    while (a.length() < sz) a += '\0';
    reverse (a.begin(), a.end());
    return a;
}

int main()
{
    int n, m, a, b;
    string tt;
    scanf("%i%i", &n, &m);
    while (m--)
    {
        scanf("%i%i", &a, &b);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for (int x = 1; x <= n; x++)
        if (!group[x].first && !BFS(x))
                {printf("-1"); return 0;}
    for (int x = 0, best = INT_MAX; x < pow(2, connected.size()); x++)
    {
        int a = 0, b = 0;
        string aa = toBin(x, connected.size());
        for (int y = 0; y < connected.size(); y++)
        {
            a += connected[y][(0^(aa[y])) + 1];
            b += connected[y][(1^(aa[y])) + 1];
        }
        if (abs(a-b) < best)
            best = abs(a-b), tt = aa;
        else if (abs(a-b) == best && aa < tt)
            tt = aa;
        if (!best && connected.size() > 29) break;
    }
    for (int x = 1; x <= n; x++)
        printf("%i", ((group[x].first - 1) ^ tt[group[x].second]) + 1);
}
