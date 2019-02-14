#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, m;
    scanf("%i", &n);
    vector<int> aa(n);
    for(auto &x : aa)
        scanf("%i", &x);
    scanf("%i", &m);
    vector<int> bb(m);
    for (auto &x : bb)
        scanf("%i", &x);
    vector<int> pos(1000005);
    int c = 0;
    for (auto &x : aa)
        pos[x] = ++c;
    vector<int> act;
    for (auto &x : bb)
        if (pos[x])
            act.push_back(pos[x]);
    vector<int> lis;
    for (auto &x : act)
    {
        if (lis.empty() || x > lis.back())
            lis.push_back(x);
        else
            *(lower_bound(lis.begin(), lis.end(), x)) = x;
    }
    printf("%lu\n", lis.size());
}
