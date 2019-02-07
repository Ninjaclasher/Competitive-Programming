#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, k;
    scanf("%i%i", &n, &k);
    int cnt = 0;
    while (n >= k)
    {
        cnt += k;
        n -= k-1;
    }
    cnt += n;
    printf("%i\n", cnt);
}
