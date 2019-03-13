#include <bits/stdc++.h>

using namespace std;

const int MAXN = 200005;

vector<int> par(MAXN);

int find(int n)
{
    if (n == par[n])
        return n;
    return par[n] = find(par[n]);
}

bool merge(int a, int b)
{
    a = find(a), b = find(b);
    if (a == b)
        return false;
    par[a] = b;
    return true;
}

int main()
{
    iota(par.begin(), par.end(), 0);
    int n, m, a, b;
    scanf("%i%i", &n, &m);
    int cc = 0;
    while (m--)
    {
        scanf("%i%i", &a, &b);
        cc += !merge(a, b);
    }
    printf("%s\n", cc <= 1 ? "YES" : "NO");
}
