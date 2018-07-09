#include <bits/stdc++.h>

using namespace std;

bool isVowel (char c)
{
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

char mi(char c)
{
    int dis = INT_MAX;
    char cc;
    for (char x = 'a'; x <= 'z'; x++)
        if (isVowel(x) && dis > abs(x-c))
            dis = abs(x-c), cc = x;
    return cc;
}

int main() 
{
    string a, b = "";
    cin>>a;
    for (auto &x : a)
    {
        b+=x;
        if (!isVowel(x))
        {
            b+= mi(x);
            for (char y = x+1; y <= 'z'; y++)
                if (!isVowel(y)) {b+=y; break;}
            if (x == 'z') b+='z';
        }
    }
    cout<<b;
    return 0;
}
