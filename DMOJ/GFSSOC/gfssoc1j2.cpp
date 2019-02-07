#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    scanf("%i", &n);
    int xx = 0, yy = 0;
    while (n--)
    {
        string a;
        int b;
        cin>>a>>b;
        if (a[0] == 'N')
            yy += b;
        else if (a[0] == 'S')
            yy -= b;
        else if (a[0] =='W')
            xx -= b;
        else
            xx += b;
    }
    printf("%i %i\n", xx, yy);
}
