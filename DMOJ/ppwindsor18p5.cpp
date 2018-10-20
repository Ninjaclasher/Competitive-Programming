#include <bits/stdc++.h>

using namespace std;

int nth(int m)
{
    long long st = 1, len = 1, cnt = 9, n = m;
    while (n > len*cnt)
    {
        n -= len*cnt;
        len++;
        cnt *= 10;
        st *= 10;
    }
    st += (n-1)/len;
    return to_string(st)[(n-1)%len]-'0';
}

int main()
{
    int n;
    scanf("%i", &n);
    printf("%i\n", nth(n));
}
