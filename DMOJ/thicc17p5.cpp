#include <bits/stdc++.h>

using namespace std;

vector<int> ff(1000005);

int main() 
{
    int n, k;
    scanf("%i%i", &n, &k);
    vector<int> f(n);
    for (auto &x : f)
        scanf("%i", &x);
    int a = 0, b = 0, c = 0;
    long long t = 0;
    for (; c < k; b++)
    {
        ff[f[b]]++;
        c += (ff[f[b]] == 1);
    }
    --b;
    while (b < n)
    {
        while (c >= k)
        {
            ff[f[a]]--;
            c -= (!ff[f[a]]);
            a++;
        }
        a--;
        ff[f[a]]++;
        c += (ff[f[a]]==1);
        t += a+1;
        b++;
        ff[f[b]]++;
        c += (ff[f[b]] == 1);
    }
    printf("%lli", t);
    return 0;
}
