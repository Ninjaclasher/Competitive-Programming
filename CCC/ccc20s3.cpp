#include <bits/stdc++.h>

using namespace std;

const long long MOD1 = 1000000007, BASE1 = 31, MOD2 = 1000003211, BASE2 = 131;

long long mod_pow(long long base, long long exp, long long MOD)
{
    long long ret = 1;
    for (base %= MOD; exp; exp >>= 1, base = (base * base) % MOD)
        if (exp&1)
            ret = (ret * base) % MOD;
    return ret;
}

int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);
    string n, h;
    cin>>n>>h;
    if (n.size() > h.size())
        return 0 * printf("0\n");
    vector<int> cntn(26), cnth(26);
    set<pair<int,int>> rhash;
    long long hsh1 = 0, hsh2 = 0;
    for (auto &x : n)
        cntn[x - 'a']++;
    for (int x = 0; x < n.size(); x++)
    {
        cnth[h[x] - 'a']++;
        hsh1 = hsh1 * BASE1 + h[x] - 'a' + 1;
        hsh1 %= MOD1;
        hsh2 = hsh2 * BASE2 + h[x] - 'a' + 1;
        hsh2 %= MOD2;
    }
    long long SHIFT1 = mod_pow(BASE1, n.size() - 1, MOD1);
    long long SHIFT2 = mod_pow(BASE2, n.size() - 1, MOD2);
    for (int x = n.size(); x <= h.size(); x++)
    {
        bool match = true;
        for (int y = 0; y < 26; y++)
            match &= cntn[y] == cnth[y];
        if (match)
            rhash.insert({(int)hsh1, (int)hsh2});
        hsh1 -= (h[x - n.size()] - 'a' + 1) * SHIFT1;
        hsh2 -= (h[x - n.size()] - 'a' + 1) * SHIFT2;
        cnth[h[x - n.size()] - 'a']--;
        if (x < h.size())
        {
            hsh1 = hsh1 * BASE1 + h[x] - 'a' + 1;
            hsh2 = hsh2 * BASE2 + h[x] - 'a' + 1;
            cnth[h[x] - 'a']++;
        }
        hsh1 = (hsh1 % MOD1 + MOD1) % MOD1;
        hsh2 = (hsh2 % MOD2 + MOD2) % MOD2;
    }
    printf("%lu\n", rhash.size());
}
