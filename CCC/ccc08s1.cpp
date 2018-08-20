#include <bits/stdc++.h>

using namespace std;

int main()
{
    string a, mia;
    int b, mi = INT_MAX;
    for (cin>>a>>b; a != "Waterloo"; cin>>a>>b)
        if (b < mi)
            mi = b, mia = a;
    if (b < mi)
        mi = b, mia = a;
    cout<<mia<<"\n";
}

