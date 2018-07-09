#include <bits/stdc++.h>

using namespace std;

long double dp[21][21][501];

long double next(int Y, int D, int K)
{
    if (K <= 0) return 1;
    if (D == 0) return 0;
    if (dp[Y][D][K] >= 0) return dp[Y][D][K];
    dp[Y][D][K] = 0;
    for (int x = 1; x <= Y; x++)
        dp[Y][D][K] += next(Y, D-1, K-x);
    return dp[Y][D][K] *= 1.0/Y;
}

int main()
{
    memset(dp, -1, sizeof(dp));
    int t, h, s;
    string a;
    scanf("%i", &t);
    for (int qqq = 1; qqq <= t; qqq++)
    {
        scanf("%i%i", &h, &s);
        long double ma = -1;
        while(s--)
        {
            cin>>a;
            int p = 0, dd = 0, tt = 0, aa = 0;
            while(a[p] != 'd') tt = tt*10 + (a[p++]-'0');
            p++;
            while(p < a.size() && a[p] != '-' && a[p] != '+') dd = dd*10 + (a[p++]-'0');
            int pp = p++;
            while(p < a.size()) aa = aa*10 + (a[p++] - '0');
            if (a[pp] == '-')
                aa = -aa;
            h -= aa;
            if (h > dd*tt)
                ma = max((long double)0, ma);
            else
                ma = max(ma, next(dd,tt,h));
            h += aa;    
        }
        printf("Case #%i: %Lf\n", qqq, ma);
    }
}
