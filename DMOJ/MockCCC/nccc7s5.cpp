#include <bits/stdc++.h>

using namespace std;

struct point 
{
    int x, y;
    friend bool operator<(point a, point b)
    {
        return a.x < b.x || (a.x == b.x && a.y < b.y);
    }
};

int main()
{
    int n;
    scanf("%i", &n);
    if (n <= 2)
        return 0 * printf("1\n");
    vector<point > arr(n);
    for (auto &x : arr)
    {
        scanf("%i%i", &x.x, &x.y);
        x.x *= 2;
        x.y *= 2;
    }
    sort(arr.begin(), arr.end());
    vector<double> cnt(n);
    vector<int> icnt(n);
    int mi = n;
    for (int x = 0; x < n; x++)
    {
        for (int y = x+1; y < n; y++)
        {
            int midx1 = arr[x].x+arr[y].x>>1;
            int midy1 = arr[x].y+arr[y].y>>1;
            for (int z = 0; z < n; z++)
                icnt[z] = (midy1-arr[z].y)*(midy1-arr[z].y) + (midx1-arr[z].x)*(midx1-arr[z].x);
            sort(icnt.begin(), icnt.end());
            int cc = n;
            for (int z = 0; z < n-1; z++)
                if (icnt[z] == icnt[z+1])
                    cc--;
            mi = min(mi, cc);
            //NOTE: FLIPPED ON PUPROSE
            int mx1 = arr[y].y-arr[x].y;
            int my1 = arr[x].x-arr[y].x;
            double r1 = mx1 ? (double)my1/mx1 : 0;
            for (int a = 0; a < n; a++)
            {
                for (int b = a+1; b < n; b++)
                {
                    int midx2 = arr[a].x+arr[b].x>>1;
                    int midy2 = arr[a].y+arr[b].y>>1;
                    int mx2 = arr[b].y-arr[a].y;
                    int my2 = arr[a].x-arr[b].x;
                    if (mx1*my2 == mx2*my1)
                        continue;
                    double X = 0, Y = 0;
                    double r2 = mx2 ? (double)my2/mx2 : 0;
                    if (mx1 == 0)
                        X = midx1;
                    else if (mx2 == 0)
                        X = midx2;
                    else
                        X = (-r1 * midx1 + midy1 + r2 * midx2 - midy2) / (r2 - r1);
                    if (mx1)
                        Y = r1 * (X - midx1) + midy1;
                    else
                        Y = r2 * (X - midx2) + midy2;
                    for (int z = 0; z < n; z++)
                        cnt[z] = (X-arr[z].x) * (X-arr[z].x) + (Y-arr[z].y) * (Y-arr[z].y);
                    sort(cnt.begin(), cnt.end());
                    int cc = n;
                    for (int z = 0; z < n-1; z++)
                        if (abs(cnt[z+1]-cnt[z]) < 1e-6)
                            cc--;
                    mi = min(mi, cc);
                }
            }
            if (mi == 1)
                return 0 * printf("1\n");
        }
    }
    printf("%i\n", mi);
}
