#include <bits/stdc++.h>

using namespace std;

int main() 
{
    vector<int> rd(200);
    rd['I']=1;
    rd['V']=5;
    rd['X']=10;
    rd['L']=50;
    rd['C']=100;
    rd['D']=500;
    rd['M']=1000;
    string a;
    cin>>a;
    int total = rd[a[a.size()-1]]*(a[a.size()-2]-'0');
    for (int x = a.size()-3; x >= 0; --x,x--)
        total += (rd[a[x]] < rd[a[x+2]] ? -1 : 1)*rd[a[x]]*(a[x-1]-'0');
    printf("%i", total);
    return 0;
}
