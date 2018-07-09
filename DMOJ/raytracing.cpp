#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> bit(8193, vector<int> (8193));
int n;

void update(int xx, int yy, int v)
{
    for (int x = xx; x <= n; x += x&-x)
        for (int y = yy; y <= n; y += y&-y)
            bit[x][y] += v;
}

int query(int xx, int yy)
{
    int sum = 0;
    for (int x = xx; x > 0; x -= x&-x)
        for (int y = yy; y > 0; y -= y&-y)
            sum += bit[x][y];
    return sum;
}

int main()
{
    int a, b, c, d, e, q;
    scanf("%i", &n);
    vector<int> arr(n+1);
    for (int x = 1; x <= n; x++)
    {
        scanf("%i", &arr[x]);
        update(++arr[x], x, 1);
    }
    scanf("%i", &q);
    while (q--)
    {
        scanf("%i%i%i", &e, &a, &b);
        b++;
        if (e == 1)
        {
            scanf("%i%i", &c, &d);
            d++;
            printf("%i\n", query(d, b) - query(c, b) - query(d, a) + query(c, a));
        }
        else
        {
            a++;
            update(arr[a], a, -1);
            arr[a] = b;
            update(arr[a], a, 1);
        }
    }
}
