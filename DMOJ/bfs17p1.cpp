#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, c = 0;
    scanf("%i", &n);
    string w;
    while (n--)
    {
        cin>>w;
        if (w.size() <= 10) c++;
    }
    printf("%i", c);
    return 0;
}
