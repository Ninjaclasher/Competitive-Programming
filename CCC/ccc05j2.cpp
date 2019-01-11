#include <bits/stdc++.h>

using namespace std;

int ctr(int n)
{
    int cnt = 0;
    for (int x = 1; x <= n; x++)
        if (n%x == 0)
            cnt++;
    return cnt;
}

int main()
{
    int a, b;
    scanf("%i%i", &a, &b);
    int ans = 0;
    for (int x = a; x <= b; x++)
        ans += (ctr(x) == 4);
    printf("The number of RSA numbers between %i and %i is %i\n", a, b, ans);
}

