#include <bits/stdc++.h>

using namespace std;

bool vowel(char c)
{
    switch (c)
    {
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u':
        case 'y':
            return true;
    }
    return false;
}

int main()
{
    string n;
    for (cin>>n; n != "quit!"; cin>>n)
    {
        int sz = n.size();
        if (sz > 4)
        {
            if (!vowel(n[sz-3]) && n[sz-2] == 'o' && n[sz-1] == 'r')
                cout<<n.substr(0, sz-2) + "our";
            else
                cout<<n;
        }
        else
            cout<<n;
        cout<<"\n";
    }
}
