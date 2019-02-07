#include <bits/stdc++.h>

using namespace std;

int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);
    int n;
    cin>>n;
    multiset<string> mp;
    string a;
    for (int x = 0; x < n; x++)
    {
        cin>>a;
        mp.insert(a);
    }
    for (int x = 1; x < n; x++)
    {
        cin>>a;
        mp.erase(mp.find(a));
    }
    cout<<*mp.begin()<<"\n";
}
