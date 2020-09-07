#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, q;
    scanf("%i%i", &n, &q);
    vector<int> arr(n+1);
    vector<pair<int, int>> pre_max(n+2), suf_max(n+2);
    for (int x = 1; x <= n; x++)
        scanf("%i", &arr[x]);
    for (int x = 1; x <= n; x++)
    {
        pre_max[x] = pre_max[x-1];
        if (arr[x] > pre_max[x].first)
            pre_max[x].first = arr[x], pre_max[x].second = 0;
        if (arr[x] == pre_max[x].first)
            pre_max[x].second++;
    }
    for (int x = n; x >= 1; x--)
    {
        suf_max[x] = suf_max[x+1];
        if (arr[x] > suf_max[x].first)
            suf_max[x].first = arr[x], suf_max[x].second = 0;
        if (arr[x] == suf_max[x].first)
            suf_max[x].second++;

    }
    while (q--)
    {
        int a, b;
        scanf("%i%i", &a, &b);
        a--;
        b++;
        if (pre_max[a].first > suf_max[b].first)
            printf("%i %i\n", pre_max[a].first, pre_max[a].second);
        else if (pre_max[a].first < suf_max[b].first)
            printf("%i %i\n", suf_max[b].first, suf_max[b].second);
        else
            printf("%i %i\n", pre_max[a].first, pre_max[a].second + suf_max[b].second);
    }
}
