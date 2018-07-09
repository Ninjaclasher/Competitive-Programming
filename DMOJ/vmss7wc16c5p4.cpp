#include <bits/stdc++.h>

using namespace std;

int main() 
{
    int n;
    vector<int> aa (3);
    scanf("%i", &n);
    for (auto &x : aa)
        scanf("%i", &x);
    vector<int> len(n*2, INT_MAX);
    len[0] = 0;
    for (int x = 0; x <= n; x++)
    {
        if (len[x] != INT_MAX)
            for (auto &y : aa)
                len[x+y] = max(len[x+y] == INT_MAX ? 0 : len[x+y], len[x]+1);
    }
    printf("%i", len[n]);
    return 0;
}
