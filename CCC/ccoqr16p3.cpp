#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, m, r, c, prev = 0;
    scanf("%i%i", &n, &m);
    long long final = 0;
    vector<pair<int,int>> block;
    while (m--)
    {
        scanf("%i%i", &r, &c);
        block.push_back(make_pair(c,n-r+1));
    }
    sort(block.begin(), block.end());
    for (int x = 1, index = 0; x < n+1; x++)
    {
        while (x == block[index].first)
        {
            prev = max(prev, block[index].second);
            index++;
        }
        if (prev > 0)
        {
            final+=prev;
            prev--;
        }
    }
    printf("%lli", final);
    return 0;
}
