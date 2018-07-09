#include <bits/stdc++.h>

using namespace std;

vector<vector<bool>> play(4, vector<bool>(4));


int w = 0, t, c = 0;;

void next(vector<int> poi)
{
    bool pos = false;
    for (int x = 0; x < 4; x++)
    {
        for (int y = 0; y < 4; y++)
        {
            if (x!=y && !play[x][y])
            {
                pos = true;
                play[x][y] = play[y][x] = true;
                poi[x]+=3;
                next(poi);
                poi[x]-=3;
                poi[y]+=3;
                next(poi);
                poi[y]-=3;
                poi[x]++, poi[y]++;
                next(poi);
                poi[x]--, poi[y]--;
                play[x][y] = play[y][x] = false;
                goto fin;     
            }
        }
    }
    fin:;
    if (!pos)
    {
        int poMax=-1, ma=-1;
        for(int x = 0; x < 4; x++)
            if (poi[x] > ma)
                ma = poi[x], poMax = x;
            else if (poi[x]==ma)
                poMax=-100;
        if (poMax == t)
            w++;
    }
}

int main()
{
    int g, a, b, sa, sb;
    scanf("%i%i", &t, &g);
    t--;
    vector<int> point(4,0);
    while(g--)
    {
        scanf("%i%i%i%i", &a, &b, &sa, &sb);
        a--, b--;
        play[a][b]=true;
        play[b][a]=true;
        if (sa > sb)
            point[a]+=3;
        else if (sb > sa)
            point[b]+=3;
        else
            point[a]++, point[b]++;
    }
    next(point);
    printf("%i\n", w);
    return 0;
}
