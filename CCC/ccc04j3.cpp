#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, m;
    scanf("%i%i", &n, &m);
    vector<string> a(n), b(m);
    for (auto &x : a)
        cin>>x;
    for (auto &x : b)
        cin>>x;
    for (auto &x : a)
        for (auto &y : b)
            cout<<x<<" as "<<y<<"\n";
}
