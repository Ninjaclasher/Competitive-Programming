#include <bits/stdc++.h>

using namespace std;

int main() 
{
    int n, a, ma = 0;
    vector<int> sq (31);
    scanf("%i", &n);
    while (n--)
    {
        scanf("%i", &a);
        sq[log2(a)]++;
        ma = max(ma, (int)log2(a));
    }
    for (int x = 0; x < 31; x++)
    {
        sq[x+1]+=sq[x]>>1;
        if (sq[x+1] && x+1 > ma)
            ma = x+1;
    }
    printf("%lli", 1LL<<ma);
    return 0;
}
