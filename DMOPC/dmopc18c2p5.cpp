#include <bits/stdc++.h>

using namespace std;

const long long MOD = 1000000007;

int m;

vector<long long> multiply(vector<long long> &a, vector<long long> &b)
{
    vector<long long> c(a.size());
    for (int x = 0; x < a.size(); x++)
        for (int y = 0; y < b.size(); y++)
            if (x+y < c.size())
                c[x+y] = (c[x+y] + a[x]*b[y]) % MOD;
    return c;
}

void pow(long long e, vector<long long> &aa, vector<long long> &ret)
{
    ret[0]= 1;
    while(e)
    {
        if (e&1)
            ret = multiply(ret, aa);
        aa = multiply(aa, aa);
        e >>= 1;
    }
}

int main()
{
    long long n;
    int k, a;
    scanf("%lli%i%i", &n, &m, &k);
    vector<long long> aa(m+2), ret(m+2);
    for (int x = 0; x < k; x++)
    {
        scanf("%i", &a);
        aa[a]++;
    }
    pow(n, aa, ret);
    long long cnt = 0;
    for (int x = 0; x <= m; x++)
        cnt = (cnt + ret[x])%MOD;
    printf("%lli\n", cnt % MOD);
}

