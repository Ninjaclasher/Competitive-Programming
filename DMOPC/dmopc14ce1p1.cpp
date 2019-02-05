#include <bits/stdc++.h>

using namespace std;

int main()
{
    string a, b;
    cin>>a>>b;
    cout<<a<<"-tu ";
    if (b.back() == 's')
        cout<<"les";
    else if (b.back() == 'e')
        cout<<"la";
    else
        cout<<"le";
    cout<<" "<<b<<" ?";
}
