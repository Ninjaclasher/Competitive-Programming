#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, m, h;
    scanf("%i%i%i", &n, &m, &h);
    vector<int> arr(n);
    for (auto &x : arr)
        scanf("%i", &x);
    int ans = 0;
    for (int x = n-2; x >= 0; x--)
    {
        int d = arr[x+1]-arr[x]-h;
        if (d > 0)
        {
            int t = (d+m-1)/m;
            ans += t;
            arr[x] += t*m;
        }
    }
    printf("%i\n", ans);
}
