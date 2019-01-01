#include <bits/stdc++.h>

using namespace std;

const long long base = 29, MOD = 1000000007;

vector<long long> pb(200050);

struct hsh
{
    vector<long long> hh;
    hsh(string b)
    {
        hh.resize(200050);
        for (int x = 1; x <= b.length(); x++)
            hh[x] = (hh[x-1]*base+(b[x-1]-'a'+1))%MOD;
    }
    long long get(int l, int r)
    {
        return (hh[r]-hh[l-1]*pb[r-l+1]%MOD + MOD)%MOD;
    }
};

int main()
{
    pb[0] = 1;
    for (int x = 1; x < pb.size(); x++)
        pb[x] = pb[x-1]*base%MOD;
    int n;
    scanf("%i", &n);
    string a;
    cin>>a;
    hsh aa(a);
    long long ans = 0;
    vector<int> ls;
    vector<long long> pre(n);
    for (int x = 0; x < n; x++)
    {
        pre[x] = aa.get(1, 1+x);
        if (pre[x] == aa.get(n-x, n))
            ls.push_back(x);
    }
    for (int x = 1; x <= n; x++)
    {
        if (a[x-1] != a[0])
            continue;
        int l = 0, h = n-x;
        while (l <= h)
        {
            int m = (l+h)/2;
            if (pre[m] != aa.get(x, x+m))
                h = m - 1;
            else
                l = m + 1;
        }
        ans += upper_bound(ls.begin(), ls.end(), l-1)-ls.begin();
    }
    cout<<ans<<"\n";
}
