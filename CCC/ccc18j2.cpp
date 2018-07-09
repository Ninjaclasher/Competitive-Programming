#include <bits/stdc++.h>

using namespace std;

int main() 
{
    int n, s = 0;
    scanf("%i", &n);
    string a, b;
    cin>>a>>b;
    for (int x = 0; x < n; x++)
        if (a[x] == 'C' && b[x] == 'C')
            s++;
    printf("%i", s);
    return 0;
}
