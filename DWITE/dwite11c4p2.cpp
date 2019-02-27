#include <bits/stdc++.h>

using namespace std;

int main()
{
    for (int iii = 0; iii < 5; iii++)
    {
        vector<int> cnt(10001);
        int n;
        scanf("%i", &n);
        for (int x = 2; x <= n; x++)
        {
            int y = x;
            for (int z = 2; z*z <= y; z++)
            {
                while (y%z == 0)
                    cnt[z]++, y /= z;
            }
            if (y > 1)
                cnt[y]++;
        }
        vector<pair<int,int>> pr;
        for (int x = 2; x < cnt.size(); x++)
            if (cnt[x])
                pr.push_back({x, cnt[x]});
        for (int x = 0; x < pr.size(); x++)
        {
            printf("%i^%i", pr[x].first, pr[x].second);
            if (x < pr.size()-1)
                printf(" * ");
            else
                printf("\n");
        }
    }
}
