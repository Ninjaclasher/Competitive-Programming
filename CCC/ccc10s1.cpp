#include <bits/stdc++.h>

using namespace std;

int main() 
{
    int n, a, b, c, ma = -1, maa = -1;
    string d, aa, aaa;
    scanf("%i", &n);
    while (n--)
    {
        cin>>d;
        scanf("%i%i%i", &a, &b, &c);
        int ss = 2*a+3*b+c;
        if (ss > ma)
        {
            maa = ma, aaa = aa;
            ma = ss, aa = d;
        }
        else if (ss == ma && d < aa)
        {
            maa = ma, aaa = aa;
            ma = ss, aa = d;
        }
        else if (ss > maa)
            maa = ss, aaa = d;
        else if (ss == maa && d < aaa)
            maa = ss, aaa = d;
    }
    cout<<aa;
    if (maa != -1) cout<<"\n"<<aaa;
    return 0;
}
