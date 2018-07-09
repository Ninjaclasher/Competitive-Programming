#include <bits/stdc++.h>

using namespace std;
 
int n, m;

bool bpm(vector<vector<bool>> bpGraph, int u, bool seen[], int matchR[])
{
    for (int v = 0; v < m; v++)
    {
        if (bpGraph[u][v] && !seen[v])
        {
            seen[v] = true;
            if (matchR[v] < 0 || bpm(bpGraph, matchR[v], seen, matchR))
            {
                matchR[v] = u;
                return true;
            }
        }
    }
    return false;
}
 
int maxBPM(vector<vector<bool>> bpGraph)
{
    int matchR[m];
    bool seen[m];
    for (int x = 0; x < m; x++)
        matchR[x] = -1;
  
    int result = 0;
    for (int u = 2; u <= n; u++)
    {
        for (int x = 0; x < m; x++)
            seen[x] = 0;
        if (bpm(bpGraph, u, seen, matchR))
            result++;
    }
    return result;
}
 
int main()
{
    int t, tmp;
    scanf("%i%i", &n, &m);
    vector<vector<bool>> interested (n+1);
    for (auto &x : interested)
        x.resize(m, false);
    for (int x = 1; x <= n; x++)
    {
        scanf("%i", &t);
        while (t--)
        {
            scanf("%i", &tmp);
            interested[x][tmp-1] = true;
        }
    }
    int count = 0;
    for (int x = 0; x < m; x++)
        if (!interested[1][x]) for (int y = 0; y < n+1; y++) interested[y][x] = false;
        else count++;
    interested[1].assign(m, false);
    printf("%i\n", count-maxBPM(interested));
    return 0;
}
