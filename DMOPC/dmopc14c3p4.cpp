#include <bits/stdc++.h>

using namespace std;

int main() 
{
    int t;
    vector<int> pr(100050, 1);
    vector<vector<int>> kk(100050);
    kk[1].push_back(1);
    for (int x = 2; x < pr.size(); x++)
    {
        for (int y = x; y < pr.size(); y += x)
            pr[y]++;
        kk[pr[x]].push_back(x);
    }
    scanf("%i", &t);
    while (t--)
    {
        int k, a, b;
        scanf("%i%i%i", &k, &a, &b);
        printf("%i\n", upper_bound(kk[k].begin(), kk[k].end(), b) - lower_bound(kk[k].begin(), kk[k].end(), a));
    }
    return 0;
}
