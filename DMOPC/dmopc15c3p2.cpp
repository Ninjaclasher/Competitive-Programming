#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    long long sum = 0, a;
    scanf("%i", &n);
    vector<long long> arr(n);
    for (auto &x : arr)
    {
        scanf("%lli", &x);
        sum += x;
    }
    if (sum%n)
        return 0 * printf("Impossible\n");
    sum /= n;
    long long ans = 0;
    for (auto &x : arr)
        if (x > sum)
            ans += x-sum;
    printf("%lli\n", ans);
}
