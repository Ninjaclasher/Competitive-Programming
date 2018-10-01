#include <bits/stdc++.h>

using namespace std;

int main()
{
    int q;
    long long n, m, k;
    scanf("%i%lli", &q, &k);
    vector<long long> pp;
    for (int x = 0; x <= 99999; x++)
    {
        string a = to_string(x), b = a;
        reverse(b.begin(), b.end());
        n = stoll(a+b);
        if (!(n%k))
            pp.push_back(n);
        a.pop_back();
        n = stoll(a+b);
        if (!(n%k))
            pp.push_back(n);
    }
    sort(pp.begin(), pp.end());
    while (q--)
    {
        scanf("%lli%lli", &m, &n);
        auto it = lower_bound(pp.begin(), pp.end(), m);
        auto it2 = lower_bound(pp.begin(), pp.end(), n);
        if (*it2 != n)
            --it2;
        printf("%lli\n", it2-it+1);
    }
}

