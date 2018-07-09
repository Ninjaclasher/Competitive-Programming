#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, c;
    scanf("%i%i", &n, &c);
    vector<int> dist(n+1, INT_MAX);
    vector<int> clubs(c);
    for (int x = 0; x < c; x++)
        scanf("%i", &clubs[x]);
    dist[0] = 0;
    for (int x = 0; x <= n; x++)
    {
        if (dist[x] != INT_MAX)
        {
            for (auto &y : clubs)
                if (x+y<=n && dist[x]+1 < dist[x+y])
                    dist[x+y] = dist[x]+1;
        }
    }
    if (dist[n]==INT_MAX)
        printf("Roberta acknowledges defeat.");
    else
        printf("Roberta wins in %i strokes.", dist[n]);
}
