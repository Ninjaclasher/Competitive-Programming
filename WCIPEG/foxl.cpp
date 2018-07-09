#include <bits/stdc++.h>

using namespace std;

map<int,int> par;

int find(int a)
{
    int &x = par[a];
    if (!x) x = a;
    else if (a != x) x = find(x);
    return x;
}

int main()
{
    int n, m, a, b;
    scanf("%i%i", &n, &m);
    while (m--)
    {
        scanf("%i%i", &a, &b);
        a = find(a), b = find(b);
        if (a != b) par[a] = b, n--;
    }
    printf("%i", n);
    return 0;
}

