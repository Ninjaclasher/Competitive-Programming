#include <bits/stdc++.h>

using namespace std;

int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);
    int xe, ye;
    cin>>xe>>ye;
    int n, m, c;
    cin>>n>>m>>c;
    vector<int> v(n), h(m);
    for (auto &x : v)
        cin>>x;
    for (auto &x : h)
        cin>>x;
    v.push_back(INT_MIN);
    v.push_back(INT_MAX);
    h.push_back(INT_MIN);
    h.push_back(INT_MAX);
    sort(v.begin(), v.end());
    sort(h.begin(), h.end());
    int vv = 0;
    for (; vv < v.size()-1; vv++)
        if (v[vv] < xe && v[vv+1] > xe)
            break;
    int hh = 0;
    for (; hh < h.size()-1; hh++)
        if (h[hh] < ye && h[hh+1] > ye)
            break;
    int ly = h[hh], ry = h[hh+1];
    int lx = v[vv], rx = v[vv+1];
    while (c--)
    {
        int i, j;
        cin>>i>>j;
        if (lx < i && i < rx && ly < j && j < ry)
            cout<<"Y\n";
        else
            cout<<"N\n";
    }
}
