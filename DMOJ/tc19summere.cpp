#include <bits/stdc++.h>

using namespace std;

long long calc(long long n, long long t)
{
    long long tt = t/2;
    long long ans = n + 2*(((n - tt - 1) * tt) + tt * (tt + 1)/2);
    if (t&1)
        ans += n - tt - 1;
    return ans;
}

int main()
{
    int n, t;
    scanf("%i%i", &n, &t);
    long long ans = calc(n, t-1) * (n / t);
    ans += calc(n, n%t - 1);
    cout<<ans<<endl;
}
