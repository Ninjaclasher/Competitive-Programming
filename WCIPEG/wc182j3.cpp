#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    int m;
    cin>>n;
    vector<string> a(n);
    for (auto &x : a)
        cin>>x;
    cin>>m;
    vector<string> b(m);
    for (auto &x : b)
        cin>>x;
    int cnt = 0;
    for (auto &x : a)
        for (auto &y : b)
            if (x == y)
                cnt++;
    cout<<cnt;
}
