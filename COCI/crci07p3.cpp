#include <bits/stdc++.h>

using namespace std;

struct ingredient
{
    int x, y, sm, pm, sv, pv, hasSmall = 0, hasLarge = 0;
    friend bool operator<(ingredient a, ingredient b)
    {
        return a.y/a.x < b.y/b.x;
    }
};

vector<ingredient> arr;

int m;

long long minCost(int s, ingredient a)
{
    long long mi = LONG_MAX;
    for (int large = 0;; large++)
    {
        long long cur = s*a.x-a.y-large*a.sv;
        if (cur < 0)
        {
            mi = min(mi, (long long)large*a.pv);
            break;
        }
        long long sneeded = (cur+a.sm-1)/a.sm;
        mi = min(mi, large*a.pv + sneeded*a.pm);
    }
    return mi;
}

bool run(int s)
{
    long long cst = 0;
    for (auto &x : arr)
        cst += minCost(s, x);
    return cst <= m;
}


int main()
{
    int n;
    scanf("%i%i", &n, &m);
    int a, b, c, d, e, f;
    for (int x = 0; x < n; x++)
    {
        scanf("%i%i%i%i%i%i", &a, &b, &c, &d, &e, &f);
        arr.push_back(ingredient{a, b, c, d, e, f, 0});
    }
    int l = 0, r = 100000;
    while (l <= r)
    {
        int M = l+r>>1;
        if (run(M))
            l = M+1;
        else
            r = M-1;
    }
    printf("%i\n", r);
}

