#include <bits/stdc++.h>

using namespace std;

const int LENGTH = 20003;

long long base = 1000003, MOD = 1000000007;

int n, k;
unordered_map<long long, int> st;
vector<long long> pb(LENGTH, 1), hh(LENGTH);

static inline bool test(int len)
{
    st.clear();
    for (int x = 0; x <= n-len+1; x++)
    {
        long long v = (hh[x+len]-hh[x]*pb[len]%MOD + MOD)%MOD;
        st[v]++;
        if (st[v] >= k)
            return true;
    }
    return false;
}

int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin>>n>>k;
    vector<int> arr(n+1);
    for (int x = 1; x <= n; x++)
    {
        cin>>arr[x];
        hh[x] = hh[x-1]*base + arr[x];
        hh[x] %= MOD;
    }
    for (int x = 1; x < pb.size(); x++)
        pb[x] = pb[x-1]*base%MOD;
    int l = 0, r = n+1;
    while (l <= r)
    {
        int m = l+r>>1;
        if (test(m))
            l = m+1;
        else
            r = m-1;
    }
    printf("%i\n", r);
}
