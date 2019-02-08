#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")

using namespace std;

const int LENGTH = 200003;

long long base = 27;

struct hsh
{
    vector<long long> hh, pb;
    hsh(){}
    hsh(string b)
    {
        int sz = b.size();
        pb.resize(sz+1, 1);    
        for (unsigned int x = 1; x < pb.size(); x++)
            pb[x] = (pb[x-1]*base);
        hh.resize(sz+1);
        for (int x = 1; x <= sz; x++)
            hh[x] = (hh[x-1]*base+b[x-1]);
    }
    inline long long get(int l, int r)
    {
        return (hh[r+1]-hh[l]*pb[r-l+1]);
    }
};

int n;
unordered_set<long long> st;
hsh h;

static inline bool test(int len)
{
    st.clear();
    for (int x = 1; x <= n-len; x++)
    {
        long long v = h.get(x, x+len);
        if (st.count(v))
            return true;
        st.insert(v);
    }
    return false;
}

int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin>>n;
    string a;
    cin>>a;
    h = hsh(a);
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
