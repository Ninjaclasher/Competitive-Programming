#include <bits/stdc++.h>

using namespace std;

bool FAIL = true;

vector<long long> div(vector<long long> n, vector<long long> &d)
{
    FAIL = false;
    vector<long long> ret(n.size());
    for (int x = 0; x < n.size()-d.size()+1; x++)
    {
        long long m = n[x]/d[0];
        ret[x+1] = m;
        for (int y = 0; y < d.size(); y++)
            n[x+y] -= m*d[y];
    }
    for (int x = 0; x < n.size(); x++)
        if (n[x])
            FAIL = true;
    return ret;
}

int main()
{
    int n;
    scanf("%i", &n);
    while (n--)
    {
        int d;
        scanf("%i", &d);
        vector<long long> cur(d+1);
        for (auto &x : cur)
            scanf("%lli", &x);
        for (int x = 150; x >= -150; x--)
        {
            vector<long long> dd = {1, x};
            while(d)
            {
                vector<long long> c = div(cur, dd);
                if (FAIL)
                    break;
                cur = c;
                printf("%i ", -x);
                --d;
            }
        }
        printf("\n");
    }
}
