#include <bits/stdc++.h>

using namespace std;

int main() 
{
    int n, xx;
    scanf("%i%i", &n, &xx);
    vector<bool> pr(n+1, true);
    pr[0] = pr[1] = false;
    vector<int> prr;
    for (int x = 2; x < pr.size(); x++)
    {
        if (pr[x])
        {
            prr.push_back(x);
            for (int y = x*x; y < pr.size(); y += x)
                pr[y] = false;
        }
    }
    long long w = 0;
    for (auto &x : prr)
    {
        int nn = n-x;
        w += nn/xx + 1;
        nn--;
        if (nn >= 0)
            w += nn/xx + 1;
    }
    printf("%lli", w);
    return 0;
}
