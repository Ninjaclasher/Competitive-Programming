#include <bits/stdc++.h>

using namespace std;

vector<int> cnt(1<<21);

bool comp(int a, int b)
{
    return cnt[a] < cnt[b];
}

int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);
    int n;
    cin>>n;
    for (int x = 0; x < (1<<20); x++)
        cnt[x] = __builtin_popcount(x);
    vector<string> aa(n);
    vector<int> msk(n);
    int tot = (1<<20)-1;
    for (int i = 0; i < n; i++)
    {
        auto &x = aa[i];
        cin>>x;
        if (x == "")
            abort();
        sort(x.begin(), x.end());
        for (int y = 0; y < x.size(); y++)
            msk[i] |= 1<<(x[y]-'a');
        tot |= msk[i];
    }
    vector<int> kkk;
    for (int x = 0; x < (1<<20); x++)
        if ((tot&x) == x)
            kkk.push_back(x);
    sort(kkk.begin(), kkk.end(), comp);
    for (auto &x : kkk)
    {
        int cc = 0;
        for (int y = 0; cc < 2 && y < n; y++)
            if ((x&msk[y]) == x)
                cc++;
        if (cc == 1)
            return 0 * printf("%i\n", cnt[x]);
    }
    printf("-1\n");  
}
