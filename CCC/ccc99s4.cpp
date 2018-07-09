#include <bits/stdc++.h>

using namespace std;



int main()
{
    int n;
    scanf("%i", &n);
    while (n--)
    {
        int r, c, pr, pc, kr, kc;
        scanf("%i%i%i%i%i%i", &r, &c, &pr, &pc, &kr, &kc);
        vector<vector<int>> dist(r+1, vector<int>(c+1,INT_MAX));
        queue<pair<int,int>> buf;
        buf.push(make_pair(kr, kc));
        dist[kr][kc] = 0;
        while (!buf.empty())
        {
            int u = buf.front().first, v = buf.front().second;
            buf.pop();
            for (int x = 0; x < 8; x++)
            {
                int aX, aY;
                switch(x)
                {
                    case 0: aX = 2; aY = 1; break;
                    case 1: aX = 2; aY = -1; break;
                    case 2: aX = -2; aY = 1; break;
                    case 3: aX = -2; aY = -1; break;
                    case 4: aX = 1; aY = 2; break;
                    case 5: aX = 1; aY = -2; break;
                    case 6: aX = -1; aY = 2; break;
                    case 7: aX = -1; aY = -2; break;
                }
                if (u+aX > 0 && u+aX <= r && v+aY > 0 && v+aY <= c && dist[u][v]+1 < dist[u+aX][v+aY])
                {
                    dist[u+aX][v+aY] = dist[u][v]+1;
                    buf.push(make_pair(u+aX, v+aY));
                }
            }
        }
        int lo = r-pr-1;
        for (int x = pr+1, m = 1; x < r; x++, m++)
        {
            if (m >= dist[x][pc] && dist[x][pc] >= 0 && (m-dist[x][pc])%2==0)
            {
                printf("Win in %i knight move(s).\n", m);
                goto end;
            }
        }
        for (int x = pr, m = 0; x < r; x++, m++)
        {
            if (x<r && m >= dist[x+1][pc] && dist[x+1][pc] >= 0 && (m-dist[x+1][pc])%2==0)
            {
                printf("Stalemate in %i knight move(s).\n", m);
                goto end;
            }
        }
        printf("Loss in %i knight move(s).\n", lo);
        end:;
    }
    return 0;
}
