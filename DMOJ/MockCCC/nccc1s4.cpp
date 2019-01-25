#include <bits/stdc++.h>

using namespace std;

vector<bool> vis(1005);
vector<set<int>> adj(1005);

int main()
{
    int n, m, k, a, b, c, d, e, f, cc = 0;
    scanf("%i%i%i%i%i",&n,&m,&k,&a,&b);
    vector<pair<int,pair<int,int>>> aa;
    for (int x = 0; x < m; x++)
    {
        scanf("%i%i%i%i", &c, &d, &e, &f);
        aa.push_back(make_pair(e, make_pair(c, d))), aa.push_back(make_pair(f+1, make_pair(-c, d)));
    }
    aa.push_back(make_pair(k, make_pair(0, 0)));
    sort(aa.begin(), aa.end());
    for (int x = 0; x < m*2;)
    {
        fill(vis.begin(), vis.end(), 0);
        int y = x;
        if (aa[x].second.first > 0)
            adj[aa[x].second.first].insert(aa[x].second.second);
        else
            adj[-aa[x].second.first].erase(aa[x].second.second);
        for (x++; x < m*2 && aa[x].first == aa[x-1].first; x++)
            if (aa[x].second.first > 0)
                adj[aa[x].second.first].insert(aa[x].second.second);
            else
                adj[-aa[x].second.first].erase(aa[x].second.second);
        queue<int> buf;
        buf.push(a);
        while (!buf.empty())
        {
            int u = buf.front();
            buf.pop();
            if (u == b)
            {
                cc += aa[x].first - aa[y].first;
                break; 
            }
            for (auto &z : adj[u])
                if (!vis[z])
                    buf.push(z), vis[z] = true;
        }
    }
    printf("%i\n", cc);
}
