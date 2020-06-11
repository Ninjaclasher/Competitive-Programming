#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100005;

vector<int> par(MAXN);

int find(int n)
{
    if (n == par[n])
        return n;
    return par[n] = find(par[n]);
}

vector<char> typ(MAXN);

int main()
{
    iota(par.begin(), par.end(), 0);
    int n, m, k, a, b, c;
    scanf("%i%i%i", &n, &m, &k);
    for (int x = 1; x <= n; x++)
        scanf(" %c", &typ[x]);
    while (m--)
    {
        scanf("%i%i", &a, &b);
        if (typ[a] == typ[b])
            par[find(a)] = find(b);
    }
    int cnt = 0;
    while (k--)
    {
        scanf("%i%i", &a, &b);
        if (find(a) == find(b))
            cnt++;
    }
    printf("%i\n", cnt);
}
