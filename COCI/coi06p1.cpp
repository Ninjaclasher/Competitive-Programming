#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    unsigned long long a, total = 0;
    scanf("%i", &n);
    vector<unsigned long long> b; 
    for (int x = 0; x < n; x++)
    {
        scanf("%llu", &a);
        auto it = upper_bound(b.rbegin(), b.rend(), a);
        total += b.size() < it-b.rbegin()+1 ? b.size() : it-b.rbegin()+1;
        while (!b.empty() && b.back() < a)
            b.pop_back();
        b.push_back(a);
    }
    printf("%lli", total);
    return 0;
}
