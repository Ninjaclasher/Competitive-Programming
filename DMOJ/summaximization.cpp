#include <bits/stdc++.h>

using namespace std;

int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);
    int q;
    cin>>q;
    while (q--)
    {
        long long ma = 0, sum = 0;
        string a, b;
        cin>>b>>a;
        for (auto &x : a)
            x -= '0';
        while (b.size() < a.size())
            b = "0" + b;
        for (auto &x : b)
            x -= '0';
        bool all = false;
        for (int x = 0; x < a.size(); x++)
        {
            all |= a[x] > b[x];
            if (all)
            {
                long long cur = a[x]-1 + sum + 9*(a.size()-x-1);
                ma = max(ma, cur);
            }
            sum += a[x];
        }
        ma = max(ma, sum);
        printf("%lli\n", ma);
    }
}
