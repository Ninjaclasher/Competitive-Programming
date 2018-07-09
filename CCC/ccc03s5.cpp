#include <bits/stdc++.h>

using namespace std;

vector<int> par (10001), rnk(10001), dest(10001);

int find(int n)
{
    if (n != par[n])
        par[n] = find(par[n]);
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
    vector<pair<int,pair<int,int>>> edge;
    int n, m, d, a, b, c;
    scanf("%i%i%i", &n, &m, &d);
    while (m--)
    {
        scanf("%i%i%i", &a, &b, &c);
        edge.push_back(make_pair(c, make_pair(a, b)));
    }
    sort(edge.rbegin(), edge.rend());
    for (int x = 0; x < d; x++)
    {
        scanf("%i", &a);
        dest[a] = true;
    }
    for (auto &x : edge)
    {
        a = x.second.first, b = x.second.second, c = x.first;
        if (merge(a, b) && d)
        {
            if (dest[a]) dest[a] = false, d--;
            if (dest[b]) dest[b] = false, d--;
        }
        if (!d)
        {
            printf("%i", c);
            break;
        }
    }
    return 0;
}
