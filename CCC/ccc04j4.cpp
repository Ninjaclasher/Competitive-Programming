#include <bits/stdc++.h>

using namespace std;

int main()
{
    string a, b;
    cin>>a;
    do getline(cin, b); while (b.empty());
    string c;
    for (auto &x : b)
        if ('A' <= x && x <= 'Z')
            c += x;
    for (int x = 0; x < c.size(); x++)
        printf("%c", 'A' + (c[x] - 'A' + a[x%a.size()] - 'A')%26);
    printf("\n");
}
