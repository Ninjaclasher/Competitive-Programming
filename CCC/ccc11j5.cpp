#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> adj (10);

int next(int u)
{
    int a = 1;
    for (auto &x : adj[u])
        a *= next(x) +1;
    return a;
}

int main() 
{
    int n, a;
    scanf("%i", &n);
    for (int x = 1; x < n; x++)
    {
        scanf("%i", &a);
        adj[a].push_back(x);
    }
    printf("%i", next(n));
    return 0;
}
