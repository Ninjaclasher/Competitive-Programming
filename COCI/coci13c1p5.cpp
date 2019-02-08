#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2000005;

int freq[MAXN];

int main()
{
    int n, a;
    scanf("%i", &n);
    while (n--)
    {
        scanf("%i", &a);
        freq[a]++;
    }
    long long ma = 0;
    for (int x = 1; x < MAXN; x++)
    {
        long long cnt = 0;
        for (int y = x; y < MAXN; y+=x)
            cnt += freq[y];
        if (cnt > 1)
            ma = max(ma, cnt * x);
    }
    printf("%lli\n", ma);
}
