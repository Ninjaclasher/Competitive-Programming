#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, m, p = 0;
    unsigned long long totalCost = 0;
    scanf("%i%i", &n, &m);
    vector<int> t (n, 0);
    vector<int> buying (n, 0);
    for (int x = 0; x < n; x++)
        scanf("%i", &t[x]);
    sort(t.begin(), t.end(), greater<int>());
    for (auto &x : t)
    {
        unsigned long long end = 1;
        for (int y = 0 ; y < buying[p]; y++)
            {end *= x; end %= 1000000007;}
        totalCost += end;
        ++buying[p++];
        p %= m;
    }
    printf("%llu\n", totalCost%1000000007);
}
