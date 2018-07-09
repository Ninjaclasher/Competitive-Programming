#include <bits/stdc++.h>

using namespace std;

int main() 
{
    int t, c, i = 0;
    scanf("%i%i", &t, &c);
    vector<int> aa (c);
    for (int x = 0; x < c; x++)
        scanf("%i", &aa[x]);
    sort(aa.begin(), aa.end());
    while (t-aa[i] >= 0) t -= aa[i++];
    printf("%i", i);
    return 0;
}
