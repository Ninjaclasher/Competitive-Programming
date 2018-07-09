#include <bits/stdc++.h>

using namespace std;

int main()
{
    int k, n, a;
    scanf("%i", &k);
    vector<int> aa (k);
    for (auto &x : aa)
        scanf("%i", &x);
    scanf("%i", &n);
    sort(aa.begin(),aa.end());
    while (n--)
    {
        scanf("%i", &a);
        printf("%i\n", a-(upper_bound(aa.begin(), aa.end(), a)-aa.begin()));
    }
}
