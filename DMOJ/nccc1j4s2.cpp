#include <bits/stdc++.h>

using namespace std;

int main() 
{
    int n;
    scanf("%i", &n);
    char t;
    vector<vector<int>> aa(n, vector<int> (n));
    for (auto &x : aa)
    {
        vector<bool> a(n);
        for (auto &y : x)
        {
            scanf(" %c", &t);
            if (t <= '9')
                y = t-'0';
            else
                y = t - 'A' + 10;
            if (a[y])
                return 0 * printf("No\n");
            a[y] = true;
        }
    }
    for (int x = 0; x < n; x++)
    {
        vector<bool> a(n);
        for (int y = 0; y < n; y++)
        {
            if (a[aa[y][x]])
                return 0 * printf("No\n");
            a[aa[y][x]] = true;
        }
    }
    for (int x = 1; x < n; x++)
        if (aa[0][x]^x)
            return 0 * printf("Latin\n");
    printf("Reduced\n");
    return 0;
}
