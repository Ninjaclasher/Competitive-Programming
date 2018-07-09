#include <bits/stdc++.h>

int spt[1005][1005];

void build(int l, int r) 
{
    if (r - l <= 1)
        return;
    int m = (l+r) / 2;
    for (int x = m - 1; x >= l; x--)
        if (!~spt[x][m])
            spt[x][m] = Secret(spt[x][x+1], spt[x+1][m]);
    for (int x = m + 1; x <= r; x++)
        if (!~spt[m][x])
            spt[m][x] = Secret(spt[m][x-1], spt[x-1][x]);
    build(l, m);
    build(m, r);
}

void Init(int N, int A[]) 
{
    memset(spt, -1, sizeof(spt));
    for (int x = 0; x < N; x++)
        spt[x][x+1] = A[x];
    build(0, N);
}

int Query(int L, int R) 
{
    for (int x = L + 1; x <= R; x++)
        if (~spt[L][x] && ~spt[x][R+1])
            return Secret(spt[L][x], spt[x][R+1]);
    return spt[L][R + 1];
}
