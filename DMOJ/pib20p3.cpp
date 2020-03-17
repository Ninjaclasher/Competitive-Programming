#include <bits/stdc++.h>

using namespace std;

int main()
{
    int q;
    scanf("%i", &q);
    vector<int> par(q+1);
    vector<int> cnt(q+1);
    int _rule = 0;
    while (q--)
    {
        int t, a;
        scanf("%i", &t);
        if (t == 1)
        {
            ++_rule;
            par[_rule] = _rule;
            cnt[par[_rule]]++;
        }
        else if (t == 2)
        {
            ++_rule;
            par[_rule] = par[_rule-1];
            cnt[par[_rule]]++;
        }
        else if (t == 3)
        {
            scanf("%i", &a);
            printf("%i\n", (a - (par[a] + cnt[par[a]] - 1) + 1) & 1);
        }
    }
}
