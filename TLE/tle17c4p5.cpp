#include <bits/stdc++.h>

using namespace std;

vector<long long> st(600005, 1), arr(200005);
int n, MOD;

long long fast_pow(long long b, long long e)
{
    long long ret = 1;
    for (; e; e>>=1, b=b*b% MOD)
        if (e&1)
            ret = ret*b% MOD;
    return ret% MOD;
}

long long update(int l, int r, int v, int i, int val)
{
    if (l > i || r < i)
        return st[v]; 
    if (l == r)
        return st[v] = fast_pow(l, arr[l] += val);
    int m = l+r>>1;
    return st[v] = update(l, m, v<<1, i, val) * update(m+1, r, v<<1|1, i, val) % MOD;
}

void factor(int n, int t)
{
    for (int x = 2; x <= sqrt(n); x++)
    {
        if (n%x == 0)
        {
            int cnt = 0;
            while (n%x == 0)
                cnt++, n/=x;
            update(1, 262143, 1, x, t*cnt);
        }
    }
    if (n > 1)
        update(1, 262143, 1, n, t);
}

int main()
{
    scanf("%i%i", &n, &MOD);
    printf("1\n");
    for (int x = 1; x <= n; x++)
    {
        factor(n-x+1, 1);
        factor(x, -1);
        printf("%lli\n", st[1]%MOD);
    }
}
