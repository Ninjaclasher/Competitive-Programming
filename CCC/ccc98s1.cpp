#include <bits/stdc++.h>

using namespace std;

int main() 
{
    int n;
    string a, b;
    scanf("%i", &n);
    while (n--)
    {
        do getline(cin, a); while (a == "");
        for (auto &x : a)
        {
            if (x == ' ')
            {
                if (b.length() == 4) printf("**** ");
                else cout<<b<<" ";
                b.clear();
            }
            else b += x;
        }
        if (b.length() == 4) printf("****\n");
        else cout<<b<<"\n";
        b.clear();
        a.clear();
    }
    return 0;
}
