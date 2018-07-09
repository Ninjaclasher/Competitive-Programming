#include <bits/stdc++.h>

using namespace std;

struct ed
{
    int a, b, w;
    bool old;
    friend bool operator<(ed &a, ed &b)
    {
        return (a.w < b.w) || (a.w == b.w && a.old);
    }
};

vector<ed> mm;
vector<int> par(100001), rnk(100001);

int find(int n)
{
    if (par[n] != n) par[n] = find(par[n]);
    return par[n];
}

bool merge(int a, int b)
{
    a = find(a), b = find(b);
    if (a == b) return false;
    if (rnk[a] > rnk[b])
        par[b] = a;
    else
        par[a] = b;
    if (rnk[a] == rnk[b])
        rnk[b]++;
    return true;
}


int main() 
{
    iota(par.begin(), par.end(), 0);
    int n, m, d, a, b, c, dd = 0, ee = 0, me = 0;
    scanf("%i%i%i", &n, &m, &d);
    mm.resize(m);
    for (int x = 0; x < m; x++)
    {
        scanf("%i%i%i", &a, &b, &c);
        mm[x] = {a,b,c, x+1 < n};
    }
    sort(mm.begin(), mm.end());
    for (auto &x : mm)
    {
        if (merge(x.a, x.b))
        {
            ee++;
            me = x.w;
            if (!x.old) dd++;
            if (ee == n-1)
            {
                if (x.old)
                {
                    printf("%i", dd);
                    return 0;
                }
                break;
            }
        }
    }
    iota(par.begin(), par.end(), 0);
    for (auto &x : mm)
    {
        if (find(x.a) != find(x.b))
        {
            if (x.w < me || (x.w == me && x.old))
                merge(x.a, x.b);
            else if (x.old && x.w <= d)
                return 0 * printf("%i", dd-1);
        }
    }
    printf("%i", dd);
    return 0;
}
