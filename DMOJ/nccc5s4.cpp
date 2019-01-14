#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, k;
    scanf("%i%i", &n, &k);
    vector<int> a(k);
    for (auto &x : a)
        scanf("%i", &x);
    sort(a.begin(), a.end());
    long long ans = 0;
    for (int x = 2; x < a.size(); x++)
        ans += ((x == a.size()-1 ? n+1 : a[x+1])-a[x]) * (long long)(a[x-2]);
    printf("%lli\n", ans);
}

