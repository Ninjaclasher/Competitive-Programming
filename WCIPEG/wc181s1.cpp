#include <bits/stdc++.h>

using namespace std;

const int MAXR = 50005;

int bit[11][MAXR];

void update(int i, int v, int c)
{
    for (; i < MAXR; i += i&-i)
        bit[c][i] += v;
}

int query(int i, int c)
{
    if (!i)
        return 0;
    int sum = 0;
    for (; i > 0; i -= i&-i)
        sum += bit[c][i];
    return sum;
}

int main()
{
    int r, c, k;
    scanf("%i%i%i", &r, &c, &k);
    int cnt = 0, a;
    for (int x = 1; x <= r; x++)
    {
        for (int y = 1; y <= c; y++)
        {
            scanf("%i", &a);
            if (a == 1)
                update(x, 1, y);
            else if (a == 2)
            {
                int q = query(x, y) - query(max(0, x-k-1), y);
                if (q)
                    cnt++;
            }
        }
    }
    cout<<cnt<<endl;
}
