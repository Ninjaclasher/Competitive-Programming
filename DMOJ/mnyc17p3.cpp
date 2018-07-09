#include <bits/stdc++.h>

using namespace std;

const long long base = 29, MOD = 1000000007;

vector<long long> pb(1000050);

struct hsh
{
    vector<long long> hh;
    hsh(string b)
    {
        hh.resize(1000050);
        for (int x = 1; x <= b.length(); x++)
            hh[x] = (hh[x-1]*base+(b[x-1]-'A'+1))%MOD;
    }
    long long get(int l, int r)
    {
        return (hh[r]-hh[l-1]*pb[r-l+1]%MOD + MOD)%MOD;
    }
};

int main()
{
    string a, b;
    cin>>a>>b;
    pb[0] = 1;
    for (int x = 1; x < pb.size(); x++)
        pb[x] = pb[x-1]*base%MOD;
    hsh aa(a), bb(b);
    int i = 0;
    for (int x = 1; x <= min(a.length(), b.length()); x++)
        if (aa.get(a.length()-x+1, a.length()) == bb.get(1, x))
            i = x;
    cout<<a<<b.substr(i, b.length());
}
