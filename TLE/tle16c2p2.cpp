#include <bits/stdc++.h>

using namespace std;

int main() 
{
    long long n, a, b, c, ma = LONG_MAX;
    vector<long long> y(3), aa(3);
    iota(aa.begin(), aa.end(), 0);
    scanf("%lli%lli%lli%lli%lli%lli%lli", &n, &y[0], &y[1], &y[2], &a, &b, &c);
    do
    {
        long long t = (a/y[aa[0]])*(b/y[aa[1]])*(c/y[aa[2]]);
        if (t)
            ma = min(ma, (long long)ceil(n/(double)t));
    }
    while (next_permutation(aa.begin(), aa.end()));
    if (ma == LONG_MAX)
        printf("SCAMMED");
    else
        printf("%lli", ma);
    return 0;
}
