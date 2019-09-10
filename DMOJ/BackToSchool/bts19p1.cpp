#include <bits/stdc++.h>

using namespace std;

int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);
    int n;
    cin>>n;
    assert(1 <= n && n <= 100);
    vector<string> arr(n);
    for (auto &x : arr)
        cin>>x, assert(1 <= x.length() && x.length() <= 100);
    string s, ans;
    cin>>s;
    assert(1 <= s.length() && s.length() <= 100);
    for (auto &x : arr)
        for (auto &y : arr)
            if (x.begin() != y.begin())
                assert(x.length() != y.length());
    for (auto &x : arr)
        if (x.length() <= s.length() && x.length() > ans.length())
            ans = x;
    printf("%s\n", ans.c_str());
}
