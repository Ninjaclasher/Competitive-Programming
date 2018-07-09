#include <bits/stdc++.h>

using namespace std;

int main() 
{
    int i, n, j, a, b, k, c = 0;
    scanf("%i%i%i", &i, &n, &j);
    vector<int> aa(i+2);
    while(j--)
    {
        scanf("%i%i%i", &a, &b, &k);
        aa[a]+=k;
        aa[b+1]-=k;
    }
    for (int x = 1; x < aa.size() - 1; x++)
    {
        aa[x] += aa[x-1];
        c += aa[x] < n;
    }
    printf("%i", c);
    return 0;
}
