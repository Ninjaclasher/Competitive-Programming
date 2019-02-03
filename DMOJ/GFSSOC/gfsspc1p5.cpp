#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, t;
    scanf("%i%i", &n, &t);
    vector<int> a1, a2;
    int a, mi = INT_MAX;
    for (int x = 0; x < n; x++)
    {
        scanf("%i", &a);
        if (a < 0)
            a1.push_back(-a);
        else
            a2.push_back(a);
    }
    sort(a1.begin(), a1.end());
    sort(a2.begin(), a2.end());
    if (a1.size() >= t)
        mi = min(mi, a1[t-1]);
    if (a2.size() >= t)
        mi = min(mi, a2[t-1]);
    for (int x = 0; x < min(t, (int)a1.size()) - 1; x++)
    {
        if (t - x - 2 < a2.size())
        {
            int cur = a1[x] * 2 + a2[t - x - 2];
            mi = min(mi, cur);
        }
    }
    for (int x = 0; x < min(t, (int)a2.size()) - 1; x++)
    {
        if (t - x - 2 < a1.size())
        {  
            int cur = a2[x] * 2 + a1[t - x - 2];
            mi = min(mi, cur);
        }
    }
    printf("%i\n", mi);
}

