#include <bits/stdc++.h>

using namespace std;
 
void sub(char c, string &str2)
{
    int len = str2.length()-1;
    str2[len]-=c-'0';
    if (str2[len] < '0')
    {
        str2[len]+=10;
        for (int x = len-1; x>=0; x--)
        {
            str2[x]-=1;
            if (str2[x] < '0') str2[x]+=10;
            else break;
        }
    }
    if (str2[0] == '0')
    {
        reverse(str2.begin(), str2.end());
        str2.pop_back();
        reverse(str2.begin(), str2.end());
    }        
}
 
int main()
{
    int n;
    scanf("%i", &n);
    string a, b;
    while (n--)
    {
        cin>>a;
        b = a;
        while (a.length() > 2)
        {
            cout<<a<<"\n";
            char last = a.back();
            a.pop_back();
            sub(last, a);
        }
        cout<<a<<"\n";
        cout<<"The number "<<b<<" is"<<(a[0]==a[1] ? " " : " not ")<<"divisible by 11.\n";
        if (n)
            cout<<"\n";
    }
    return 0;
}
