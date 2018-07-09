#include <bits/stdc++.h>

using namespace std;

int main()
{
    vector<vector<int>> aa(3);
    int n, a;
    scanf("%i", &n);
    while(n--)
    {
        scanf("%i", &a);
        aa[a%3].push_back(a);
    }
    vector<int> ans;
    while (aa[0].size() > 1)
    {
        ans.push_back(aa[0].back());
        aa[0].pop_back();
        if (!aa[1].empty())
            ans.push_back(aa[1].back()), aa[1].pop_back();
        else if (!aa[2].empty())
            ans.push_back(aa[2].back()), aa[2].pop_back();
        else
            return 0 * printf("impossible");
    }
    while (!aa[1].empty())
        ans.push_back(aa[1].back()), aa[1].pop_back();
    if (!aa[0].empty())
        ans.push_back(aa[0].back());
    else if (!ans.empty())
        return 0 * printf("impossible");
    while (!aa[2].empty())
        ans.push_back(aa[2].back()), aa[2].pop_back();
    for (auto x : ans)
        printf("%i ", x);
}
