#include <bits/stdc++.h>

using namespace std;

const long long MOD = 1000000000;

const int MAXN = 1000005;
const int MAXM = 1000005;

long long arr[MAXN];
long long o[MAXM];
long long a[MAXM];
long long b[MAXM];
long long c[MAXM];
long long d[MAXM];
long long xs, ys, zs, xo, yo, zo, xa, ya, za, xb, yb, zb, xc, yc, zc, xd, yd, zd;

int main()
{
    int t;
    scanf("%i", &t);
    for (int i = 1; i <= t; i++)
    {
        int n, m;
        scanf("%i%i", &n, &m);
        scanf("%lli%lli%lli%lli%lli", &arr[1], &arr[2], &xs, &ys, &zs);
        scanf("%lli%lli%lli%lli%lli", &o[1], &o[2], &xo, &yo, &zo);
        scanf("%lli%lli%lli%lli%lli", &a[1], &a[2], &xa, &ya, &za);
        scanf("%lli%lli%lli%lli%lli", &b[1], &b[2], &xb, &yb, &zb);
        scanf("%lli%lli%lli%lli%lli", &c[1], &c[2], &xc, &yc, &zc);
        scanf("%lli%lli%lli%lli%lli", &d[1], &d[2], &xd, &yd, &zd);
        for (int x = 3; x <= n; x++)
            arr[x] = (xs * arr[x-2] + ys * arr[x-1] + zs)%MOD;
        for (int x = 3; x <= m; x++)
        {
            o[x] = (xo * o[x-2] + yo * o[x-1] + zo)%4 + 1;
            a[x] = (xa * a[x-2] + ya * a[x-1] + za)%n + 1;
            b[x] = (xb * b[x-2] + yb * b[x-1] + zb)%n + 1;
            c[x] = (xc * c[x-2] + yc * c[x-1] + zc)%MOD;
            d[x] = (xd * d[x-2] + yd * d[x-1] + zd)%MOD;
        }
        long long ans = 0;
        for (int u = 1; u <= m; u++)
        {
            for (int x = 1; x <= n; x++)
                cout<<arr[x]<<" ";
            cout<<endl;
            int l = a[u];
            int r = a[u]+b[u]-1;
            long long cc = c[u], dd = d[u];
            if (r > n)
                r %= n;
            switch(o[u])
            {
                case 1:
                    if (r < l)
                    {
                        long long k = 0;
                        for (int x = l; x <= n; x++, k++)
                        {
                            arr[x] = (arr[x] + cc + k*dd)%MOD;
                            ans = (ans+cc+k*dd)%MOD;
                        }
                        for (int x = 1; x <= r; x++, k++)
                        {
                            arr[x] = (arr[x] + cc + k*dd)%MOD;
                            ans = (ans+cc+k*dd)%MOD;
                        }
                    }
                    else
                    {
                        long long k = 0;
                        for (int x = l; x <= r; x++, k++)
                        {
                            arr[x] = (arr[x] + cc + k*dd)%MOD;
                            ans = (ans+cc+k*dd)%MOD;
                        }
                    }
                break;
                case 2:
                    if (r < l)
                    {
                        for (int x = l; x <= n; x++)
                        {
                            ans = (ans+arr[x]+cc)%MOD;
                            arr[x] = cc;
                        }
                        for (int x = 1; x <= r; x++)
                        {
                            ans = (ans+arr[x]+cc)%MOD;
                            arr[x] = cc;
                        }
                    }
                    else
                    {
                        for (int x = l; x <= r; x++)
                        {
                            ans = (ans+arr[x]+cc)%MOD;
                            arr[x] = cc;
                        }
                    }
                break;
                case 3:
                    if (r < l)
                    {
                        for (int x = l; x <= n; x++)
                        {
                            ans = (ans+arr[x])%MOD;
                        }
                        for (int x = 1; x <= r; x++)
                        {
                            ans = (ans+arr[x])%MOD;
                        }
                    }
                    else
                    {
                        for (int x = l; x <= r; x++)
                        {
                            ans = (ans+arr[x])%MOD;
                        }
                    }
                break;
                case 4:
                    if (r < l)
                    {
                        for (int x = l; x <= n; x++)
                            if (arr[x]&1)
                                ans++;
                        for (int x = 1; x <= r; x++)
                            if (arr[x]&1)
                                ans++;
                    }
                    else
                    {
                        for (int x = l; x <= r; x++)
                            if (arr[x]&1)
                                ans++;
                    }
                    ans %= MOD;
                break;
            }
            ans %= MOD;
            //cout<<ans<<endl;
        }
        printf("Case #%i: %lli\n", i, ans%MOD);
    }
}
