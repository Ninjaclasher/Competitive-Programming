#include <bits/stdc++.h>

using namespace std;

int bit[3000][3000], aa[3000][3000];

void update(int i, int j, int v)
{
    for (int x = i; x < 3000; x += x&-x)
        for (int y = j; y < 3000; y += y&-y)
            bit[x][y] += v;
}

int query(int i, int j)
{
    int s = 0;
    for (int x = i; x; x -= x&-x)
        for (int y = j; y; y -= y&-y)
            s += bit[x][y];
    return s;
}

void convert(int &i, int &j)
{
    int ii = i+j-1, jj = 1005+i-j;
    i = ii, j = jj;
}

int main()
{
    int l, t, a, b;
    char c;
    scanf("%i%i", &l, &t);
    while (t--)
    {
        scanf(" %c%i%i", &c, &a, &b);
        if (a > 1900)
            continue;
        convert(a, b);
        switch(c)
        {
            case 'E':
                update(a, b, 1);
                aa[a][b] = 1;
            break;
            case 'L':
                update(a, b, -1);
                aa[a][b] = 0;
            break;
            case 'S':
                if (aa[a][b] || aa[a+1][b-1])
                    printf("No\n");
                else
                    printf("%i\n", query(a, b) + query(a+1, b-1));
            break;
        }
    }
    int mi1 = INT_MAX, mi2 = INT_MAX;
    for (int x = l+1; x <= l+900; x++)
    {
        for (int y = 1; y <= 1000; y++)
        {
            int yy = y, xx = x;
            convert(xx, yy);
            if (aa[xx][yy])
                continue;
            int v = query(xx, yy);
            if (v <= mi1)
                mi2 = mi1, mi1 = v;
            else if (v < mi2)
                mi2 = v;
        }
    }
    printf("%i\n", mi1+mi2);
}

