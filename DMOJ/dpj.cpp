#include <bits/stdc++.h>
 
using namespace std;
 
const int MAXN = 305;
 
long double dp[305][305][305];
int n;
 
 
long double solve(int s1, int s2, int s3)
{
    if (!s1 && !s2 && !s3)
        return 0;
    auto &cur = dp[s1][s2][s3];
    if (cur)
        return cur;
    cur = 1;
    if (s1)
        cur += s1/(long double)n * solve(s1-1, s2, s3);
    if (s2)
        cur += s2/(long double)n * solve(s1+1, s2-1, s3);
    if (s3)
        cur += s3/(long double)n * solve(s1, s2+1, s3-1);
    cur /= 1 - (n-s1-s2-s3)/(long double)n;
    return cur;
}
 
int main()
{
    int s[3] = {0, 0, 0};
    scanf("%i", &n);
    for (int x = 0; x < n; x++)
    {
        int a;
        scanf("%i", &a);
        s[a-1]++;
    }
    printf("%.30Lf\n", solve(s[0], s[1], s[2]));
}
