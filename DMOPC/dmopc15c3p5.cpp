#include <bits/stdc++.h>

using namespace std;

int N;
int arr[40];

int main()
{
    int n, m;
    scanf("%i%i", &n, &m);
    N = n+m;
    for (int x = 0; x < n; x++)
        scanf("%i", &arr[x]);
    for (int x = 0; x < m; x++)
        scanf("%i", &arr[x+n]), arr[x+n] *= -1;
    map<long long, int> mp;
    int p1 = (N>>1), p2 = (N>>1)+(N&1);
    for (int x = 0; x < (1<<p1); x++)
    {
        long long s = 0;
        for (int y = 0; y < p1; y++)
            if (x>>y&1)
                s += arr[y];
        mp[s]++;
    }
    long long ans = 0;
    for (int x = 0; x < (1<<p2); x++)
    {
        long long s = 0;
        for (int y = 0; y < p2; y++)
            if (x>>y&1)
                s += arr[p1+y];
        ans += mp[-s];   
    }
    printf("%lli\n", ans-1);
}

