#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, a;
    scanf("%i", &n);
    vector<int> aa;
    while (n--)
    {
        scanf("%i", &a);
        aa.push_back(a);
    }
    sort(aa.begin(), aa.end());
    for (auto &x : aa) printf("%i\n", x);
    return 0;
}
