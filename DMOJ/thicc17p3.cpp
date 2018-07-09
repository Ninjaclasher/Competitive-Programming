#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, q, target, y, dayNum = 1;
    scanf("%i", &n);
    vector<vector<pair<int,int>>> l (n);
    for (auto &x : l)
        x.resize(1, make_pair(0,0));
    for (int x = 0; x < n; x++)
        scanf("%i", &l[x][0].first);
    scanf("%i", &q);
    while (q--)
    {
        char t;
        scanf(" %c %i%i", &t, &target, &y);
        if (t == 'C')
        {
            l[target-1].push_back(make_pair(y, dayNum));
            dayNum++;
        }
        else if (t == 'Q')
        {
            int check = l[target-1].size();
            while(l[target-1][--check].second > y);
            printf("%i\n", l[target-1][check].first);
        }
    }
}
