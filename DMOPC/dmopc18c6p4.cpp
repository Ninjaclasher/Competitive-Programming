#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1000005;

vector<long long> psa(MAXN), aa(MAXN), psb(MAXN), bb(MAXN);

int main()
{
    int n, p, m, a;
    scanf("%i%i%i", &n, &p, &m);
    vector<pair<int,int>> arr(n);
    for (auto &x : arr)
        scanf("%i%i", &x.first, &x.second);
    while (p--)
    {
        scanf("%i", &a);
        aa[a]++;
    }
    while (m--)
    {
        scanf("%i", &a);
        bb[a]++;
    }
    for (int x = MAXN-2; x >= 1; x--)
    {
        aa[x] += aa[x+1];
        psa[x] += psa[x+1] + aa[x];
        bb[x] += bb[x+1];
        psb[x] += psb[x+1] + bb[x];
    }
    long long ma = LONG_MAX, mai = 0;
    for (int x = 0; x < n; x++)
    {
        long long cur = psa[arr[x].first+1] + psb[arr[x].second+1];
        if (cur < ma)
            ma = cur, mai = x+1;
    }
    printf("%lli\n", mai);
}
