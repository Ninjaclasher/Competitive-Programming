#include <bits/stdc++.h>

using namespace std;

int main ()
{
    int xx, yy, xxx, yyy, r, b, k, cc, best = 0;
    scanf("%i%i", &xx, &yy);

    vector<vector<int>> diff(xx+1);
    for (auto &x : diff)
        x.resize(yy+1, 0);

    scanf("%i", &k);
    while (k--)
    {
        scanf("%i%i%i%i", &xxx, &yyy, &r, &b);
        yyy--, xxx--;
        for (int j = max (0, xxx - r) ; j <= min (yy - 1, xxx + r) ; j++)
        {
            int dis = static_cast<int>(floor(sqrt (r * r - (xxx - j) * (xxx - j))));
            diff[max (0, yyy-dis)][j] += b;
            diff[min (xx, yyy+dis+1)][j] -= b;
        }
    }
    for (int x = 0 ; x < xx ; x++)
    {
        for (int y = 0 ; y < yy ; y++)
        {
            if (x > 0)
                diff[x][y] += diff[x - 1][y]; 
            if (diff[x][y] == best)
                cc++;
            if (diff[x][y] > best)
            {
                best = diff[x][y];
                cc = 1;
            }
        }
    }
    printf("%i\n%i\n", best, cc);
}
