#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, k;
    scanf("%i%i", &n, &k);
    if ((k<<1) < n)
        return 0 * printf("0\n");
    vector<int> ans(n);
    int cnt = 0;
    for (int x = 0; x < k; x++)
    {
        int cur = 0, tot =0;
        for (int y = x; y < n; y += k) tot++;
        for (int y = x; y < n; y += k)
            ans[y] = (tot-cur) + cnt, cur++;
        cnt += cur;
    }
    for (auto &x : ans)
        printf("%i ", x);
}
