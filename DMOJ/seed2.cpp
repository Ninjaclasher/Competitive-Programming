#include <bits/stdc++.h>

using namespace std;

int main() 
{
    long long a = 1073741824, b = a>>1;
    string c;
    do
    {
        cout<<a<<endl;
        cin>>c;
        a += (c == "SINKS" ? 1 : -1) * b;
        a = min(a, 2000000000LL);
        b>>=1;
    }
    while (c != "OK");
    return 0;
}
