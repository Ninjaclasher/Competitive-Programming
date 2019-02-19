#include <bits/stdc++.h>

using namespace std;

int main()
{
    int b = 0, g = 0;
    int n, m, k;
    scanf("%i%i%i", &n, &m, &k);
    for (int x = 0; x < k; x++)
    {
        if ((n>>x&1) ^ (m>>x&1))
            b++;
        else
            g++;
    }
    cout<<b<<" "<<g<<endl;
}
