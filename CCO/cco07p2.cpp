#include <bits/stdc++.h>

using namespace std;

int main() 
{
    set<vector<int>> aa;
    int n;
    scanf("%i", &n);
    vector<int> a(6);
    while (n--)
    {
        for (auto &x : a)
            scanf("%i", &x);
        sort(a.begin(), a.end());
        if (aa.find(a) != aa.end())
            return 0 * printf("Twin snowflakes found.");
        aa.insert(a);
    }
    printf("No two snowflakes are alike.");
    return 0;
}
