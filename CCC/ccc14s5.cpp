#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    scanf("%i", &n);
    vector<int> best (n+1), pbest(n+1), dist(n+1);
    vector<pair<int,int>> pos (n+1);
    vector<pair<int,pair<int,int>>> edge;
    for (int x = 1; x <= n; x++)
        scanf("%i%i", &pos[x].first, &pos[x].second);
    for (int x = 0; x <= n; x++)
        for (int y = x+1; y <= n; y++)
            edge.push_back(make_pair(pow(pos[x].first - pos[y].first, 2) + pow(pos[x].second - pos[y].second, 2), make_pair(x, y)));
    sort(edge.begin(), edge.end());
    for (auto &x : edge)
    {
        int a = x.second.first, b = x.second.second, c = x.first;
        if (c != dist[a]) 
            dist[a] = c, pbest[a] = best[a];
        if (c != dist[b]) 
            dist[b] = c, pbest[b] = best[b];
        if (!a) 
            best[a] = max(best[a], pbest[b]);
        else 
            best[a] = max(best[a], pbest[b] + 1), best[b] = max(best[b], pbest[a] + 1);
    }

    printf("%i", best[0]+1);
}
