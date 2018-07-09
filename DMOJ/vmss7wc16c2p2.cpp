#include<bits/stdc++.h>
using namespace std;

int main()
{
    int a[100001];
    int n, c, d;
    string b;
    cin>>b;
    for (int x = 0; x < b.length(); x++)
    {
        if (b[x] == 'G')
            a[x] = a[x-1] + 1;
        else
            a[x] = a[x-1];
    }
    scanf("%i", &n);
    for (int x = 0; x < n; x++)
    {
        scanf("%i%i", &c, &d);
        printf("%i\n", a[d] - a[c-1]);
    }
}
