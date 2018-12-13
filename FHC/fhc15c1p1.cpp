#include <bits/stdc++.h>

using namespace std;

int main() 
{
    vector<int> aa(10000001);
    for (int x = 2; x < aa.size(); x++)
    {
        if (!aa[x])
        {
            aa [x]++;
            for (int y = x+x; y < aa.size(); y += x)
                aa[y]++;
        }
    }
    int t, a, b, k;
    scanf("%i", &t);
    for (int x = 1; x <= t; x++)
    {
        scanf("%i%i%i", &a, &b,&k);
        int c = 0;
        for (int y = a; y <= b; y++)
            c += (aa[y] == k);
        printf("Case #%i: %i\n", x, c);
    }
    return 0;
}
