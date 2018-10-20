#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, m;
    scanf("%i%i", &n, &m);
    vector<int> a(n);
    vector<int> b(m);
    for (auto &x : a)
        scanf("%i", &x);
    for (auto &x : b)
        scanf("%i", &x);
    long long ma = 0, mai = 0;
    sort(a.begin(), a.end());
    for (auto &x : a)
    {
        long long cur = INT_MAX;
        for (auto &y : b)
            cur = min(cur, (long long)abs(y-x));
        if (cur > ma)
            ma = cur, mai = x;
    }
    printf("%lli\n", mai);
}
