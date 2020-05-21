#include <bits/stdc++.h>

using namespace std;

const int MAXN = 50005;

int par[128][MAXN], rnk[128][MAXN];

int find(int n, int i)
{
    if (par[i][n] == n)
        return n;
    return par[i][n] = find(par[i][n], i);
}

void merge(int a, int b, int i)
{
    a = find(a, i), b = find(b, i);
    if (a == b)
        return;
    if (rnk[i][a] > rnk[i][b])
        par[i][b] = a;
    else
        par[i][a] = b;
    if (rnk[i][a] == rnk[i][b])
        rnk[i][b]++;
}

int main()
{
    for (int x = 0; x < 128; x++)
    {
        iota(par[x], par[x]+MAXN, 0);
        fill(rnk[x], rnk[x]+MAXN, 1);
    }
    int n, m, q, a, b, c;
    scanf("%i%i%i", &n, &m, &q);
    while (m--)
    {
        scanf("%i%i%i", &a, &b, &c);
        for (int x = 0; x < 128; x++)
            if ((c | x) == x)
                merge(a, b, x);
    }
    while (q--)
    {
        scanf("%i%i", &a, &b);
        for (int x = 0; x < 128; x++)
        {
            if (find(a, x) == find(b, x))
            {
                printf("%i\n", x);
                break;
            }
        }
    }
}
