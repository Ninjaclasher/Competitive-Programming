#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    scanf("%i", &n);
    vector<int> ret;
    for (int x = 0; x < n; x++)
    {
        vector<int> cur(n);
        for (auto &y : cur)
            scanf("%i", &y);
        sort(cur.begin(), cur.end());
        ret.push_back(cur[n/2]);
    }
    sort(ret.begin(), ret.end());
    printf("%i\n", ret[n/2]);
}
