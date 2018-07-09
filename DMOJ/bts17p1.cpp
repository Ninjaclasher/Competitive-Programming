#include <bits/stdc++.h>

using namespace std;

int main() 
{
    string a;
    getline(cin, a);
    for (int x = 0; x < a.length(); x++)
    {
        if (a[x] == ' ' && a[x+1] >= 'A' && a[x+1] <= 'Z')
            printf(".");
        printf("%c", a[x]);
    }
    printf(".");
    return 0;
}
