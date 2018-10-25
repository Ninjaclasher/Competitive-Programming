#include <bits/stdc++.h>

using namespace std;

int besthub(int n, int L, int arr[], long long k)
{
    long long l = 0, r = 0, qi = 0, qf = 0, qb = 0;
    long long ma = 0;
    vector<long long> qq(100010);
    long long cur = 0;
    while (l < n && r < n)
    {
        while (r <= n && cur <= k)
        {
            ma = max(ma, qb-qf);
            if (r < n)
            {
                if (qf ^ qb)
                    cur += (arr[r]-qq[qi]);
                qq[qb] = arr[r];
                qb++;
                if (qi < (qb+qf)/2)
                    qi++;
            }
            r++;
        }
        cur -= (qq[qi]-qq[qf]);
        qf++;
        if (qi < (qb+qf)/2)
            qi++;
        l++;
    }
    return (int)ma;
}

