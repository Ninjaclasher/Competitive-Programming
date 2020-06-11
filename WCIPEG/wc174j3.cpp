#include <bits/stdc++.h>

using namespace std;

int main()
{
    set<string> aa;
    aa.insert("Mind");
    aa.insert("Power");
    aa.insert("Reality");
    aa.insert("Soul");
    aa.insert("Space");
    aa.insert("Time");
    int n;
    scanf("%i", &n);
    string a;
    while (n--)
    {
        cin>>a;
        aa.erase(a);
    }
    for (auto &x : aa)
        cout<<x<<"\n";
}
