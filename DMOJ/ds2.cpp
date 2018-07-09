#include <bits/stdc++.h>

using namespace std;

vector<int> rnk, par;

int find(int a)
{
    if (a != par[a])
        par[a] = find(par[a]);
    return par[a];
}

void merge(int a, int b)
{
    a = find(a), b = find(b);
    if (rnk[a] > rnk[b])
        par[b] = a;
    else
        par[a] = b;
    if (rnk[a] == rnk[b])
        rnk[b]++;
}

int main() 
{
    int n, m, a, b;
    scanf("%i%i", &n, &m);
    rnk.resize(n+1, 1);
    par.resize(n+1);
    iota (par.begin(), par.end(), 0);
    vector<int> MST;
    for (int x = 0; x < m; x++)
    {
        scanf("%i%i", &a, &b);
        a = find(a), b = find(b);
        if (a != b)
        {
            MST.push_back(x+1);
            merge(a,b);
        }
        if (MST.size() == n-1) break;
    }
    if (MST.size() != n-1)
        printf("Disconnected Graph");
    else
        for (auto &x : MST)
            printf("%i\n", x);
    return 0;
}
