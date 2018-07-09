#include <bits/stdc++.h>

using namespace std;

vector<int> aa;
vector<int> l;

int lis()
{
    int ma = 0;
    for (int i = 0; i < aa.size(); i++)
    {
        l[i] = aa[i];
        for (int j = 0; j < i; j++) 
            if (aa[i] > aa[j] && l[i] < l[j] + aa[i])
                l[i] = l[j] + aa[i];
    }

    for (int i = 0; i < aa.size(); i++)
        ma = max(ma, l[i]);
  
    return ma;
}

int main()
{
    int n;
    scanf("%i", &n);
    aa.resize(n);
    l.resize(n);
    for (int x = 0; x < n; x++)
        scanf("%i", &aa[x]);
    printf("%i\n", lis());
    return 0;
}
