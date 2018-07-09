#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> adj(4, vector<int> (4));
vector<int> par (4);

int find(int a)
{
    if (a != par[a])
        par[a] = find(par[a]);
    return par[a];
}

bool merge(int a, int b)
{
    a = find(a), b = find(b);
    if (a == b) return false;
    par[a] = b;
    return true;
}

int main()
{
    iota(par.begin(), par.end(), 0);
    int m = 0;
    for (auto &x : adj)
    {
        for (auto &y : x)
        {
            scanf("%i", &y);
            m+=y;
        }
    }
    if (m != 6)
    {
        printf("No");
        return 0;
    }
    for (int x = 0; x < 4; x++)
        for (int y = x+1; y < 4; y++)
            if (adj[x][y] && !merge(x, y))
            {printf("No"); return 0;}
    printf("Yes");
}
