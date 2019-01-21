#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    scanf("%i", &n);
    while (n--)
    {
        vector<string> aa(3);
        for (auto &x : aa)
            cin>>x;
        for (int x = 0; x < 3; x++)
        {
            for (int y = 0; y < 3; y++)
            {
                if (x == y || aa[x].size() > aa[y].size())
                    continue;
                if (aa[y].substr(0, aa[x].size()) == aa[x] || aa[y].substr(aa[y].size()-aa[x].size(), aa[x].size()) == aa[x])
                {
                    printf("No\n");
                    goto nxt;
                }
            }
        }
        printf("Yes\n");
nxt:;
    }
}
