#include <bits/stdc++.h>

using namespace std;

struct num
{
    string a;
    friend bool operator<(num &aa, num &bb)
    {
        return aa.a+bb.a < bb.a+aa.a;
    }
}
;
int main()
{
    int n;
    scanf("%i", &n);
    vector<num> aa(n);
    for (auto &x : aa)
        cin>>x.a;
    sort(aa.rbegin(), aa.rend());
    for (auto &x : aa)
        cout<<x.a;
}
