#include <bits/stdc++.h>

using namespace std;

int toDecimal(char c)
{
    if (c >= '0' && c <= '9')
        return c - '0';
    else
        return 10 + c - 'A'; 
}

int main() 
{
    int n;
    string a, b;
    scanf("%i", &n);
    while (n--)
    {
        cin>>a;
        b = a;
        b[2] -= toDecimal(b[2])&1;
        if (a == b)
            cout<<a<<"\n";
        else
            cout<<b<<" "<<a<<"\n";
    }
    return 0;
}
