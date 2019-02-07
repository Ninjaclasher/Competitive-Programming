#include <bits/stdc++.h>

using namespace std;

int main()
{
    string a;
    cin>>a;
    sort(a.begin(), a.end());
    do
        cout<<a<<"\n";
    while (next_permutation(a.begin(), a.end()));
}
