#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> score;
int t, n, k, w;

int next(vector<int> &poi, vector<int> &sum)
{
    for (int x = 1; x <= k; x++)
    {
        for (int y = n-1; y >= 0; y--)
        {
            if (y > n-w)
                score[x][y] = sum[y];
            else
                score[x][y] = max(score[x-1][y+w]+sum[y], score[x][y+1]);
        }
    }
    int ma = 0;
    for (int x = 0; x < n; x++)
        ma = max(ma, score[k][x]);
    return ma;
}

int main()
{
    scanf("%i", &t);
    while (t--)
    {
        scanf("%i%i%i", &n, &k, &w);
        vector<int> poi (n), sum (n,0);
        score.resize(k+1, vector<int>(30001, 0));
        for (int x = 0; x < n; x++)
            scanf("%i", &poi[x]);
        for (int x = 0; x < n; x++)
            for (int y = 0; y < min(n-x,w); y++)
                sum[x] += poi[x+y];
        printf("%i\n", next(poi, sum));
    }   
    return 0;
}
