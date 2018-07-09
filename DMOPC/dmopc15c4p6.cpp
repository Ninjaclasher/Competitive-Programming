#include <bits/stdc++.h>

using namespace std;

int n, m, res;
int g[6], alarm[6], ans[6], row[6], col[6];

void recurs(int x, int y, int state)
{
    while (x < n && !(g[x]>>y & 1))
    {
        if(y + 1 >= n)
        {
            x++;
            y=0;
        }
        else y++;
    }
    if (x == n)
    {
        int ret = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if(ans[i]>>j & 1)
                    ret++;
        res = max(res, ret);
        return;
    }
    if (y + 1 >= n)
        recurs(x+1, 0, state);
    else
        recurs(x, y+1, state);
    int arr[6];
    for (int i=0; i<n; i++)
        arr[i] = ans[i];
    for (int i=0; i<m; i++)
    {
        if (state>>i & 1 || x+alarm[i]-1>=n || x-alarm[i]+1<0 ||  y+alarm[i]-1>=n || y-alarm[i]+1<0 || row[x] || col[y])
            continue;
        int line = 1<< ((alarm[i]-1)*2+1);
        --line <<= (y-alarm[i]+1);
        for (int j = x-alarm[i]+1; j <= x+alarm[i]-1; j++)
        {
            int tmp = line & g[j];
            ans[j] |= tmp;
        }
        row[x] = col[y] = true;
        if(y + 1 >= n)
            recurs (x+1, 0, state+(1<<i));
        else
            recurs (x, y+1, state+(1<<i));
        for (int i = 0; i < n; i++)
            ans[i] = arr[i];
        row[x] = col[y] = false;
    }
}

int main()
{
    scanf("%i", &n);
    for(int x = 0; x < n; x++)
    {
        int sum = 0;
        for(int y = 0; y < n; y++)
        {
            int tmp;
            scanf("%i", &tmp);
            if (tmp) sum += 1<<y;
        }
        g[x] = sum;
    }

    scanf("%i", &m);
    for(int x = 0; x < m; x++)
        scanf("%i", &alarm[x]);
    recurs(0, 0, 0);
    printf("%i", res);
    return 0;
}
