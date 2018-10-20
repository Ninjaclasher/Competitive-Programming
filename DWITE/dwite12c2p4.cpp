#include <bits/stdc++.h>

using namespace std;

int main()
{
    for (int i = 0; i < 5; i++)
    {
        int n;
        scanf("%i", &n);
        vector<int> arr(n), perm(n);
        iota(perm.begin(), perm.end(), 1);
        for (auto &x : arr)
            scanf("%i", &x);
        vector<int> ans(n);
        for (int x = 0; x < n; x++)
        {
            if (perm.size() <= arr[x])
            {
                printf("IMPOSSIBLE\n");
                goto nxt;
            }
            auto it = perm.end()-arr[x]-1;
            ans[x] = *it;
            perm.erase(it);
        }
        for (auto &x : ans)
            printf("%i ", x);
        printf("\n");
nxt:;
    }
}
