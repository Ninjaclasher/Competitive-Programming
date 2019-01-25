#include <bits/stdc++.h>

using namespace std;

int main()
{
    vector<vector<int>> aa(3, vector<int>(2));
    for (auto &x : aa)
        for (auto &y : x)
            scanf("%i", &y);
    for (int x = 0; x < 3; x++)
        for (int y = 0, f = (x+1)%3, s = (x+2)%3; y < 2; y++)
            for (int z = 0; z < 2; z++)
                for (int a = 0; a < 2; a++)
                    if (aa[f][z] == aa[s][a] && aa[f][!z] + aa[s][!a] == aa[x][y] && aa[f][z] + aa[x][!y] == aa[x][y])
                        return 0 * printf("YES\n");
    return 0 * printf("NO\n");
}
