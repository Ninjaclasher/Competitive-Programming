#include <bits/stdc++.h>

using namespace std;

int main()
{
    string n;
    for (cin>>n; n != "X"; cin>>n)
    {
        bool ch = true;
        while (ch)
        {
            ch = false;
            int o = n.find("ANA");
            if (o != -1)
                n.replace(o, 3, "A"), ch = true;
            o = n.find("BAS");
            if (o != -1)
                n.replace(o, 3, "A"), ch = true;
        }
        if (n != "A")
            printf("NO\n");
        else
            printf("YES\n");
    }
}
