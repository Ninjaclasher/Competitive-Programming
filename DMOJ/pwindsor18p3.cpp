#include <bits/stdc++.h>

using namespace std;

bool prime(int n)
{
    for (int x = 2; x <= sqrt(n); x++)
        if (n%x == 0)
            return false;
    return true;
}

int main()
{
    int n;
    scanf("%i", &n);
    int cnt = 0, a;
    while (n--)
    {
        scanf("%i", &a);
        cnt += !prime(a);
    }
    printf("%i\n", cnt);
}
