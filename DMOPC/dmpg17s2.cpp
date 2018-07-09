#include <bits/stdc++.h>

using namespace std;

vector<int> par(100005), rnk(100005);

int find(int n)
{
    if (n != par[n]) return par[n] = find(par[n]);
    return par[n];
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

int main() 
{
    int n, q, a, b;
    char t;
    scanf("%i%i", &n, &q);
    iota(par.begin(), par.end(), 0);
    while (q--)
    {
        scanf(" %c%i%i", &t, &a, &b);
        if (t == 'A')
            merge(a, b);
        else
            printf("%c\n", find(a) == find(b) ? 'Y' : 'N');
    }
    return 0;
}
