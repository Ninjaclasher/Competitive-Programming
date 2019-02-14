#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1005;

struct node
{
    int lazy, ma;
};

node st[MAXN<<2];

void pushdown(int l, int r, int v)
{
    if (st[v].lazy)
    {
        st[v].ma = max(st[v].ma, st[v].lazy);
        if (l ^ r)
        {
            st[v<<1].lazy = max(st[v<<1].lazy, st[v].lazy);
            st[v<<1|1].lazy = max(st[v<<1|1].lazy, st[v].lazy);
        }
        st[v].lazy = 0;
    }
}

int update(int l, int r, int v, int li, int ri, int val)
{
    pushdown(l, r, v);
    if (l > ri || r < li)
        return st[v].ma;
    if (l >= li && r <= ri)
    {
        st[v].lazy = val;
        pushdown(l, r, v);
        return st[v].ma;
    }
    int m = l+r>>1;
    return st[v].ma = max(update(l, m, v<<1, li, ri, val), update(m+1, r, v<<1|1, li, ri, val));
}

int query(int l, int r, int v, int i)
{
    pushdown(l, r, v);
    if (l > i || r < i)
        return 0;
    if (l == r)
        return st[v].ma;
    int m = l+r>>1;
    if (i <= m)
        return query(l, m, v<<1, i);
    else
        return query(m+1, r, v<<1|1, i);
}

int main()
{
    int n, l, r, h;
    scanf("%i", &n);
    vector<vector<char>> grid(MAXN, vector<char>(MAXN, '.'));
    while (n--)
    {
        scanf("%i%i%i", &l, &r, &h);
        --r;
        update(1, MAXN, 1, l, r, h);
    }
    vector<int> arr(MAXN);
    int lbound = 0, rbound = 0;
    for (int x = 1; x < MAXN; x++)
    {
        arr[x] = query(1, MAXN, 1, x);
        if (arr[x])
        {
            if (!lbound)
                lbound = x;
            rbound = x;
        }
    }
    int cnt = 0;
    for (int x = lbound; x <= rbound; x++)
    {
        cnt += max(0, arr[x] - arr[x-1]);
        cnt += max(0, arr[x] - arr[x+1]);
        if (arr[x])
            cnt++;
        grid[arr[x]][x] = '#';
        for (int y = arr[x-1]; y <= arr[x]; y++)
            grid[y][x] = '#';
        for (int y = arr[x+1]; y <= arr[x]; y++)
            grid[y][x] = '#';
        grid[0][x] = '*';
    }
    printf("%i\n", cnt);
    for (int x = st[1].ma; x >= 0; x--)
    {
        for (int y = lbound; y <= rbound; y++)
            printf("%c", grid[x][y]);
        printf("\n");
    }
}
