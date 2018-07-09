#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> nn (3001);
vector<vector<int>> mm (3002);
vector<pair<int,pair<int,int>>> pp;

int graphBFS (int src, int end, vector<vector<int>> &adj)
{
    vector<int> dist (3001, INT_MAX);
    bitset<3001> vis;
    queue<int> buf;
    dist[src] = 0;
    vis[src] = true;
    buf.push(src);
    while (!buf.empty())
    {
        int u = buf.front();
        vis[u] = false;
        buf.pop();
        for (auto &x : adj[u])
        {
            if (dist[u] + 1 < dist[x])
            {
                dist[x] = dist[u] + 1;
                if (!vis[x])
                {
                    vis[x] = true;
                    buf.push(x);
                }
            }
        }
    }
    return dist[end];
}

int main()
{
    int n, m, xx, yy, rr, nS, nSY = 0, nE, mS, mSY = 0, mE;
    scanf("%i%i", &n, &m);
    for (int x = 0; x < n; x++)
    {
        scanf("%i%i%i", &xx, &yy, &rr);
        pp.push_back(make_pair(rr,make_pair(xx,yy)));
        if (yy > nSY)
            nSY = yy, nS = x;
        else if (rr == 9001)
            nE = x;
    }
    for (int x = 0; x < pp.size(); x++)
    {
        for (int y = 0; y < pp.size(); y++)
        {
            if (x != y)
            {
                if (pow(pp[y].second.first-pp[x].second.first,2)+pow(pp[y].second.second-pp[x].second.second,2) <= pow(pp[x].first,2))
                    nn[x].push_back(y);
            }
        }
    }
    pp.clear();
    for (int x = 0; x < m; x++)
    {
        scanf("%i%i%i", &xx, &yy, &rr);
        pp.push_back(make_pair(rr,make_pair(xx,yy)));
        if (yy > mSY)
            mSY = yy, mS = x;
        else if (rr == 9001)
            mE = x;
    }
    for (int x = 0; x < pp.size(); x++)
    {
        for (int y = 0; y < pp.size(); y++)
        {
            if (x != y)
            {
                if (pow(pp[y].second.first-pp[x].second.first,2)+pow(pp[y].second.second-pp[x].second.second,2) <= pow(pp[x].first,2))
                    mm[x].push_back(y);
            }
        }
    }
    int ne = graphBFS(nS, nE, nn), me = graphBFS(mS, mE, mm);
    if (ne < me)
        printf("We are the champions!\n");
    else if (ne > me)
        printf(":'(\n");
    else
        printf("SUDDEN DEATH\n");
    return 0;
}
