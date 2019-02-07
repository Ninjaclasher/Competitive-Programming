#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, k, t;
    int ans = 0;
    scanf("%i%i", &n, &k);
    while (k--)
    {
        scanf("%i", &t);
        if (t == 1)
            ans += 30;
        else if (t == 2)
            ans += 60;
        else
            ans += 300;
    }
    n *= 60;
    if (ans <= n)
        printf("Continue\n");
    else
        printf("Return\n");
}
