#include <bits/stdc++.h>

using namespace std;

vector<int> mot = {0,990,1010,1970,2030,2940,3060,3930,4060,4970,5030,5990,6010,7000};
int a, b, c, n;
long long dp[100];

long long next(int p)
{
    if (~dp[p])
        return dp[p];
    if (mot[p] == 7000)
        return dp[p] = 1;
    dp[p] = 0;
    for (int x = p+1; x < mot.size(); x++)
        if (mot[x]-mot[p] >= a && mot[x]-mot[p] <= b)
            dp[p] += next(x);
    return dp[p];
}

int main()
{
    memset(dp, -1, sizeof dp);
    scanf("%i%i%i", &a, &b, &n);
    while (n--)
    {
        scanf("%i", &c);
        mot.push_back(c);
    }
    sort(mot.begin(), mot.end());
    printf("%lli\n", next(0));
    return 0;
}
