#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> par(2, vector<int>(100005)), rnk(2, vector<int>(100005));

int find(int i, int n)
{
    if (par[i][n] ^ n)
        return par[i][n] = find(i, par[i][n]);
    return n;
}

bool merge(int i, int a, int b)
{
    a = find(i, a), b = find(i, b);
    if (a == b) return false;
    if (rnk[i][a] > rnk[i][b])
        par[i][b] = a;
    else
        par[i][a] = b;
    if (rnk[i][a] == rnk[i][b])
        rnk[i][b]++;
    return true;
}

struct ed
{
    int a, b, c, i;
    friend bool operator<(ed &a, ed &b)
    {
        return a.c < b.c;
    }
};

vector<ed> aa;

int main()
{
    iota(par[0].begin(), par[0].end(), 0);
    iota(par[1].begin(), par[1].end(), 0);
    int n, m, p, q, a, b, c;
    long long s = 0, ms = 0;
    scanf("%i%i%i%i", &n, &m, &p, &q);
    while (p--)
    {
        scanf("%i%i%i", &a, &b, &c);
        aa.push_back({a,b,c,0});
        s += c*(long long)n;
    }
    while (q--)
    {
        scanf("%i%i%i", &a, &b, &c);
        aa.push_back({a,b,c,1});
        s += c*(long long)m;
    }
    sort(aa.begin(), aa.end());
    vector<int> cnt(2);
    for (auto &x : aa)
    {
        if (merge(x.i, x.a, x.b))
        {
            cnt[x.i]++;
            ms += ((x.i ? m : n) - cnt[!x.i])*(long long)x.c;
        }
    }
    printf("%lli", s - ms);
}
