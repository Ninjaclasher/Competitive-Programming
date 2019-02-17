#include <bits/stdc++.h>

using namespace std;

struct voter
{
    queue<int> choices;
};

int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);
    int n, m;
    cin>>n>>m;
    assert(1 <= n && n <= 20);
    assert(1 <= m && m <= 10000);
    map<string,int> mp;
    vector<string> cand(n);
    vector<vector<voter>> vot(n);
    vector<bool> elim(n);
    for (int x = 0; x < n; x++)
    {
        cin>>cand[x];
        assert(cand[x].size() <= 20);
        mp[cand[x]] = x;
    }
    string b;
    while (m--)
    {
        int a;
        cin>>a;
        assert(1 <= a && a <= 20);
        voter v;
        while (a--)
        {
            cin>>b;
            if (!mp.count(b))
                abort();
            v.choices.push(mp[b]);
        }
        vot[v.choices.front()].push_back(v);
    }
    for (int left = 0; left < n-1; left++)
    {
        int bst = 0;
        for (int x = 0; x < n; x++)
            if (!elim[x] && (vot[bst].size() > vot[x].size() || elim[bst]))
                bst = x;
        elim[bst] = 1;
        for (auto &x : vot[bst])
        {
            while (!x.choices.empty() && elim[x.choices.front()])
                x.choices.pop();
            if (!x.choices.empty())
                vot[x.choices.front()].push_back(x);
        }
        vot[bst].clear();
    }
    for (int x = 0; x < n; x++)
    {
        if (!elim[x])
        {
            cout<<cand[x]<<"\n";
            return 0;
        }
    }
}
