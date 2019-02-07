#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, k;
    scanf("%i%i", &n, &k);
    vector<int> arr(n+1), psa(n+1);
    for (int x = 1; x <= n; x++)
    {
        scanf("%i", &arr[x]);
        psa[x] = arr[x] ^ psa[x-1];
    }
    long long ans = 0;
    for (long long x = k; x <= 1000; x *= k)
    {
        vector<long long> freq(1000000);
        freq[0] = 1;
        for (int y = 1; y <= n; y++)
        {
            ans += freq[psa[y] ^ x];
            freq[psa[y]]++;
        }
    }
    printf("%lli\n", ans);
}
