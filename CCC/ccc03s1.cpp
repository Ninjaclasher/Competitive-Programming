#include <bits/stdc++.h>

using namespace std;

const int MAXN = 105;

int main()
{
    vector<int> par(MAXN);
    iota(par.begin(), par.end(), 0);
    par[99] = 77;
    par[90] = 48;
    par[67] = 86;
    par[54] = 19;
    par[40] = 64;
    par[9] = 34;
    int cur = 1, n;
    for (scanf("%i", &n); n; scanf("%i", &n))
    {
        if (cur+n <= 100)
        {
            cur += n;
            cur = par[cur];
        }
        printf("You are now on square %i\n", cur);
        if (cur == 100)
            return 0 * printf("You Win!\n");
    }
    printf("You Quit!\n");
}
