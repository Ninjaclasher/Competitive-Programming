#include <bits/stdc++.h>

using namespace std;

vector<vector<vector<int>>> adj(2, vector<vector<int>>(2005));
vector<vector<bitset<2005>>> cc(2, vector<bitset<2005>>(2005));

int main()
{
    int n, m, k, a, b;
    scanf("%i%i%i", &n, &m, &k);
    while (k--)
    {
        scanf("%i%i", &a, &b);
        adj[0][a].push_back(b);
        adj[1][b].push_back(a);
        cc[0][a].set(b);
        cc[1][b].set(a);
    }
    for (int x = 1; x <= n; x++)
    {
        bitset<2005> com;
        for (auto &y : adj[1][x])
            com |= cc[1][y];
        for (int y = 1; y <= n; y++)
            if (com.test(y) && x ^ y)
                if ((cc[0][x] & cc[0][y]).count() > 1)
                    return 0 * printf("NO\n");
    }
    printf("YES\n");
}
