#include <bits/stdc++.h>

using namespace std;

long long getPow(long long max)
{
    unsigned long long pt = 1;
    for (int i = 0; i < 64; i++)
    {
        pt <<= 1;
        if (pt > max)
        {
            pt >>= 1;
            return static_cast<long long>(pt);
        }
    }
    return 0;
}

int main()
{
    long long t;
    int n;
    scanf("%i%lli", &n, &t);
    vector<bool> oG (n), nG (n);
    string input;
    cin>>input;
    for (int x = 0; x < n; x++)
        oG[x] = input[x] - '0';
    while (t > 0)
    {
        long long lp = getPow(t);
        t -= lp;
        for (int x = 0, q = (x-lp)%n; x < n; x++, q = (x-lp)%n)
            nG[x] = oG[q + (q < 0 ? n : 0)] ^ oG[(x + lp) % n];
        swap(oG, nG);
    }
    for (int x = 0; x < n; x++)
        printf("%i", static_cast<int>(oG[x]));
    return 0;
}
