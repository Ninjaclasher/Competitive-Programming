#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")

using namespace std;

const int MAXN = 200005;

long long BASE1 = 31, MOD1 = 1000000007, BASE2 = 37, MOD2 = 1000000009;

vector<long long> h1(MAXN), p1(MAXN);
vector<long long> h2(MAXN), p2(MAXN);

static inline long long get1(int l, int r)
{
    return ((h1[r+1] - h1[l] * p1[r -l + 1]) % MOD1 + MOD1) % MOD1;
}

static inline long long get2(int l, int r)
{
    return ((h2[r+1] - h2[l] * p2[r -l + 1]) % MOD2 + MOD2) % MOD2;
}

int n;

long long hashes[MAXN];

static inline bool test(int len)
{
    int i = 0;
    for (int x = 0; x < n-len; x++)
        hashes[i++] = get1(x, x+len) << 32 | get2(x, x+len);
    sort(hashes, hashes+i);
    for (int x = 0; x < i-1; x++)
        if (hashes[x] == hashes[x+1])
            return true;
    return false;
}

int main()
{
    p1[0] = 1;
    p2[0] = 1;
    for (int x = 1; x < MAXN; x++)
        p1[x] = (p1[x-1] * BASE1) % MOD1,
        p2[x] = (p2[x-1] * BASE2) % MOD2;

    cin.tie(0);
    cin.sync_with_stdio(0);
    cin>>n;
    string a;
    cin>>a;
    for (int x = 1; x <= a.length(); x++)
        h1[x] = (h1[x-1] * BASE1 + a[x-1] - 'a' + 1) % MOD1,
        h2[x] = (h2[x-1] * BASE2 + a[x-1] - 'a' + 1) % MOD2;
    int l = 0, r = n-1;
    while (l <= r)
    {
        int m = l+r>>1;
        if (test(m))
            l = m+1;
        else
            r = m-1;
    }
    printf("%i\n", r+1);
}
