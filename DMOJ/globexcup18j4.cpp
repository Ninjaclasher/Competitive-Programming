#include <bits/stdc++.h>

using namespace std;

const long long MOD = 1000000007;

long long a, b, c, d, e;

long long solve(int i)
{
    if (!i)
        return e;
    return (a*solve(i/b)%MOD + c*solve(i/d)%MOD)%MOD;
}

int main()
{
    int n;
    scanf("%lli%lli%lli%lli%lli%i", &a, &b, &c, &d, &e, &n);
    printf("%lli\n", solve(n));
}
