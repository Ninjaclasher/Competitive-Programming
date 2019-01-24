#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, k, a;
    scanf("%i%i", &n, &k);
    vector<pair<int,int>> arr(n);
    while (k--)
    {
        for (int x = 0; x < n; x++)
        {
            scanf("%i", &a);
            arr[x].first += a;
        }
        for (auto &x : arr)
        {
            int cnt = 1;
            for (auto &y : arr)
                if (y.first > x.first)
                    cnt++;
            x.second = max(x.second, cnt);
        }
    }
    vector<int> ma = {0};
    for (int x = 1; x < n; x++)
    {
        if (arr[x].first > arr[ma[0]].first)
        {
            ma.clear();
            ma.push_back(x);
        }
        else if (arr[x].first == arr[ma[0]].first)
            ma.push_back(x);
    }
    for (auto &x : ma)
        printf("Yodeller %i is the TopYodeller: score %i, worst rank %i\n", x+1, arr[x].first, arr[x].second);
}
