#include <bits/stdc++.h>

using namespace std;

vector<int> par(2000005), rnk(2000005), v(2000005);

int find(int n)
{
    if (n ^ par[n]) return par[n] = find(par[n]);
    return n;
}

void merge(int a, int b)
{
    a = find(a), b = find(b);
    if (a == b) return;
    if (rnk[a] > rnk[b])
        par[b] = a;
    else
        par[a] = b;
    if (rnk[a] == rnk[b])
        rnk[b]++;
}

int m;

void run(int b, vector<int> &cur)
{
    if (cur.size() < 2) return;
    if (!~b)
    {
        for (int x = 0; x < (int)cur.size()-1; x++)
            merge(cur[x], cur[x+1]);
        return;
    }
    vector<vector<int>> bi(2);
    for (auto x : cur)
        bi[((v[x]>>b)&1)].push_back(x);
    if((m>>b)&1)
    {
        for (int x = 0; x < (int)bi[1].size()-1; x++)
            merge(bi[1][x], bi[1][x+1]);
        for (int x = 0; x < (int)bi[0].size()-1; x++)
            merge(bi[0][x], bi[0][x+1]);
        run(b-1, cur);
    }
    else
        run(b-1, bi[0]), run(b-1, bi[1]);
}

int main()
{
    iota(par.begin(), par.end(), 0);
    int n, q, a, b;
    scanf("%i%i%i", &n, &m, &q);
    for (int x = 1; x <= n; x++)
        scanf("%i", &v[x]);
    vector<int> t(n);
    iota(t.begin(), t.end(), 1);
    run(30, t);
    while(q--)
    {
        scanf("%i%i", &a, &b);
        printf("%s\n", find(a) == find(b) ? "YES" : "NO");
    }
}
