#include <bits/stdc++.h>

using namespace std;

vector<int> pp, bit;

void update(int x, int v)
{
    for (; x < bit.size(); x+=x&-x)
        bit[x] += v;
}

int sum(int x)
{
    int s = 0;
    for (; x > 0; x -= x&-x)
        s += bit[x];
    return s;
}

int main()
{
    int n, rp=1, lp=1, len=1, a;
    scanf("%i", &n);
    pp.resize(n+1), bit.resize(n+1);
    map<int,int> pos;
    for (int x = 1; x <= n; x++)
    {
        scanf("%i", &a);
        pos[a] = x;
    }
    for (int x = 1; x <= n; x++)
    {
        scanf("%i", &a);
        pp[x] = pos[a];
    }
    for (int x = 2, l = 1; x <= n; x++)
    {
        if (pp[x] < pp[x-1]) l = x;
        if (x-l+1 > len) len = x-l+1, lp = l, rp = x;
    }
    printf("%i\n", n-len);
    for (int x = 1; x <= n; x++)
        update(x, 1);
    for (int x = rp+1; x <= n; x++)
    {
        int t = sum(pp[x]);
        update(pp[x], -1);
        printf("B %i\n", t);
    }
    for (int x = lp-1, c = 0; x > 0; x--, c++)
    {
        int t = sum(pp[x])+c;
        update(pp[x], -1);
        printf("F %i\n", t);
    } 
}
