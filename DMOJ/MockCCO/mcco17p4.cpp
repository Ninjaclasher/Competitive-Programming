#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> adj(200001);
vector<int> ty(200001), ind(200001), ind2(200001);

int main()
{
    int n, m, a, b, c = 0, d = 0, t;
    scanf("%i%i", &n, &m);
    for (int x = 0; x < n; x++)
        scanf("%i", &ty[x]);
    while (m--)
    {
        scanf("%i%i", &a, &b);
        adj[a].push_back(b);
        ind[b]++, ind2[b]++;
    }
    
    vector<queue<int>> buf(2), buf2(2);
    for (int x = 0; x < n; x++)
        if (!ind[x])
            buf[ty[x]].push(x), buf2[ty[x]].push(x);
    t = 1;
    while (!buf[0].empty() || !buf[1].empty())
    {   
        c += buf[t].empty(), t ^= buf[t].empty();
        a = buf[t].front();
        buf[t].pop();
        for (auto &x : adj[a])
        {
            if (ind[x] == 1)
                buf[ty[x]].push(x);
            ind[x]--;
        }
    }
    t = 0;
    while (!buf2[0].empty() || !buf2[1].empty())
    {
        d += buf2[t].empty(), t ^= buf2[t].empty();
        a = buf2[t].front();
        buf2[t].pop();
        for (auto &x : adj[a])
        {
            if (ind2[x] == 1)
                buf2[ty[x]].push(x);
            ind2[x]--;
        }
    }
    printf("%i", min(c,d));
}
