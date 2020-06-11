#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, m, S;
    cin>>n>>m>>S;
    multiset<int> s;
    int a;
    for (int x = 0; x < n; x++)
    {
        cin>>a;
        s.insert(a);
    }
    int cnt = 0;
    while (S && !s.empty())
    {
        auto it = s.lower_bound(m-S);
        if (it != s.begin())
            --it;
        if (*it == 0 && S < 2)
        {
            ++it;
            if (it == s.end())
                --it;
        }
        S = min(m+1, S+*it);
        s.erase(it);
        S--;
        cnt++;
    }
    cout<<cnt<<endl;
}
