#include <bits/stdc++.h>

using namespace std;

const int MAXN = 10;

vector<set<int>> adj(MAXN);
vector<int> ans, vis(MAXN);

void add(int a, int b)
{
    adj[b].insert(a);
}

int main()
{
    add(1, 7);
    add(1, 4);
    add(2, 1);
    add(3, 4);
    add(3, 5);
    int a, b;
    for (scanf("%i%i", &a, &b); a && b; scanf("%i%i", &a, &b))
        add(a, b);
    while (ans.size() < 7)
    {
        bool t = false;
        for (int x = 1; x <= 7; x++)
        {
            if (adj[x].empty() && !vis[x])
            {
                vis[x] = t = true;
                for (int y = 1; y <= 7; y++)
                {
                    auto it = adj[y].find(x);
                    if (it != adj[y].end())
                        adj[y].erase(it);
                }
                ans.push_back(x);
                break;
            }
        }
        if (!t)
            return 0 * printf("Cannot complete these tasks. Going to bed.\n");
    }
    for (auto &x : ans)
        printf("%i ", x);
}
