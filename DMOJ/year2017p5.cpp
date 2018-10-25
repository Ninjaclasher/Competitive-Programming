#include <bits/stdc++.h>

using namespace std;

int n, k;

int run(vector<int> &arr)
{
    int l = 0, r = 0, cur = 0, qi = 0, qf = 0, qb = 0;
    int ma = 0;
    vector<int> qq(100010);
    while (l < n && r < n)
    {
        while (r <= n && cur <= k)
        {
            ma = max(ma, qb-qf);
            if (r < n && arr[r])
            {
                if (qf ^ qb)
                    cur += (r-qq[qi]-(qb-qi));
                qq[qb] = r;
                qb++;
                if (qi < (qb+qf)/2)
                    qi++;
            }
            r++;
        }
        if (arr[l])
        {
            if (qq[qf] ^ l)
                abort();
            cur -= (qq[qi]-qq[qf])-(qi-qf);
            qf++;
            if (qi < (qb+qf)/2)
                qi++;
        }
        l++;
    }
    return ma;
}

int main()
{
    scanf("%i%i", &n, &k);
    vector<int> arr(n);
    for (auto &x : arr)
        scanf(" %c", &x), x -= '0';
    int mab = run(arr);
    for (auto &x : arr)
        x ^= 1;
    int maa = run(arr);
    printf("%i %i\n", mab, maa);
}

