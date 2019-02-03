#include <bits/stdc++.h>

using namespace std;

pair<long long,long long> dp[202][202][8][5];
char wiz[202][202][8];

void updatePos(long long &x, long long &y, long long dir)
{
    switch (dir)
    {
        case 0: ++y; break;
        case 1: ++x; break;
        case 2: --y; break;
        case 3: --x; break;
    }
}

long long n, k;

bool inBound(long long x, long long y)
{
    return x >= 0 && x < n && y >= 0 && y < n;
}

void simulate(long long &x, long long &y, long long &day, long long &dir, long long &turnCount)
{
    switch(wiz[x][y][day%7])
    {
        case 'L':
            dir = (dir+3)%4;
            turnCount++;
            break;
        case 'R':
            dir = (dir+1)%4;
            turnCount++;
            break;
    }
    long long xx = x, yy = y;
    updatePos(xx, yy, dir);
    if (!inBound(xx, yy))
    {
        dir = (dir+2)%4;
        turnCount++;
    }
    updatePos(x, y, dir); 
}

void dfs2(long long x, long long y, long long day, long long dir, long long turnCount)
{
    if (turnCount == k)
    {
        printf("%lli", day-1);
        exit(0);
    }
    simulate(x, y, day, dir, turnCount);
    dfs2(x, y, day+1, dir, turnCount);
}

void dfs(long long x, long long y, long long day, long long dir, long long turnCount = 0)
{
    if (k == turnCount)
    {
        printf("%lli\n", day-1);
        exit(0);
    }
    auto &cur = dp[x][y][day%7][dir];
    if (~cur.first)
    {
        long long diff = turnCount - cur.second;
        long long dayD = day - cur.first;
        long long kk = (k - cur.second) / diff;
        long long dday = cur.first + kk*dayD;
        long long dturn = cur.second + kk*diff;
        dfs2(x, y, dday, dir, dturn);
        //CYCLE!!!!
        exit(0);
    }
    cur = {day, turnCount};
    simulate(x, y, day, dir, turnCount);
    dfs(x, y, day+1, dir, turnCount);
}

int main()
{
    memset(dp, -1, sizeof dp);
    scanf("%lli%lli", &n, &k);
    long long m, r, c;
    scanf("%lli", &m);
    while (m--)
    {
        scanf("%lli%lli", &r, &c);
        --r; --c;
        for (long long x = 0; x < 7; x++)
            scanf(" %c", &wiz[r][c][x]);
    }
    dfs(0, 0, 0, 0);
}
