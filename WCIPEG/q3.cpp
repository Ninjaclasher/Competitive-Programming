#include <bits/stdc++.h>

using namespace std;

int main() 
{
    int z, t, a, b;
    scanf("%i", &z);
    vector<vector<int>> aa(z);
    for (auto &x : aa)
        x.resize(z);
    for (auto &x : aa)
    {
        for (auto &y : x)
        {
            scanf("%i", &y);
        }
    }
    scanf("%i", &t);
    while (t--)
    {
        int q = 0;
        scanf("%i%i", &a, &b);
        for (int x = 0; x < z; x++)
        {
            q+=aa[x][b-1];
            q+=aa[a-1][x];
        }
        printf("%i\n", q);
    }
    return 0;
}
