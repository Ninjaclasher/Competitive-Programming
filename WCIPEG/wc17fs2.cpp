#include <bits/stdc++.h>

using namespace std;

vector<int> par(100001), rnk(100001);

int find(int n)
{
    if (par[n] ^ n)
        par[n] = find(par[n]);
    return par[n];
}

bool merge(int a, int b)
{
    a = find(a), b = find(b);
    if (a == b)
        return false;
    if (rnk[a] > rnk[b])
        par[b] = a;
    else
        par[a] = b;
    if (rnk[a] == rnk[b])
        rnk[b]++;
    return true;
}


struct ed
{
    int a, b, w;
    friend bool operator<(ed &aa, ed &bb)
    {
        return aa.w < bb.w;
    }
};

int main()
{
    iota(par.begin(), par.end(), 0);
    int n, m, a, b, c;
    scanf("%i%i", &n, &m);
    vector<ed> edd(m);
    for (auto &x : edd)
        scanf("%i%i%i", &x.a, &x.b, &x.w);
    sort(edd.rbegin(), edd.rend());
    c = 0;
    long long cc = 0;
    for (auto &x : edd)
    {
        if (merge(x.a, x.b))
        {
            c++;
            cc+=x.w;
        }
        else if (x.w >= 0)
            cc += x.w;
    }
    if (c < n-1)
        printf("Impossible\n");
    else
        printf("%lli\n", cc);
}
