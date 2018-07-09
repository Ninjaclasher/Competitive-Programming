#include <bits/stdc++.h>

using namespace std;

vector<int> BIT;

void update(int idx, int val)
{
    for (; idx < BIT.size(); idx+= idx&-idx)
        BIT[idx]+=val;
}

int sum(int idx)
{
    int ss = 0;
    for (; idx > 0; idx-=idx&-idx)
        ss += BIT[idx];
    return ss;
}


int main()
{
    int n, q, a, b;
    scanf("%i%i", &n, &q);
    BIT.resize(n+1);
    stack<pair<int,int>> ss;
    ss.push(make_pair(INT_MAX,0));
    vector<vector<int>> greater (n);
    vector<pair<pair<int,int>,int>> qq;
    for (int x = 1; x <= n; x++)
    {
        scanf("%i", &a);
        while (ss.top().first < a) ss.pop();
        greater[ss.top().second].push_back(x);
        ss.push(make_pair(a,x));
    }
    while (q--)
    {
        scanf("%i%i", &a, &b);
        qq.push_back(make_pair(make_pair(a,b),q));
    }
    sort(qq.begin(),qq.end());
    vector<pair<int,int>> ans;
    int pos = 0;
    for (auto &x : qq)
    {
        while (x.first.first > pos)
        {
            for (auto &x : greater[pos])
                update(x, 1);
            pos++;
        }
        ans.push_back(make_pair(x.second, sum(x.first.second)-sum(x.first.first-1)));
    }
    sort(ans.rbegin(),ans.rend());
    for (auto &x : ans)
        printf("%i\n", x.second);
    return 0;
}
