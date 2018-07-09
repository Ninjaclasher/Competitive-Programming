#include <bits/stdc++.h>

using namespace std;

int main()
{
    string a, b, c, zero;
    int z, carry, n;
    bool negativeB, negativeC, temp;
    cin>>n;
    while (n--)
    {
        cin>>b>>c;
        negativeB = false, negativeC = false;
        if (b[0] == '-')
            b = b.substr(1, b.length()), negativeB = true;
        if (c[0] == '-')
            c = c.substr(1, c.length()), negativeC = true;
        zero = "";
        for (int x = 0; x < abs((int)c.length()-(int)b.length()); x++)
            zero += '0';
        if (b.length() < c.length())
            b = zero + b;
        if (c.length() < b.length())
            c = zero + c;
        a = "", carry = 0;
        if (!(negativeB^negativeC))
        {
            for (z = b.length() - 1; z >= 0; z--)
            {
                int tmp = b[z] - '0' + c[z] - '0' + carry;
                carry = 0;
                if (tmp > 9)
                {
                    carry = 1;
                    tmp -= 10;
                }
                a = (char)(tmp + '0') + a;
            }
            if (carry)
                a = "1" + a;
        }
        else
        {
            if (b == c)
            {
                cout<<0<<"\n";
                continue;
            }
            for (z = 0; b[z] == c[z]; z++);
            if (b[z] < c[z])
            {
                swap(b,c);
                swap(negativeB, negativeC);
            }
            for (z = b.length()-1; z >= 0; z--)
            {
                int tmp = b[z] - c[z] - carry;
                carry = 0;
                if (tmp < 0)
                    carry = 1, tmp += 10;
                a = (char)(tmp + '0') + a;
            }
        }
        for (z = 0; a[z] == '0'; z++);
        a = a.substr(z, a.length());
        if (negativeB)
            cout<<"-";
        cout<<a<<"\n";
    }
}

