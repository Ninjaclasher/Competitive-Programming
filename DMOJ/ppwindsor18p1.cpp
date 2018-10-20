#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    scanf("%i", &n);
    long long sum = 0;
    for (int x = 1; x <= n; x++)
    {
        if (n%x == 0)
            sum += x;
    }
    printf("%lli\n", sum);
}
