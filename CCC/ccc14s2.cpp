#include <bits/stdc++.h>

using namespace std;

int main() 
{
    int n;
    scanf("%i", &n);
    map<string,string> mp;
    vector<string> a(n), b(n);
    for (auto &x : a) cin>>x;
    for (auto &x : b) cin>>x;
    for (int x = 0; x < n; x++)
    {
        if (a[x] == b[x])
        {
            cout<<"bad";
            return 0;
        }
        if (mp[a[x]] == "")
            mp[a[x]] = b[x];
        else if (mp[a[x]] != b[x])
        {
            cout<<"bad";
            return 0;
        }
        if (mp[b[x]] == "")
            mp[b[x]] = a[x];
        else if (mp[b[x]] != a[x])
        {
            cout<<"bad";
            return 0;
        }
    }
    cout<<"good";
    return 0;
}
