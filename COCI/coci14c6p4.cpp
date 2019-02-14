#include <bits/stdc++.h>

using namespace std;

int main()
{
    int k, n;
    scanf("%i%i", &n, &k);
    vector<int> arr(n);
    int cc = 1;
    for (int x = 0; x < k; x++)
    {
        int cnt = 0;
        int fi = x;
        while (fi < n)
            fi += k;
        fi -= k;
        for (int y = fi; y >= 0; y -= k)
            arr[y] = cc++, cnt++;
        if (cnt > k)
            return 0 * printf("-1\n");
    }
    for (auto &x : arr)
        printf("%i ", x);
    printf("\n");
}
