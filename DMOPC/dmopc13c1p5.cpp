#include <bits/stdc++.h>

using namespace std;

struct g
{
    long double x, y1, y2;
    friend bool operator<(g &a, g &b)
    {
        return a.x < b.x;
    }
};

long double a = 0, b = 0;
int cnt = 0;

void test(vector<g> &arr, long double m, long double aa)
{
    if (aa < 0)
        aa = 0;
    long double bb = m*100+aa;
    if (bb < 0)
        return;
    int cur = 0;
    for (auto &z : arr)
    {
        long double yy = m * z.x + aa;
        if (z.y1-1e-6 <= yy && yy <= z.y2+1e-6)
            cur++;
    }
    if (cur > cnt)
        cnt = cur, a = aa, b = bb;
    else if (cur == cnt)
    {
        if (aa < a)
            a = aa, b = bb;
        else if (abs(aa-a) < 1e-9)
            b = min(b, bb);
    }
}

int main()
{
    int n;
    scanf("%i", &n);
    vector<g> arr(n);
    for (auto &x : arr)
        scanf("%Lf%Lf%Lf", &x.x, &x.y1, &x.y2);
    sort(arr.begin(), arr.end());
    long double m = 0, aa = 0;
    for (int x = 0; x < n; x++)
    {
        for (int y = x+1; y < n; y++)
        {
            if (arr[x].x == arr[y].x)
                continue;
            long double xd = arr[y].x-arr[x].x;

            m = (arr[y].y1 - arr[x].y1) / xd;
            aa = -m * arr[x].x + arr[x].y1;
            test(arr, m, aa);
            m = (arr[y].y1 - arr[x].y2) / xd;
            aa = -m * arr[x].x + arr[x].y2;
            test(arr, m, aa);
            m = (arr[y].y2 - arr[x].y1) / xd;
            aa = -m * arr[x].x + arr[x].y1;
            test(arr, m, aa);
            m = (arr[y].y2 - arr[x].y2) / xd;
            aa = -m * arr[x].x + arr[x].y2;
            test(arr, m, aa);
        }
    }
    if (cnt == 0)
    {
        cnt = 1;
        b = INT_MAX;
        for (auto &x : arr)
        {
            m = x.y1 / x.x;
            a = 0;
            b = min(b, m * 100);
        }
    }
    printf("%i\n%.10Lf\n%.10Lf\n", cnt, a, b);
}
