#include <bits/stdc++.h>

using namespace std;

int main() 
{
    long long n, m, p = 0;
    scanf("%lli%lli", &n, &m);
    vector<long long> prime;
    vector<bool> pp(100001, true), ppp(100000001, true);
    for (int x = 2, y; x < pp.size(); x++)
        if (pp[x])
            for (y = x*x, prime.push_back(x); y < pp.size(); pp[y] = false, y += x);
    for (auto &x : prime)
        for (long long y = n+x-((n%x) ? n%x : x); y <= m-m%x; y+=x)
            ppp[y-n] = false;
    for (long long x = n; x < m; p += ((x < 100000 && pp[x]) || ppp[x-n]), x++);
    printf("%lli", p);
}
