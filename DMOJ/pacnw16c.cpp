#include <bits/stdc++.h>

using namespace std;

int main() 
{
    vector<int> aa(100005);
    int n, k, r, a, b = 0, c = 0;
    scanf("%i%i%i", &n, &k, &r);
    while (k--)
    {
        scanf("%i", &a);
        aa[a]++;
    }
    for (int x = 1; x <= r; x++)
        b += aa[x];
    for (int x = 1; x+r-1 <= n; x++)
    {
        int i = x+r-1;
        for (; b < 2; c++, b++)
        {
            while (aa[i])
                i--;
            aa[i]++;
        }
        b += aa[x+r]-aa[x];
    }
    printf("%i\n", c);
}
