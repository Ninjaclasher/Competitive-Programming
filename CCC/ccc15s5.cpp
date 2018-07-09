#include <bits/stdc++.h>

using namespace std;

int dp[3010][110][110][2];
vector<int> nn, mm;

int n, m;

int next(int p, int lidx, int ridx, int t)
{
    int &tmp = dp[p][lidx][ridx][t];
    if (tmp != -1)
        return tmp;
    else if (p == n)
        if (m && lidx <= ridx)
            if (t) tmp = mm[ridx] + next(p, lidx, ridx-1, 0);
            else tmp = next(p, lidx + 1, ridx, 1);
        else tmp = 0;
    else if (t)
        tmp = max(max(next(p, lidx, ridx, 0), nn[p] + next(p+1, lidx, ridx, 0)), (m && lidx <= ridx) ? mm[ridx] + next(p, lidx, ridx-1, 0) : 0);
    else
        tmp = max(next(p+1, lidx, ridx, 1), (m && lidx <= ridx) ? next(p, lidx+1, ridx, 1) : 0);
    return tmp;
}

int main()
{
    memset(dp, -1, sizeof(dp));
    scanf("%i", &n);
    nn.resize(n);
    for (auto &x : nn) scanf("%i", &x);
    scanf("%i", &m);
    mm.resize(m);
    for (auto &x : mm) scanf("%i", &x);
    sort(mm.begin(), mm.end());
    printf("%i\n", next(0, 0, max(0,m-1), 1));
}
