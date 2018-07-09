#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, q, s, ss, aa;
    char t;
    scanf("%i%i", &n, &s);
    vector<int> dist (n);
    vector<set<pair<int,int>>> can(101);
    for (auto &x : dist)
        scanf("%i", &x);
    while (s--)
    {
        scanf("%i%i", &ss, &aa);
        can[aa].insert(make_pair(dist[ss-1], ss-1));
    }
    scanf("%i", &q);
    while (q--)
    {
        scanf(" %c%i", &t, &aa);
        aa--;
        if (t != 'Q') scanf("%i", &ss);
        switch (t)
        {
            case 'A':
                can[ss].insert(make_pair(dist[aa],aa));
            break;
            case 'S':
                can[ss].erase(make_pair(dist[aa],aa));
            break;
            case 'E':
                for (int x = 0; x < 101; x++)
                    can[x].erase(make_pair(dist[aa],aa));
                dist[aa] = ss;
            break;
            case 'Q':
                printf("%i\n", can[aa+1].empty() ? -1 : (can[aa+1].begin()->second)+1);
            break;
        }
    }
    return 0;
}
