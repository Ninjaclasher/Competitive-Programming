#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    scanf("%i", &n);
    long long ans = 0;
    vector<long long> xx(100005), yy(100005);
    vector<pair<int,int>> arr(n);
    for (auto &x : arr)
    {
        scanf("%i%i", &x.first, &x.second);
        xx[x.first]++;
        yy[x.second]++;
    }
    for (auto &x : arr)
        ans += (xx[x.first]-1)*(yy[x.second]-1);
    printf("%lli\n", ans);
}

