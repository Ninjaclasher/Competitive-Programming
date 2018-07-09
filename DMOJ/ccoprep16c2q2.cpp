#include <bits/stdc++.h>

using namespace std;

int main()
{
    vector<int> dp(32, 0);
    int n, a, t = 0;
    scanf("%i", &n);
    while (n--)
    {
        scanf("%i", &a);
        int b = 0;
        for (int y = 0; y < 32; y++)
            if(a & (1<<y)) 
                b = max(b, ++dp[y]);
        for (int y = 0; y < 32; y++)
            if (a & (1<<y))
                dp[y] = b;
        t = max(t, b);
    }
    printf("%i", t);
    return 0;
}
