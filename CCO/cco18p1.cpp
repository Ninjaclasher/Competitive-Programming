#include <bits/stdc++.h>

using namespace std;

vector<long long> a(1005), b(1005), pa(1005), pb(1005);
vector<vector<long long>> dp(2000, vector<long long>(2000));
vector<long long> ma(1005);
long long n, mm = 0, tt = 0;

void ne(int i, int j, long long mma)
{
    if (i == n+1)
    {
        tt = max(mma, tt);
        return;
    }
    for (int x = j; x <= n; x++)
        if ((pa[i] && !pb[x] && a[i] > b[x]) || (!pa[i] && pb[x] && a[i] < b[x]))
            ne(i+1, x+1, mma + a[i]+b[x]);
    ne(i+1, j, mma);
}


int main()
{
    string aa, bb;
    scanf("%lli", &n);  
    cin>>aa;
    for (long long x = 1; x <= n; x++)
    {
        scanf("%lli", &a[x]);
        pa[x] = (aa[x-1] == 'W');
    }
    cin>>bb;
    for (long long x = 1; x <= n; x++)
    {
        scanf("%lli", &b[x]);
        pb[x] = (bb[x-1] == 'W');
    }
    for (long long x = 1; x <= n; x++)
    {
        for (long long y = 1; y <= n; y++)
        {
            dp[x][y] = ma[y-1];
            if ((pa[x] && !pb[y] && a[x] > b[y]) || (!pa[x] && pb[y] && a[x] < b[y]))
                dp[x][y] += a[x]+b[y];
            dp[x][y] = max(dp[x][y], ma[y]);
        }
        for (long long y = 1; y <= n; y++)
            ma[y] = max(dp[x][y], ma[y-1]);
        //for (int y = 1; y <= n; y++)
        //  cout<<ma[y]<<" ";
        //cout<<endl;
        mm = max(mm, ma[n]);
    }
    //ne(1, 1, 0);
    /*if (tt != mm)
    {
        if (abs(tt-mm) < 10)
            while (true);
        else if (abs(tt-mm) < 100)
            abort();
    }*/
    //printf("%lli\n", tt);
    printf("%lli\n", mm);
}
