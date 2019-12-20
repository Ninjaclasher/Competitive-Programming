#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, k, a;
    scanf("%i%i", &n, &k);
    map<int,int> mp;
    while (n--)
    {
        scanf("%i", &a);
        printf("%i\n", mp[a]);
        mp[a]++;
    }
    printf("%lu\n", mp.size());
}
