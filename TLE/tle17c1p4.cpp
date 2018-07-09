#include <bits/stdc++.h>

using namespace std;

vector<vector<pair<int,int>>> adj;

void BFS(int src, vector<int> &dist)
{
    queue<int> buf;
    vector<bool> vis(1000001);
    buf.push(src);
    dist[src] = 0;
    while (!buf.empty())
    {
        int v = buf.front();
        buf.pop();
        vis[v]=false;
        for (auto &x : adj[v])
        {
            if (dist[v]+x.second < dist[x.first])
            {
                dist[x.first] = dist[v] + x.second; 
                if (!vis[x.first])
                {
                    vis[x.first] = true;
                    buf.push(x.first);
                }
            }
        }
    }
}

int main()
{
    int n, m, a, b, c, d, e, q, f, l;
    scanf("%i%i%i%i", &n, &m, &a, &b);
    adj.resize(n+1);
    vector<pair<pair<int,int>,int>> chan;
    while (m--)
    {
        scanf("%i%i%i", &c, &d, &e);
        adj[c].push_back(make_pair(d, e));
        adj[d].push_back(make_pair(c, e));
        chan.push_back(make_pair(make_pair(c, d), e));
    }
    vector<int> dist1(n+1,INT_MAX), dist2(n+1,INT_MAX);
    BFS(a, dist1);
    BFS(b, dist2);
    scanf("%i", &q);
    while (q--)
    {
        scanf("%i%i", &f, &l);
        if (f == 1)
        {
            if (dist1[l] == dist2[l])
                printf("%i\n", dist1[l]);
            else
                printf("-1\n");
        }
        else
        {
            int aa = chan[l-1].first.first, bb = chan[l-1].first.second, cc = chan[l-1].second;
            if ((dist1[aa] > dist2[aa] && dist1[bb] > dist2[bb]) || (dist1[aa] < dist2[aa] && dist1[bb] < dist2[bb]))
                printf("-1\n");
            else if (dist1[aa]==dist2[aa] || dist1[bb]==dist2[bb])
            {
                if (dist1[aa]==dist2[aa] && dist1[bb]==dist2[bb])
                    printf("%i\n", min(dist1[aa], dist1[bb]));
                else if (dist1[aa]==dist2[aa])
                {
                    if (dist1[aa] < min(dist1[bb],dist2[bb])+cc)
                        printf("%i\n", dist1[aa]);
                    else 
                        printf("-1\n");
                }
                else
                {
                    if (dist1[bb] < min(dist1[aa],dist2[aa])+cc)
                        printf("%i\n", dist1[bb]);
                    else 
                        printf("-1\n");
                }
            }            
            else
            {
                int n1 = min(dist1[aa], dist2[aa]), n2 = min(dist1[bb], dist2[bb]);
                printf("%.1f\n", (cc-abs(n1-n2))/2.0 + max(n1, n2));
            }
        }
    }

    return 0;
}
