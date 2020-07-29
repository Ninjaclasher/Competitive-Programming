#include <bits/stdc++.h>

using namespace std;

long long f(long long x)
{
    return x * (x + 1) / 2;
}

int main()
{
    int n, m, r, c;
    scanf("%i%i", &n, &m);
    vector<pair<int,int>> block;
    while (m--)
    {
        scanf("%i%i", &r, &c);
        block.push_back(make_pair(c, n - r + 1));
    }
    block.push_back(make_pair(n + 1, 0));
    sort(block.begin(), block.end());
    int height = block[0].second;
    long long ans = 0;
    for (int x = 1; x < block.size(); x++)
    {
        int diff = block[x].first - block[x - 1].first;
        ans += f(height) - f(max(height - diff, 0));
        height = max(height - diff, block[x].second);
    }
    printf("%lli\n", ans);
}
