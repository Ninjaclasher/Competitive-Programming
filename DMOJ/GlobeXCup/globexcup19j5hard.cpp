#include <bits/stdc++.h>

using namespace std;

template <const long long BASE=131, const long long MOD=1000000007>
struct hsh
{
    vector<long long> hashes, powers;

    hsh(string str)
    {
        int sz = str.size();
        hashes.resize(sz+1);
        powers.resize(sz+1);
        powers[0] = 1;
        for (int x = 1; x <= sz; x++)
        {
            powers[x] = powers[x-1] * BASE % MOD; 
            hashes[x] = (hashes[x-1] * BASE % MOD + str[x-1])%MOD;
        }
    }
    inline long long get()
    {
        return hashes.back();
    }
    inline long long get(int l, int r)
    {
        return (hashes[r+1]-hashes[l]*powers[r-l+1]%MOD + MOD)%MOD;
    }
    inline long long get(int l, int r, int shift)
    {
        return get(l, r) * powers[shift] % MOD;
    }
};

bool run(string &a, string &b)
{
    long long MOD1 = 1000000007, MOD2 = 1000002457;
    hsh<> a1(a), b1(b);
    hsh<137, 1000002457> a2(a), b2(b);

    vector<long long> match;
    match.reserve(b.length() * b.length());

    for (int x = 0; x < b.length()-1; x++)
    {
        for (int y = x; y < b.length()-1; y++)
        {
            long long cur1 = 0, cur2 = 0;
            if (x > 0)
                cur1 += b1.get(0, x-1, b.length()-x),
                cur2 += b2.get(0, x-1, b.length()-x);
            if (y+1 < b.length())
                cur1 += b1.get(y+1, b.length()-1, y-x+1),
                cur2 += b2.get(y+1, b.length()-1, y-x+1);
            cur1 += b1.get(x, y);
            cur2 += b2.get(x, y);
            cur1 %= MOD1;
            cur2 %= MOD2;
            match.push_back(cur1 << 32 | cur2);
        }
    }
    match.push_back(b1.get() << 32 | b2.get());
    sort(match.begin(), match.end());
    match.erase(unique(match.begin(), match.end()), match.end());
    for (int x = 0; x < a.length()-1; x++)
    {
        for (int y = x; y < a.length()-1; y++)
        {
            long long cur1 = 0, cur2 = 0;            
            if (x > 0)
                cur1 += a1.get(0, x-1, a.length()-x),    
                cur2 += a2.get(0, x-1, a.length()-x);    
            if (y+1 < a.length())                             
                cur1 += a1.get(y+1, a.length()-1, y-x+1),     
                cur2 += a2.get(y+1, a.length()-1, y-x+1);
            cur1 += a1.get(x, y);
            cur2 += a2.get(x, y);
            cur1 %= MOD1;
            cur2 %= MOD2;
            long long cur = cur1 << 32 | cur2;
            auto it = lower_bound(match.begin(), match.end(), cur);
            if (it != match.end() && *it == cur)
                return true;
        }
    }
    return false;
}

int main()
{
    string a, b;
    cin>>a>>b;
    a += '%';
    b += '%';
    if (!run(a, b))
        printf("no aliens\n");
    else
        printf("aliens\n");
}
