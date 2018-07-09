#include <bits/stdc++.h>

using namespace std;

int k, m;
bool possible(vector<long long> a, long long height)
{
    vector<long long> add(a.size()+m+1);
    long long need = 0;
    for (int x = 0; x < a.size(); x++)
    {
        if (x)
            add[x] += add[x-1];
        a[x] += add[x];
        if (a[x] < height)
        {
            int diff = height-a[x];
            need+=diff;
            if (need > k) return false;
            add[x]+=diff, add[x+m]-=diff;
        }
    }
    return need <= k;
}

int main()
{
    int n;
    long long mi = INT_MAX, ma = 0;
    scanf("%i%i%i", &n, &m, &k);
    vector<long long> a(n);
    for (auto &x : a)
        scanf("%lli", &x), mi = min(mi, x), ma = max(ma, x);
    long long l = mi, r = ma+k;
    while (l <= r)
    {
        int mid = (l+r)/2;
        if (possible(a, mid)) l = mid+1;
        else r = mid-1;
    }
    printf("%lli", r);
}
