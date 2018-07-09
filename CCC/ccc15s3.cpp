#include <bits/stdc++.h>

using namespace std;

vector<int> par (100001);

int find(int n)
{
    if (n != par[n])
        par[n] = find(par[n]);
    return par[n];
}

int main() 
{
    iota(par.begin(), par.end(), 0);
    int g, p, a, t = 0;
    scanf("%i%i", &g, &p);
    while (p--)
    {
        scanf("%i", &a);
        a = find(a);
        if (!a)
        {
            printf("%i", t);
            return 0;
        }
        par[a] = find(a-1);
        t++;
    }
    printf("%i", t);
    return 0;
}
