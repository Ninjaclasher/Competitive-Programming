#include <bits/stdc++.h>

using namespace std;

int main() 
{
    int w, n, s = 0;
    scanf("%i%i", &w, &n);
    vector<int> aa(n);
    for (int x = 0; x < n; x++)
    {
        scanf("%i", &aa[x]);
        s += aa[x];
        if (x > 3)
            s-= aa[x-4];
        if (s > w)
        {
            printf("%i", x);
            return 0;
        }
    }
    printf("%i", n);
    return 0;
}
