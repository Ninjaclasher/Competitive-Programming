#include <bits/stdc++.h>

using namespace std;

vector<long long> aa(1000005);

long long fib(int n)
{
    if (n < 2)
        return aa[n];
    return max(aa[n], fib(n-2)+aa[n-1]);
}

int main() 
{
    int k, n;
    scanf("%i%i", &k, &n);
    if (k > n+1)
        return 0 * printf("-1");
    for (int x = 1; x <= n; x++)
        scanf("%lli", &aa[x]);
    if (k == 1)
        printf("%lli", max(aa[1], aa[2]));
    else
        printf("%lli", fib(k));
    return 0;
}
