#include <bits/stdc++.h>
#include <string>

using namespace std;

int main()
{
    int a;
    string c;
    scanf("%i", &a);
    for (int b = 0; b < a; b++)
    {
        cin>> c;
        if (c.length() == 10 && ((c[0] == '4' && c[1] == '1' && c[2] == '6') || (c[0] == '6' && c[1] == '4' && c[2] == '7')))
            cout <<"("<<c[0]<<c[1]<<c[2]<<")-"<<c[3]<<c[4]<<c[5]<<"-"<<c[6]<<c[7]<<c[8]<<c[9];
        else
            cout <<"not a phone number";
        cout <<"\n";
    }
    return 0;
}
