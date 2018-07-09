#include <bits/stdc++.h>

using namespace std;

const long long base = 29, MOD = 1000000007;

string a;
int k, mi = 0;
vector<long long> aa(1000010), bb(1000010);

long long hh(int p, int len) 
{
    return ((aa[p+len] - bb[len] * aa[p])%MOD + MOD) % MOD;
}

int main()
{
    cin>>a>>k;
    aa[0] = a[0], bb[0] = 1;
    for (int x = 1; x < a.size(); x++)
        aa[x] = ((aa[x-1]*base)%MOD + (a[x]-'a'+1))%MOD, bb[x] = (bb[x-1]*base)%MOD;
    for (int x = 1; x <= a.size()-k; x++)
    {
        if (a[x] < a[mi])
            mi = x;
        else if (a[x] == a[mi])
        {
            int l = 0, h = k;
            while (l <= h)
            {
                int m = (l+h)/2;
                if (hh(mi, m) ^ hh(x, m))
                    h = m - 1;
                else
                    l = m + 1;
            }
            if (a[x+l] < a[mi+l])
                mi = x;
        }
    }
    cout<<a.substr(mi, k);
}
