#include <bits/stdc++.h>

using namespace std;

int main() 
{
    map<string,char> aa;
    int k;
    string a, b;
    char c;
    scanf("%i", &k);
    while (k--)
    {
        scanf(" %c", &c);
        cin>>a;
        aa[a] = c;
    }
    cin>>a;
    for (auto &x : a)
    {
        b += x;
        if (aa[b])
        {
            printf("%c", aa[b]);
            b.clear();
        }
    }
    return 0;
}
