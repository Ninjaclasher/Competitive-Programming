#include <bits/stdc++.h>

using namespace std;

long double dp[23];

long long choose[23][23];

long long fact(int n)
{
    long long ret = 1;
    for (int x = 2; x <= n; x++)
        ret *= x;
    return ret;
}

void precomp()
{
    for (int n = 1; n <= 20; n++)
        for (int k = 0; k <= n; k++)
            choose[n][k] = fact(n) / fact(n-k) / fact(k); 
}

long double p;

long double solve(int i)
{
    auto &cur = dp[i];
    if (cur)
        return cur;
    if (i == 20)
        return 0;
    cur = 1;
    for (int x = 1; x <= 20-i; x++)
    {
        cur += choose[20-i][x] * pow(p, x) * pow(1-p, 20-i-x) * solve(i+x);
    }
    cur /= 1 - pow(1-p, 20-i);
    return cur;
}

int main()
{
    int t;
    scanf("%i", &t);
    precomp();
    for (int i = 1; i <= t; i++)
    {
        scanf("%Lf", &p);
        for (int x = 0; x < 23; x++)
            dp[x] = 0;
        printf("Case #%i: %.30Lf\n", i, solve(0));
    }
}

