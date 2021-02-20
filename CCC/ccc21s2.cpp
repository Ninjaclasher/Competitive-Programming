#include <bits/stdc++.h>

using namespace std;

int main()
{
    int m, n, k;
    scanf("%i%i%i", &m, &n, &k);
    vector<int> row(m + 1);
    vector<int> col(n + 1);
    while (k--)
    {
        char c;
        int i;
        scanf(" %c%i", &c, &i);
        if (c == 'R')
            row[i] ^= 1;
        else
            col[i] ^= 1;
    }
    int ans = 0;
    for (int x = 1; x <= m; x++)
        for (int y = 1; y <= n; y++)
            ans += row[x] ^ col[y];
    printf("%i\n", ans);
}
