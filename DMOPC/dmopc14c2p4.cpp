#include <bits/stdc++.h>
using namespace std;


int main ()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    int a,b,c, d, y;
    cin >> a;
    int t[a];
    cin >> t[0];
    for (int x=1; x < a; x++)
    {
        cin >> y;
        t[x] = t[x-1] + y;
    }
    cin >> b;
    for (int x=0; x < b; x++)
    {
        cin >> c >> d;
        if (c==0)
            cout << t[d] << "\n";
        else
            cout << t[d]-t[c-1] << "\n";
    }
}
