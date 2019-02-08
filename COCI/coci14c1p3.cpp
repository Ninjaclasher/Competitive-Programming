#include <bits/stdc++.h>

using namespace std;

int main()
{
    vector<vector<int>> psa(26);
    long long n, k, a;
    char c;
    scanf("%lli", &n);
    string aa;
    cin>>aa;
    int sz = aa.size();
    for (int x = 0; x < sz; x++)
        psa[aa[x]-'A'].push_back(x);
    scanf("%lli", &k);
    while (k--)
    {
        scanf("%lli %c", &a, &c);
        c -= 'A';
        long long pos = 0;
        if (a&1)
            pos = a%sz * ((a-1)/2%sz) % sz;
        else
            pos = a/2%sz * ((a-1)%sz) %sz;
        long long mult = a/sz;
        a -= sz * mult;
        long long ans = psa[c].size() * mult;
        auto it = lower_bound(psa[c].begin(), psa[c].end(), pos);
        --a;
        if (pos + a < sz)
            ans += upper_bound(psa[c].begin(), psa[c].end(), pos+a) - it;
        else
        {
            ans += psa[c].end() - it;
            a -= sz-pos;
            ans += upper_bound(psa[c].begin(), psa[c].end(), a) - psa[c].begin();
        }
        printf("%lli\n", ans);
    }
}
