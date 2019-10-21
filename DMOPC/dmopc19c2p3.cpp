#include <bits/stdc++.h>

using namespace std;

const int MAXN = 300005;
int n;

int bit[30][MAXN];

void update(int i, int x, int v)
{
    for (; x <= n; x += x&-x)
        bit[i][x] += v;
}

int query(int i, int x)
{
    int ret = 0;
    for (; x; x -= x&-x)
        ret += bit[i][x];
    return ret;
}

int main()
{
    int m;
    scanf("%i%i", &n, &m);
    vector<int> arr(n+1);
    for (int x = 1; x <= n; x++)
    {
        scanf("%i", &arr[x]);
        update(arr[x], x, 1);
    }
    while (m--)
    {
        int a, b, c, d;
        scanf("%i%i%i", &a, &b, &c);
        if (a == 1)
        {
            update(arr[b], b, -1);
            arr[b] = c;
            update(arr[b], b, 1);
        }
        else
        {
            scanf("%i", &d);
            int sum = 0;
            for (int x = 20; x >= 0; x--)
            {
                sum += query(x, c) - query(x, b-1);
                if (sum >= d)
                {
                    printf("%i\n", x);
                    goto nxt;
                }
            }
nxt:;
        }
    }
}
