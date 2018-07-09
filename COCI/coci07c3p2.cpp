#include <bits/stdc++.h>

using namespace std;

int main() 
{
    string a, b;
    cin>>a;
    reverse(a.begin(), a.end());
    while (a.length()%3) a+='0';
    reverse(a.begin(), a.end());
    while (!a.empty())
    {
        string c = a.substr(0,3);
        a.erase(0,3);
        if (c == "000") b+='0';
        else if (c == "001") b+='1';
        else if (c == "010") b+='2';
        else if (c == "011") b+='3';
        else if (c == "100") b+='4';
        else if (c == "101") b+='5';
        else if (c == "110") b+='6';
        else if (c == "111") b+='7';
    }
    cout<<b;
    return 0;
}
