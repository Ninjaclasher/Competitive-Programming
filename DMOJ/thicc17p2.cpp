#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long totalNum = 0, subtractNum = 0, a;
    int n, b, m;
    scanf("%i", &n);
    scanf("%lli%i%i", &a, &b, &m);
    for (int x = 0; x < n; x++)
        totalNum += a, subtractNum += (a*a)%1000000007, a = (a*b)%m;
    
    totalNum %= 1000000007;
    totalNum *= totalNum;
    totalNum -= (subtractNum%1000000007);
    totalNum %= 1000000007;
    if (totalNum < 0) totalNum += 1000000007;

    printf("%lli\n", totalNum % 1000000007);
}
